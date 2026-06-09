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
    Top = NULL; // @@ [Error: Top is a pointer (Nodeptr), assigning -1 is invalid and causes undefined behavior. It should be initialized to NULL to represent an empty stack.]
}
int  isEmpty()
{
    return Top == NULL; // @@ [Error: Since Top is a pointer, checking against -1 is incorrect. It should check against NULL.]
}
void  push(int item)
{
    Nodeptr p;
    if ((p = (Nodeptr)malloc(sizeof(Node))) == NULL||flag==100) // @@ [Error: The condition uses && which means it only errors if malloc fails AND flag is 100. It should use || to error if either malloc fails OR the stack is full (flag==100). Also, malloc failure is rare, the main logic error is not checking capacity correctly with OR.]
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
    // @@ [Error: The problem description does not require popping remaining elements after -1. The reference program stops at -1. This loop might cause issues if not handled correctly, but the primary TLE cause is likely the infinite loop below if isEmpty is broken or just unnecessary processing. However, the specific TLE in the prompt context usually points to logical errors causing infinite loops or excessive output. The previous errors in initStack and isEmpty are critical. ]
    while (!isEmpty())
    {
        pop(); // @@ [Error: 'pop' is a function call, it must be written as 'pop()' with parentheses. Without parentheses, this statement does nothing, causing an infinite loop because isEmpty() will remain true if the stack was not empty, leading to Time Limit Exceeded.]
    }
}