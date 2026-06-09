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
            scanf("%d ", &num); // @@ [The format string has an extra space which may cause input parsing issues, especially at the end of input or before -1.]
            if (top > 99)
                printf("error ");
            stack[top++] = num; // @@ [This line executes even when stack is full (top > 99), causing buffer overflow. It should be inside an else block.]
            break;
        case 0:
            if (top == 0)
                printf("error ");
            printf("%d ", stack[top-- - 1]); // @@ [This line executes even when stack is empty (top == 0), leading to undefined behavior. It should be inside an else block.]
        case -1: // @@ [Missing 'break;' causes fall-through to default (though harmless here), but more critically, the program does not terminate on -1 as required.]
            break;
        default:
            break;
        }
    }
    return 0;
}