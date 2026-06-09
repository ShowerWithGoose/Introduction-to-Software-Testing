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
            scanf("%d ", &num); // @@ [The format string has an extra space which may cause input parsing issues, especially at the end of input or before -1. This can lead to waiting for unintended input.]
            if (top > 99)
                printf("error ");
            stack[top++] = num; // @@ [This assignment happens even when the stack is full (i.e., after printing "error "), leading to buffer overflow. The push should only occur if not full.]
            break;
        case 0:
            if (top == 0)
                printf("error ");
            printf("%d ", stack[top-- - 1]); // @@ [When the stack is empty (top == 0), this line still executes and accesses stack[-1], causing undefined behavior. The pop print should only happen if stack is not empty. Also, missing break causes fall-through to case -1.]
        case -1:
            break; // @@ [Missing break in case 0 causes fall-through to case -1, but more critically, after handling -1, the loop doesn't terminate immediately as it should. The program should exit upon reading -1.]
        default:
            break;
        }
    }
    return 0;
}