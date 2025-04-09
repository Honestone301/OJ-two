/*
#include "stdio.h"
#include <malloc.h>
#include <iostream>
#include <queue>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
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
    //ABC###D##
    //2
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
    BiTree T;
    if (!CreateBiTree(T))
    {
        return 0;
    }
    int k;
    scanf("%d", &k);
    queue<BiTNode *> q1;
    q1.push(T);
    int counters = 0;
    int level=1;
    while (!q1.empty())
    {
        BiTNode *x;
        int len=q1.size();
        if(level==k){
            break;
        }
        while (len--)
        {
            x = q1.front();
            q1.pop();
            if (x->lchild)
            {
                q1.push(x->lchild);
            }
            if (x->rchild)
            {
                q1.push(x->rchild);
            }
        }
        level++;
    }
    
    while(!q1.empty()){
        BiTNode* y;
        y=q1.front();
        q1.pop();
        if(!(y->lchild)){if(!(y->rchild))counters++;}
    }
    std::cout<<counters;

    // 补充代码
} // main
*/
#include "stdio.h"
#include "malloc.h"
#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR  0
#define INFEASIBLE -1
#define OVERFLOW -2
#include<iostream>
using namespace std; 
typedef int  Status;
int k;
typedef char  ElemType;
typedef struct BiTNode{
  ElemType data;
  struct BiTNode *lchild,*rchild;//左右孩子指针
} BiTNode,*BiTree;

Status CreateBiTree(BiTree &T) {  // 算法6.4
  // 按先序次序输入二叉树中结点的值（一个字符），’#’字符表示空树，
  // 构造二叉链表表示的二叉树T。
  char ch;
  scanf("%c",&ch);
  if (ch=='#') T = NULL;
  else {
    if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) return ERROR;
    T->data=ch;// 生成根结点
    CreateBiTree(T->lchild); // 构造左子树
    CreateBiTree(T->rchild);  // 构造右子树
  }
  return OK;
} // CreateBiTree
int solve(BiTree T,int n)
{
	//cout<<n<<endl;
	if(T==NULL)
	return 0;
	else if(n==k)
	{
		if(T->lchild==NULL&&T->rchild==NULL)
		return 1;
		else 
		return 0;
	}
	
	return solve(T->lchild,n+1)+solve(T->rchild,n+1);
	
}

int main()   //主函数
{
    BiTree T;
	CreateBiTree(T);
	cin>>k;
	cout<<solve(T,1);
 }//main
