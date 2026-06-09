#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXSIZE 100
int s[MAXSIZE];
int top = -1;
int isempty();
int isfull();
int push(int item);
int pop();
int main()
{
    int a, b, i;
    do
    {
        scanf("%d", &a);
        if (a == 1)
        {
            scanf("%d", &b);
            if (isfull())
            {
                printf("error ");
            }
            else
            {
                push(b);
            }
        }
        if (a == 0)
        {
            if (isempty())
            {
                printf("error ");
            }
            else
            {
                printf("%d ", pop());
            }
        }
    } while (a != -1);
    return 0;
}
int isempty()
{
    return top == -1;
}
int isfull()
{
    return top == MAXSIZE;
}
int push(int item)
{
    s[++top] = item;
}
int pop()
{
    int c;
    c = s[top--];
    return c;
}
