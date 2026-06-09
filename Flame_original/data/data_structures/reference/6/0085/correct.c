#include <stdio.h>

int main()
{
    int stack[100] = {0};
    int top = -1;
    int dd = 0, num = 0;
    while (scanf("%d", &dd))
    {
        if (dd == 1)
        {
            if (top == 100)
                printf("error ");
            else
            {
                scanf("%d", &num);
                top++;
                stack[top] = num;
            }
        }
        else if (dd == 0)
        {
            if (top == -1)
                printf("error ");
            else
            {
                printf("%d ", stack[top]);
                stack[top] = 0;
                top--;
            }
        }
        else if (dd == -1)
            break;
    }

    return 0;
}
