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
            room[++flag] = num; // @@ [Error: The stack index is incremented before storing, so room[1] stores the first element, but flag starts at 0. When popping, flag is decremented first, so room[flag+1] accesses the wrong element. Additionally, there is no check for stack overflow (max capacity 100).]
        }
        else if (op == 0)
        {
            flag--;
            if (flag < 0)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",room[flag+1]); // @@ [Error: After decrementing flag, flag+1 points to the element that was just popped, but due to the pre-increment in push, the indices are off by one. For example, after pushing 5, flag=1, room[1]=5. On pop, flag becomes 0, and room[1] is printed, which is correct, but subsequent pushes and pops will misalign because the first element is at index 1, not 0. Also, when the stack is empty (flag=0) and a pop occurs, flag becomes -1, and the error is printed, but the next push will set flag to 0 and store at room[0], causing inconsistency.]
            }
        }
    }
    return 0;
}