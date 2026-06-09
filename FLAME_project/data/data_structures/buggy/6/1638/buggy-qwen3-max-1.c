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
            scanf("%d ", &num); @@ [The space after %d in scanf can cause input parsing issues by consuming extra whitespace or waiting for more input, leading to incorrect reads. It should be "%d" without trailing space.]
            if (top > 99)
                printf("error ");
            stack[top++] = num; @@ [Push operation occurs even when stack is full (top > 99), which violates the problem requirement to output "error" and skip the push. The assignment should only happen if there's no error.]
            break;
        case 0:
            if (top == 0)
                printf("error ");
            printf("%d ", stack[top-- - 1]); @@ [Pop operation executes regardless of whether the stack is empty. When top == 0, it still tries to access stack[-1], causing undefined behavior. The pop print should only occur in the else branch.]
        case -1:
            break; @@ [Missing 'break;' after case 0 causes fall-through into case -1, but more critically, there's no 'return 0;' or exit upon reading -1 as required by the problem. The program continues processing instead of terminating immediately.]
        default:
            break;
        }
    }
    return 0;
}