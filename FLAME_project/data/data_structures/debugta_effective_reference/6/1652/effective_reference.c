#include <stdio.h>
int stack[100];
int top = -1, option, flag, newnum, i;
int push(int x)
{
    if (top >= 99)
    {
        return -1;
    }
    stack[++top] = x;
    return 0;
}
int pop()
{
    if (top < 0)
    {
        return -1;
    }
    return stack[top--];
}
int main()
{
    for (scanf("%d", &option); option != -1; scanf("%d", &option))
    {
        if (option == 1)
        {
            scanf("%d", &newnum);
            flag = push(newnum);
            if (flag == -1)
            {
                printf("error ");
            }
        }
        if (option == 0)
        {
            flag = pop();
            if (flag == -1)
            {
                printf("error ");
            }
            else
            {
                printf("%d ", flag);
            }
        }
    }
    return 0;
}

