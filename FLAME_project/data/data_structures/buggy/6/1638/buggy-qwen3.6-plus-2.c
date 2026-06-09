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
                printf("error "); // @@ The code continues to push even when the stack is full, causing incorrect state and output. It should skip the push operation.
            stack[top++] = num; // @@ This line executes regardless of whether the stack is full, leading to buffer overflow or incorrect data being pushed after an error.
            break;
        case 0:
            if (top == 0)
                printf("error ");
            else // @@ Missing else block. The pop and print operation should only occur if the stack is not empty. Currently, it prints garbage/incorrect values when stack is empty after printing "error ".
            printf("%d ", stack[top-- - 1]);
        case -1:
            break;
        default:
            break;
        }
    }
    return 0;
}