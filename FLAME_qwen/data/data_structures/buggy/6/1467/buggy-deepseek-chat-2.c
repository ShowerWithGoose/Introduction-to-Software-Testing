#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int main()
{
    int op,num,flag=0,room[110]={0};
    while (~scanf("%d",&op))
    {
        if (op == -1)
        {
            break;
        }
        else if (op == 1)
        {
            scanf("%d",&num);
            room[++flag] = num; // @@ Error: The push operation does not check if the stack is full (maximum capacity 100). When flag reaches 100, incrementing it to 101 causes an out-of-bounds write to room[101], and subsequent pushes will continue to write beyond the array bounds.
        }
        else if (op == 0)
        {
            flag--; // @@ Error: The pop operation decrements flag before checking if the stack is empty. If flag is 0, decrementing makes it -1, and then the check `if (flag < 0)` correctly prints "error", but the value printed in the else branch uses room[flag+1] which would be room[0] (the wrong element). The correct order is to first check if the stack is empty, then decrement and print.
            if (flag < 0)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",room[flag+1]); // @@ Error: Due to the premature decrement, when flag is 0 and a pop is attempted, flag becomes -1, the error is printed, but the else branch is not executed. However, for a valid pop, after decrementing flag, the element to print is at index flag (since flag now points to the top), not flag+1. For example, after pushing one element, flag=1; pop should print room[0] (the element at index 0), but this code prints room[1] (which is uninitialized or wrong).
            }
        }
    }
    return 0;
}