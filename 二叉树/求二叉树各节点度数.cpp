#include "stdio.h"
#include "malloc.h"
#include <iostream>
#include <queue>
#include <vector>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
using namespace std;
typedef char ElemType;
typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lchild, *rchild; // 左右孩子指针
} BiTNode, *BiTree;

Status CreateBiTree(BiTree &T)
{ // 算法6.4
    // 按先序次序输入二叉树中结点的值（一个字符），’#’字符表示空树，
    // 构造二叉链表表示的二叉树T。
    char ch;
    scanf("%c", &ch);
    if (ch == '#')
        T = NULL;
    else
    {
        if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
            return ERROR;
        T->data = ch;            // 生成根结点
        CreateBiTree(T->lchild); // 构造左子树
        CreateBiTree(T->rchild); // 构造右子树
    }
    return OK;
} // CreateBiTree

int main() // 主函数
{
    // 补充代码
    BiTree T;
    CreateBiTree(T);
    int s2 = 0, s1 = 0, s0 = 0;

    queue<BiTree> q1;
    q1.push(T);
    while (!q1.empty())
    {
        BiTree x = q1.front();
        q1.pop();
        int sum = 0;
        if (x->lchild)
        {
            q1.push(x->lchild);
            sum++;
        }
        if (x->rchild)
        {
            q1.push(x->rchild);
            sum++;
        }
        switch (sum)
        {
        case 2:
            s2++;
            break;
        case 1:
            s1++;
            break;
        default:
            s0++;
            break;
        }
    }

    cout << s2 << endl;
    cout << s1 << endl;
    cout << s0 << endl;
} // main
