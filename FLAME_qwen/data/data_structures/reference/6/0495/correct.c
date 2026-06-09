#include <stdio.h>

#define STACK_SIZE 100
#define STACK_ENDSER (STACK_SIZE - 1)

int main()
{
    int stack[105];
    int top = -1;
    int cmd, arg;
    int operating = 1;
    while (operating && ~scanf("%d", &cmd))
    {
        switch(cmd)
        {
            case 1: // push
                if (scanf("%d", &arg) <= 0)
                {
                    printf("\ninvalid argument(s)!\n");
                    return 0;
                }
                if (top >= STACK_ENDSER)
                {
                    printf("error "); // stack overflow
                    //return;
                    break;
                }
                stack[++top] = arg;
            break;
            case 0: // pop
                if (top <= -1)
                {
                    printf("error "); // stack empty
                    //return;
                    break;
                }
                printf("%d ", stack[top--]);
            break;
            case -1: // pop
                operating = 0;
            break;
            default: // unknown cmd
                printf("\nunknown command!\n");
                return 0;
            break;
        }
    }
    return 0;
}
