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
            scanf("%d ", &num); // @@ The trailing space in scanf format can cause reading issues and does not match the input format. Also, no error handling for push when stack full (still executes the push after printing "error").
            if (top > 99)
                printf("error ");
            stack[top++] = num; // @@ This line executes even when the stack is full (after printing "error"). Should be in an else block.
            break;
        case 0:
            if (top == 0)
                printf("error ");
            printf("%d ", stack[top-- - 1]); // @@ This line executes unconditionally. When stack is empty (top==0), it prints "error " and then attempts to access stack[-1], causing undefined behavior. Also, it should only execute in an else branch.
        case -1: // @@ Missing break after case 0 causes fall-through into case -1. Also, case -1 should terminate the program, but it only breaks the switch, not the while loop.
            break; // @@ This break exits the switch, but the while loop continues, so the program does not stop when -1 is encountered. Should use return 0; or a loop exit mechanism.
        default:
            break;
        }
    }
    return 0;
}