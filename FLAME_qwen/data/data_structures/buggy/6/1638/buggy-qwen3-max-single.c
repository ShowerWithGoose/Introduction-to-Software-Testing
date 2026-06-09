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
            scanf("%d ", &num); // @@ [The format string has an extra space which may consume unintended whitespace and cause input parsing issues, especially before -1 or 0.]
            if (top > 99)
                printf("error ");
            stack[top++] = num; // @@ [This line executes even when the stack is full (top > 99), causing a buffer overflow. It should only execute if there's no error.]
            break;
        case 0:
            if (top == 0)
                printf("error ");
            printf("%d ", stack[top-- - 1]); // @@ [This line executes even when the stack is empty (top == 0), leading to undefined behavior. It should be inside an else block.]
        case -1:
            break; // @@ [Missing 'break;' after case 0 causes fall-through into case -1, but more critically, there's no exit on -1; program continues looping instead of terminating. Also, -1 should terminate the program immediately.]
        default:
            break;
        }
    }
    return 0;
}