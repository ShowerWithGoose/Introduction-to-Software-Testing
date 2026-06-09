#include <stdio.h>
int stack[100];
int num = -1, option, flag, xx, i;
int push(int x)
{
    if (num >= 99)
    {
        return -1;
    }
    stack[++num] = x;
    return 0;
}
int pop()
{
    if (num < 0)
    {
        return -1;
    }
    return stack[num--];
}
int main()
{
    for (scanf("%d", &option); option != -1; scanf("%d", &option))
    {
        if (option == 1)
        {
            scanf("%d", &xx);
            flag = push(xx);
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

