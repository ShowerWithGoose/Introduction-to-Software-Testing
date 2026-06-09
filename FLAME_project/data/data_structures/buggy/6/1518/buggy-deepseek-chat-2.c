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
    Top = -1; // @@ Error: Top is a pointer, but it is being assigned an integer -1. This makes Top an invalid pointer, causing segmentation faults or undefined behavior when dereferenced. It should be Top = NULL.
}
int  isEmpty()
{
    return Top == -1; // @@ Error: Since Top is a pointer, comparing it to -1 is incorrect. It should be Top == NULL.
}
void  push(int item)
{
    Nodeptr p;
    if ((p = (Nodeptr)malloc(sizeof(Node))) == NULL&&flag==100) // @@ Error: The condition for stack full is incorrect. The stack capacity is 100, but the check uses flag==100, which only triggers when flag is exactly 100, not when it reaches 100. Also, the condition should be flag >= 100, and the error should be printed regardless of malloc failure. The logic is flawed.
        printf("error ");
    else {
        p->data = item;          
        p->link = Top;              // @@ Error: Top is -1 (invalid pointer), so p->link is set to an invalid address, corrupting the linked list.
        Top = p;
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
        p = Top;                          
        item = Top->data;         // @@ Error: If Top is -1, dereferencing it causes a segmentation fault.
        Top = Top->link;            // @@ Error: Same issue - Top is invalid.
        free(p);                         
        printf("%d ", item);                       
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
        pop; // @@ Error: Missing parentheses for function call. Should be pop().
    }
}