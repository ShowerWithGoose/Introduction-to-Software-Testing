#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <malloc.h>
#define MAXLEN 100
int stack[MAXLEN];
int top = -1;
void pop()
{
    if (top == -1)
    {
        printf("error ");
        return;
    }
    else
    {
        printf("%d ", stack[top]);
        top--;
    }
}
void push(int a)
{
    if (top == MAXLEN)
    {
        printf("error ");
        return;
    }
    else
    {
        top++;
        stack[top] = a;
    }
}
int main()
{
    int ope, num;
    while (1)
    {
        scanf("%d", &ope);
        if (ope == 0)
        {
            pop();
        }
        else if (ope == 1)
        {
            scanf("%d", &num);
            push(num);
        }
        else if (ope == -1)
        {
            break;
        }
    }
    return 0;
}
