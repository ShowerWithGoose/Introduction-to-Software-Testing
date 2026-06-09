#include <stdio.h>
int main()
{
    int stack[101];
    int c;
    int num;
    int top;
    top = 0;
    while (~scanf("%d", &c))
    {
        switch (c)
        {
        case 1:
            scanf("%d ", &num);
            if (top > 99)
                printf("error ");
            stack[top++] = num;
            break;
        case 0:
            if (top == 0)
                printf("error ");
            printf("%d ", stack[top-- - 1]);
        case -1:
            break;
        default:
            break;
        }
    }
    return 0;
}
