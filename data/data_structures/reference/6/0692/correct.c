#include <stdio.h>
int main()
{
    int stack[100] = {0}, i = 0, op;
    while (1)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            if (i < 100)
            {
                scanf("%d", &stack[i]);
                i++;
            }
            else
                printf("error ");
        }
        else if (op == 0)
        {
            if (i > 0)
            {
                i--;
                printf("%d ", stack[i]);
            }
            else
                printf("error ");
        }
        else if (op == -1)
            return 0;
    }
}
