#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define M 100
int stack[M];
int empty(int top);
int full(int top);
int push(int a[], int *top, int n);
int pop(int a[], int *top);
int main()
{
    int top=-1;
    int order, num;
    scanf("%d ", &order);
    while (order != -1)
    {
        if (order == 1)
        {
            scanf("%d ", &num);
            if (full(top))
            {
                printf("error ");
            }
            else
                push(stack, &top, num);
        }
        else if (order == 0)
        {
            if (empty(top))
                printf("error ");
            else 
            {
                printf("%d ", stack[top]);
                pop(stack, &top);
            }
        }
        scanf("%d ", &order);
    }
    return 0;
}
int empty(int top)
{
    return top == -1;
}
int full(int top)
{
    return top == M - 1;
}
int push(int a[], int *top, int n)
{
    if (full(*top)==1)
        return 0;
    else
    {
        (*top)++;
        a[*top] = n;
        return 1;
    }
}
int pop(int a[], int *top)
{
    if (empty(*top)==1)
        return 0;
    else
    {
        (*top)--;
        return 1;
    }
}
