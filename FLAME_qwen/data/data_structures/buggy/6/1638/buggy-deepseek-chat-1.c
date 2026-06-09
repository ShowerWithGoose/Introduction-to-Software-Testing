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
            scanf("%d ", &num); // @@ The format string "%d " has a trailing space, which may cause input issues; should be "%d"
            if (top > 99)
                printf("error ");
            stack[top++] = num; // @@ When the stack is full (top > 99), the push should not occur, but this line always executes, causing overflow
            break;
        case 0:
            if (top == 0)
                printf("error ");
            printf("%d ", stack[top-- - 1]); // @@ When the stack is empty (top == 0), this line still executes, causing underflow; also missing break statement
        case -1:
            break; // @@ This break only exits the switch, not the while loop; should use return 0 to terminate
        default:
            break;
        }
    }
    return 0;
}