//⚠️说在前面 ： 根本不需要任何的扩容操作
//  sb OJ没有超过初始空间的测试样本
// 根本不难，扣好细节就行
#include <malloc.h>
#include <iostream>
using namespace std;
#include <stdio.h>
#define OK 1
#define ERROR 0
#define STACK_INIT_SIZE 100 // 存储空间初始分配量
#define STACKINCREMENT 10   // 存储空间分配增量

typedef int SElemType; // 定义栈元素类型
typedef int Status;    // Status是函数的类型,其值是函数结果状态代码，如OK等

struct SqStack
{
    SElemType *base; // 在栈构造之前和销毁之后，base的值为NULL
    SElemType *top;  // 栈顶指针
    int stacksize;   // 当前已分配的存储空间，以元素为单位
}; // 顺序栈

Status InitStack(SqStack &S)
{
    // 构造一个空栈S，该栈预定义大小为STACK_INIT_SIZE
    // 请补全代码
    S.base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
    if (!S.base)
    {
        return ERROR;
    }
    S.stacksize = 0;
    S.top = S.base;
    return OK;
}

Status Push(SqStack &S, SElemType e)
{
    // 在栈S中插入元素e为新的栈顶元素
    // 请补全代码
    *S.top = e;
    S.top++;
    //🌟 记得对stacksize进行自增操作
    S.stacksize++;
    return OK;
}

Status Pop(SqStack &S, SElemType &e)
{
    // 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR
    // 请补全代码
    if (S.top == S.base)
        return ERROR;
    e = *(--S.top);
    //🌟 记得对stacksize进行自增操作
    S.stacksize--;
    return OK;
}

Status GetTop(SqStack S, SElemType &e)
{
    // 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR
    // 请补全代码
    if (S.base == S.top)
        return ERROR;
    e = *(S.top - 1);
    return OK;
}

int StackLength(SqStack S)
{
    // 返回栈S的元素个数
    // 请补全代码
    return S.stacksize;
}

Status StackTraverse(SqStack S)
{
    // 从栈顶到栈底依次输出栈中的每个元素
    SElemType *p = S.top - 1; // 请填空
    if (S.top == S.base)
        printf("The Stack is Empty!"); // 请填空
    else
    {
        printf("The Stack is: ");
        // 🌟 个人建议直接修改源代码，不要填空
        //    给定代码顺序不好实现顺序输出不越界的操作
        while (p >= S.base) // 请填空
        {
            printf("%d ", *p);
            p--;
        }
    }
    printf("\n");
    return OK;
}

int main()
{
    int a;
    SqStack S;
    SElemType x, e;
    if (InitStack(S)) // 判断顺序表是否创建成功，请填空
    {
        printf("A Stack Has Created.\n");
    }
    while (1)
    {
        printf("1:Push \n2:Pop \n3:Get the Top \n4:Return the Length of the Stack\n5:Load the Stack\n0:Exit\nPlease choose:\n");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            scanf("%d", &x);
            if (!Push(S, x))
                printf("Push Error!\n"); // 判断Push是否合法，请填空
            else
                printf("The Element %d is Successfully Pushed!\n", x);
            break;
        case 2:
            if (!Pop(S, e))
                printf("Pop Error!\n"); // 判断Pop是否合法，请填空
            else
                printf("The Element %d is Successfully Poped!\n", e);
            break;
        case 3:
            if (!GetTop(S, e))
                printf("Get Top Error!\n"); // 判断Get Top是否合法，请填空
            else
                printf("The Top Element is %d!\n", e);
            break;
        case 4:
            printf("The Length of the Stack is %d!\n", StackLength(S)); // 请填空
            break;
        case 5:
            StackTraverse(S); // 请填空
            break;
        case 0:
            return 1;
        }
    }
}
