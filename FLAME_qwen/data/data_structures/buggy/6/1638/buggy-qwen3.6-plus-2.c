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
            scanf("%d ", &num); // @@ The trailing space in the format string causes scanf to skip whitespace and wait for non-whitespace input, potentially causing the program to hang or misread input.
            if (top > 99)
                printf("error "); // @@ Missing else clause or control flow statement. The subsequent push operation will execute unconditionally, leading to stack overflow or incorrect state.
            stack[top++] = num;
            break;
        case 0:
            if (top == 0)
                printf("error "); // @@ Missing else clause or control flow statement. The subsequent pop operation will execute unconditionally, causing undefined behavior when the stack is empty.
            printf("%d ", stack[top-- - 1]); // @@ Missing break statement causes fall-through to case -1. Additionally, if top is 0, accessing stack[-1] is out of bounds.
        case -1:
            break; // @@ According to the problem, -1 indicates the end of operations. This should be return 0; to terminate the program, otherwise the while loop continues indefinitely or processes further input incorrectly.
        default:
            break;
        }
    }
    return 0;
}