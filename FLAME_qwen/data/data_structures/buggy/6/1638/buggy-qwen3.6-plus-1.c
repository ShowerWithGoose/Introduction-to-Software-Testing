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
            scanf("%d ", &num); // @@ The trailing space in the format string causes scanf to skip whitespace indefinitely, potentially causing the program to hang or misread subsequent inputs.
            if (top > 99)
                printf("error ");
            stack[top++] = num; // @@ Missing 'else' clause; this statement executes unconditionally, causing a push operation even when the stack is full, leading to buffer overflow.
            break;
        case 0:
            if (top == 0)
                printf("error ");
            printf("%d ", stack[top-- - 1]); // @@ Missing 'else' clause causes out-of-bounds array access when the stack is empty. Also missing 'break;' causes fall-through to case -1.
        case -1: // @@ Should terminate the program (e.g., return 0;) to end operations as specified, but currently only breaks the switch and continues the loop.
            break;
        default:
            break;
        }
    }
    return 0;
}