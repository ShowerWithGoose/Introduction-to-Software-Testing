#include <stdio.h>

int stack[101];

int main()
{
    int top = 0, operation;
    int flag = 0;

    scanf("%d", &operation);
    while (operation != -1)
    {
        if (flag)
        {
            stack[++top] = operation;
            flag = 0;
        }

        if (operation == 1)
        {
            if (top == 100)
                printf("error ");
            else
                flag = 1;
        }

        if (operation == 0)
        {
            if (top != 0)
                printf("%d ", stack[top--]);
            else
                printf("error ");
        }

        scanf("%d", &operation);
    }

    return 0;
}
