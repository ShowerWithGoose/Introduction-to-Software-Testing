#include <stdio.h>

int stk[505], top = 0;

int main()
{
    while (1)
    {
        int op, val;
        scanf("%d", &op);
        if (op == -1) break;
        if (op == 1)
        {
            scanf("%d", &val);
            if (top == 100)
            {
                printf("error ");
                continue;
            }
            stk[ ++ top] = val;
        }
        if (op == 0)
        {
            if (top == 0)
            {
                printf("error ");
                continue;
            }
            printf("%d ", stk[top]);
            top --;
        }
    }
    return 0;
}


