#include <stdio.h>
int stack[105], h = 0;
int main()
{
    int op, num;
    while (1)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            h++;
            if (h > 100)
            {
                printf("error ");
                continue;
            }
            scanf("%d", &num);
            stack[h] = num;
        }
        else if (op == 0)
        {
            if (h <= 0)
            {
                printf("error ");
                continue;
            }
            printf("%d ", stack[h]);
            h--;
        }
        else if (op == -1)
        {
            break;
        }
    }
    return 0;
}
