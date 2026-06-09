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
            scanf("%d ", &num); // @@ The format string "%d " expects a space after the integer, which may cause input issues; should be "%d"
            if (top > 99)
                printf("error ");
            stack[top++] = num; // @@ When the stack is full (top > 99), this line still pushes the element, causing overflow; should be in an else block
            break;
        case 0:
            if (top == 0)
                printf("error ");
            printf("%d ", stack[top-- - 1]); // @@ When the stack is empty (top == 0), this line still attempts to pop, causing underflow; should be in an else block
        case -1: // @@ Missing break statement before this case; execution falls through from case 0 to case -1, causing unintended behavior
            break;
        default:
            break;
        }
    }
    return 0;
}