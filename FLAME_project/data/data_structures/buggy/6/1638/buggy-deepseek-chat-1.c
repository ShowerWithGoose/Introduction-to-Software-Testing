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
            scanf("%d ", &num); // @@ The format string "%d " includes a trailing space, which may cause input reading issues; should be "%d"
            if (top > 99)
                printf("error ");
            stack[top++] = num; // @@ When the stack is full (top > 99), the push should not be performed, but here it always pushes regardless of the error condition
            break;
        case 0:
            if (top == 0)
                printf("error ");
            printf("%d ", stack[top-- - 1]); // @@ When the stack is empty (top == 0), this line still executes and prints an invalid value; should only print if pop is valid
        case -1:
            break;
        default:
            break;
        }
    }
    return 0;
}