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
            room[++flag] = num; // @@ [Error: The stack should push after incrementing flag, but flag starts at 0, so ++flag makes the first element at index 1, leaving index 0 unused. However, the pop logic uses flag-- and then accesses room[flag+1], which works correctly for this indexing. The real issue is that the stack capacity check is missing: if flag reaches 100 (the maximum capacity), a push should output "error" and not push the element. Also, the pop operation decrements flag before checking if the stack is empty, which causes flag to become -1 and then the error check fails to detect the empty stack properly because the decrement happens first.]
        }
        else if (op == 0)
        {
            flag--; // @@ [Error: The pop operation decrements flag before checking if the stack is empty. This means when the stack is empty (flag == 0), flag becomes -1, and then the condition flag < 0 is true, so it prints "error". However, the expected behavior is to check emptiness before decrementing, and if empty, print "error" without changing the stack state. Additionally, after a successful pop, the element should be printed from room[flag+1] (which is correct given the pre-decrement), but the logic is flawed because the decrement happens even when the stack is empty, leading to incorrect state.]
            if (flag < 0)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",room[flag+1]);
            }
        }
    }
    return 0;
}