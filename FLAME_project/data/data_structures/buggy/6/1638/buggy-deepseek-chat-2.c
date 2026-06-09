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
            scanf("%d ", &num); // @@ The space after %d causes scanf to consume extra whitespace, which may skip the next operation. Use "%d" instead.
            if (top > 99)
                printf("error ");
            stack[top++] = num; // @@ When stack is full (top > 99), the push should not occur, but here it always pushes regardless of the error condition.
            break;
        case 0:
            if (top == 0)
                printf("error ");
            printf("%d ", stack[top-- - 1]); // @@ When top == 0 and error is printed, this line still executes, printing an invalid value. Should use else to skip pop on error.
        case -1:
            break; // @@ Missing break after case 0 causes fall-through to case -1, which breaks out of switch but not the loop, causing infinite loop. Should add break after case 0.
        default:
            break;
        }
    }
    return 0;
}