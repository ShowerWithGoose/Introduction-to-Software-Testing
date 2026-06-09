#include <stdio.h>
#include <string.h>
int main()
{
    int stack[105] = {0}, state, num, top = -1;
    scanf("%d", &state);
    while (state != -1)
    {
        if (state == 1)
        {
            scanf("%d", &num);
            stack[++top] = num;
        }
        else if (state == 0)
        {
            if (top == -1)
            {
                printf("error ");
            }
            else
            {
                printf("%d ", stack[top--]);
            }
        }
        scanf("%d", &state);
    }
    return 0;
}
