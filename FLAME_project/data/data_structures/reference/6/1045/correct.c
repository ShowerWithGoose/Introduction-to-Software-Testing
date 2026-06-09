#include <stdio.h>
int top = 0;
int num[200];
int op;
int a;
int main()
{
    while (scanf("%d", &op))
    {
        if (op == -1)
            return 0;
        if (op == 1)
        {
            scanf("%d", &a);
            if (top == 100)
            {
                printf("error ");
                continue;
            }
            num[++top] = a;
        }
        else if (op == 0)
        {
            if (top == 0)
            {
                printf("error ");
                continue;
            }
            printf("%d ", num[top--]);
        }
    }
    return 0;
}
