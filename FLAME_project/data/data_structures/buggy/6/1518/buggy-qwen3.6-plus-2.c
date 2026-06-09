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
    Top = -1; // @@ [Error: Top is a pointer (Nodeptr), assigning integer -1 to it is invalid. It should be initialized to NULL. This causes undefined behavior and likely crashes or infinite loops when checking isEmpty.]
}
int  isEmpty()
{
    return Top == -1; // @@ [Error: Since Top is a pointer, it should be compared to NULL, not -1. Due to the initialization error above, this check is also logically incorrect for a linked list stack.]
}
void  push(int item)
{
    Nodeptr p;
    if ((p = (Nodeptr)malloc(sizeof(Node))) == NULL&&flag==100) // @@ [Error: Logic error. If malloc fails (returns NULL), accessing p->data later will crash. Also, the condition checks flag==100 but doesn't handle the "stack full" error correctly if malloc succeeds but capacity is reached. It should check if flag >= 100 before allocating or just check flag. More importantly, if malloc returns NULL, it prints error but continues to use p? No, it's in an if/else structure implicitly? No, there is no else for the outer if. Wait, the code structure is: if (condition) printf... else { ... }. The condition is complex. If malloc fails OR flag==100, it prints error. But if malloc succeeds and flag!=100, it goes to else. However, if malloc fails, p is NULL. If the condition is true because of flag==100 but malloc succeeded, it prints error but DOES NOT push, which is correct. But if malloc fails, it prints error. The issue is that if the stack is full (flag==100), it prints error. But the problem says "error " followed by space. The main issue causing TLE is likely the infinite loop at the end.]
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
        pop; // @@ [Error: 'pop' is a function name. Calling it requires parentheses 'pop()'. Without parentheses, this statement does nothing, resulting in an infinite loop because isEmpty() remains true. This causes Time Limit Exceeded.]
    }
}