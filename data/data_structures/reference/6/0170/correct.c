#include <stdio.h>

int stack[100];
int topnum;
int main()
{
    int inst;
    topnum = -1;
    while (1)
    {
        scanf("%d", &inst);
        if (inst == -1)
            break;
        else if (inst == 0)
        {
            if (topnum == -1)
                printf("error ");
            else
                printf("%d ", stack[topnum--]);
        }
        else if (inst == 1)
        {
            if (topnum == 99)
                printf("error ");
            else
                scanf("%d", &stack[++topnum]);
        }
    }
    return 0;
}
