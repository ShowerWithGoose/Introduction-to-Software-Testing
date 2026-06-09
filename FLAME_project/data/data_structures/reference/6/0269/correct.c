#include <stdio.h>
int a[100], top = -1, op, er;
int main()
{
    while (1)
    {
        scanf("%d", &op);
        if (op == -1)
            break;
        else if (op == 1)
        {
            if (top == 99)
            {
                printf("error ");
                scanf("%d", &er);
            }
            else
                scanf("%d", &a[++top]);
        }
        else if (op == 0)
        {
            if (top == -1)
                printf("error ");
            else
                printf("%d ", a[top--]);
        }
    }
    return 0;
}
