#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100
int STACK[MAXSIZE], top;

void initStack() //
{
    top = -1;
}

int isEmpty() //
{
    return top == -1;
}

int isFull() //
{
    return top == MAXSIZE - 1;
}

int push(int e) //
{
    if (isFull())
    {
        printf("error ");
        return -1;
    }
    else
        STACK[++top] = e;
    return top;
}

int pop() //
{
    if (isEmpty())
    {
        printf("error ");
        return -1;
    }
    else
        return STACK[top--];
}

int getTop() //
{
    if (isEmpty())
    {
        printf("error ");
        return -1;
    }
    return STACK[top];
}

int main()
{
    // freopen("data.in", "r", stdin);
    int op, x;
    initStack();
    while (1)
    {
        scanf("%d", &op);
        if (op == -1)
            break;
        else if (op == 1)
        {
            scanf("%d", &x);
            push(x);
        }
        else if (op == 0)
        {
            x = pop();
            if (x != -1)
            {
                printf("%d ", x);
            }
        }
    }
    return 0;
}

