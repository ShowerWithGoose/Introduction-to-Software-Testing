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
    Top = -1; // @@ [Top is a pointer, should be initialized to NULL, not -1 (integer). This causes undefined behavior in isEmpty() and other functions.]
}
int  isEmpty()
{
    return Top == -1; // @@ [Top is a pointer; comparing it to -1 is incorrect. Should compare to NULL. Because of initStack() setting Top=-1, this may accidentally work numerically but is logically wrong and unsafe.]
}
void  push(int item)
{
    Nodeptr p;
    if ((p = (Nodeptr)malloc(sizeof(Node))) == NULL&&flag==100) // @@ [Condition is flawed: it only prints "error " if BOTH malloc fails AND flag==100. It should check stack full (flag>=100) separately from malloc failure. Also, malloc rarely fails before hitting capacity, so stack overflow (push when full) is not properly detected.]
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
        pop; // @@ [pop is a function; this line does nothing (missing parentheses). It should be pop(); but even then, the problem says to stop at -1 and not pop remaining elements. This extra loop causes infinite loop or undefined behavior because isEmpty() is broken and pop without () doesn't execute. This likely causes Time Limit Exceeded.]
    }
}