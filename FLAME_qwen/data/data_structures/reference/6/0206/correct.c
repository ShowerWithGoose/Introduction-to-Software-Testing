#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];

int top = -1;

void push(int n)
{
    if (top == MAX_SIZE - 1)
    {
        printf("error ");
        return;
    }
    else
    {
        stack[++top] = n;
        return;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("error ");
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0)
        {
            int p = pop();
            if (p != -1)
                printf("%d ", p);
        }
        else if (n == 1)
        {
            int m;
            scanf("%d", &m);
            push(m);
        }
    }
}
