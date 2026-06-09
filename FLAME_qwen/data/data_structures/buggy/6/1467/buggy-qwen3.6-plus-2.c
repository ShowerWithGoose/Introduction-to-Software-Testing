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
            room[++flag] = num; // @@ Missing check for stack full (max capacity 100). Should verify flag < 100 before pushing, otherwise print "error ".
        }
        else if (op == 0)
        {
            flag--; // @@ Stack pointer is decremented before checking if the stack is empty, which corrupts the state on underflow.
            if (flag < 0) // @@ Checks emptiness after decrement; should check if flag == 0 before decrementing to handle empty stack properly.
            {
                printf("error ");
            }
            else
            {
                printf("%d ",room[flag+1]); // @@ Indexing relies on flawed decrement logic; should print room[flag] then decrement flag.
            }
        }
    }
    return 0;
}