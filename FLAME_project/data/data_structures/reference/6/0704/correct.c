#include <stdio.h>
#define M 100
int STACK[M];
int top = -1;
void in(int);
void out();
int main()
{
    int op, num;
    while (scanf("%d", &op))
    {
        if (op == 1)
        {
            scanf("%d", &num);
            in(num);
        }
        else if (op == 0)
        {
            out();
        }
        else
            break;
    }
    return 0;
}
void in(int n)
{
    if (top >= M)
    {
        printf("error ");
    }
    else
    {
        STACK[++top] = n;
    }
}
void out()
{
    if (top>-1)
    {
        printf("%d ", STACK[top--]);
    }
    else
        printf("error ");
}
