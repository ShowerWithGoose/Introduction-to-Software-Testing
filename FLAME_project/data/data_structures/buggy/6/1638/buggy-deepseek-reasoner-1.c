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
            stack[top++] = num; // @@ Push is executed even when stack is full, causing overflow. Should be in an else block.
            break;
        case 0:
            if (top == 0)
                printf("error ");
            printf("%d ", stack[top-- - 1]); // @@ Unconditional print of popped value, even when stack is empty (top==0 leads to out-of-bounds). Also missing break causes fall-through.
        case -1:
            break; // @@ Should be 'return 0;' to end program; otherwise loop continues reading further input.
        default:
            break;
        }
    }
    return 0;
}