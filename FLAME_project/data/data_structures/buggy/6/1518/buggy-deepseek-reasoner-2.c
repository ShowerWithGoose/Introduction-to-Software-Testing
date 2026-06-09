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
    Top = -1; // @@ [Error: Top should be initialized to NULL, not -1. Using -1 as a pointer is invalid and will cause problems when comparing with NULL.]
}
int  isEmpty()
{
    return Top == -1; // @@ [Error: Should compare with NULL, not -1. This only works coincidentally because Top is set to -1 initially, but after pushing, Top becomes a valid pointer, so isEmpty returns false incorrectly for non-empty stack? Actually after push, Top is a pointer, so this comparison returns false (since pointer not equal to -1), so it works for non-empty. However, after popping all nodes, Top becomes the link of the last node, which was set to -1, so it returns true. So it's consistent but conceptually wrong and may cause issues if memory addresses equal -1. Better to use NULL.]
}
void  push(int item)
{
    Nodeptr p;
    if ((p = (Nodeptr)malloc(sizeof(Node))) == NULL&&flag==100) // @@ [Error: The condition for full stack is incorrect. Should check if flag >= 100 before attempting to push. The current condition only prints error if malloc fails AND flag==100, which never happens. Also missing a check for stack capacity; the stack can hold at most 100 elements, but this code does not enforce that.]
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
        pop; // @@ [Error: Missing parentheses. This is not a function call; it's just a statement that evaluates the function pointer and does nothing. This causes an infinite loop because isEmpty never changes, leading to Time Limit Exceeded.]
    }
}