#include <stdio.h>
#include <string.h>

int stack[1000], top = -1;

const int Max = 100;

void push(int val)
{
    if(top == Max)
        printf("error ");
    else
        stack[++top] = val;
    return ;
}

void pop()
{
    if(top == -1)
        printf("error ");
    else
        printf("%d ", stack[top--]);
    return ;
}

int main()
{
    int op, tmp;
    while(scanf("%d", &op) && op != -1)
    {
        if(op == 1)
        {
            scanf("%d", &tmp);
            push(tmp);
        }
        else
            pop();
    }
    return 0;
}
