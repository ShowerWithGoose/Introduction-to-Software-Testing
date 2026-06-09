#include <stdio.h>
int isfull(int a[], int top)
{
    if (top<99)
    {
        return 0;
    }
    else
        return 1;
}

int isempty(int a[], int top)
{
    if (top>=0)
    {
        return 0;
    }
    else
        return 1;
}


int main()
{
    int stack[100];
    int top = -1;
    int flag, num;

    while (scanf("%d", &flag)!=EOF)
    {
        if (flag==1)
        {
            if (isfull(stack, top)==0)
            {
                scanf("%d", &num);
                stack[++top]=num;
            }
            else
                printf("error ");

        }
        if (flag==0)
        {
            if (isempty(stack, top)==0)
                printf("%d ", stack[top--]);
            else
                printf("error ");
        }
        if (flag==-1)
            return 0;
    }

    return 0;
}

