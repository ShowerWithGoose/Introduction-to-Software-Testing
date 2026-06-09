#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100
int STACK[MAXSIZE - 1];
int top = -1;

int isEmply()
{
    return top == -1;
}

int isFull()
{
    return top == MAXSIZE - 1;
}

signed main()
{
    int op, num;
    while (scanf("%d", &op) != EOF)
    {
        if (op == 1)
        {
            if (isFull())
                printf("error ");
            else
            {
                scanf("%d", &num);
                STACK[++top] = num;
            }
        }
        if (op == 0)
        {
            if (isEmply())
                printf("error ");
            else
            {
                printf("%d ", STACK[top--]);
            }
        }
        if (op == -1)
            break;
    }
    return 0;
}


