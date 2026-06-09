#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int flag = 0;
struct  node {
    int data;
    struct  node* link;
};
typedef  struct node* Nodeptr;
typedef  struct node  Node;
Nodeptr Top;
void  initStack()
{
    Top = -1; // @@ 类型错误：Top是指针类型，不能直接赋值为整数-1，应初始化为NULL
}
int  isEmpty()
{
    return Top == -1; // @@ 类型错误：指针与整数-1比较，逻辑错误，应改为Top == NULL
}
void  push(int item)
{
    Nodeptr p;
    if ((p = (Nodeptr)malloc(sizeof(Node))) == NULL&&flag==100) // @@ 逻辑错误：条件应为||而非&&，且应同时处理栈满和内存分配失败的情况
        printf("error ");
    else {
        p->data = item;           /*将item送新结点数据域*/
        p->link = Top;              /*将新结点插在链表最前面*/
        Top = p;/*修改栈顶指针的指向*/
        flag++;
    }
}
void pop()
{
    Nodeptr p;
    int item;
    if (isEmpty())
        printf("error ");
    else {
        p = Top;                          /* 暂时保存栈顶结点的地址*/
        item = Top->data;         /*保存被删栈顶的数据信息*/
        Top = Top->link;            /* 删除栈顶结点 */
        free(p);                         /* 释放被删除结点*/
        printf("%d ", item);                       /* 返回出栈元素*/
        flag--;
    }
}
int main()
{
    initStack();
    int op,x;
    while (1)
    {
        scanf("%d", &op);
        if (op == -1)
            break;
        if (op == 0)
            pop();
        if (op == 1)
        {
            scanf("%d", &x);
            push(x);
        }
    }
    while (!isEmpty())
    {
        pop; // @@ 语法错误：缺少函数调用括号，应改为pop();
    }
}