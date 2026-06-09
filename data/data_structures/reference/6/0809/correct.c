#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int top = -1;
int stack[100];
void push(int);
int pop();
int isFull();
int isEmpty();
int main()
{
    int op, num;
    scanf("%d",&op);
    while (op != -1)
    {
        if (op == 1)
        {
           scanf("%d", &num);
            push(num);
        }
        else if (op == 0)
        {
            pop();
        }
        scanf("%d",&op);
    }
    return 0;
}
int isEmpty()
{
    return top == -1;
}
int isFull()
{
    return top == 99;
}
void push(int num)
{
    if (isFull())
    {
        printf("error ");
        return;
    }
    else
    {
        stack[++top] = num;
    }
}
int pop()
{
    if (isEmpty())
    {
        printf("error ");
    }
    else
    {
        printf("%d ",stack[top--]);
    }
}

