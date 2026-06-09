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
            scanf("%d ", &num); // @@ [The format string has an extra space which may cause input parsing issues, especially before -1; also, missing check before assignment leads to potential overflow]
            if (top > 99)
                printf("error ");
            stack[top++] = num; // @@ [Assignment happens even when stack is full (top > 99), causing buffer overflow]
            break;
        case 0:
            if (top == 0)
                printf("error ");
            printf("%d ", stack[top-- - 1]); // @@ [Pop operation executes even when stack is empty (after printing "error "), leading to undefined behavior]
            break; // @@ [Missing break causes fall-through to case -1]
        case -1:
            break;
        default:
            break;
        }
    }
    return 0;
}