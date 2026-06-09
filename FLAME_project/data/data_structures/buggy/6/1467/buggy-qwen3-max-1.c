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
            room[++flag] = num; @@ // The stack pointer 'flag' is incremented before storing, so the first element is stored at index 1. However, during pop, 'flag' is decremented first, then room[flag+1] is printed. This causes inconsistency: after a push, 'flag' points to the top index, but after a pop, 'flag' becomes one less than the actual top index. Also, stack overflow (when flag >= 100) is not checked.
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
                printf("%d ",room[flag+1]); @@ // After decrementing 'flag', the top element should be at 'room[flag+1]' only if the push used pre-increment. But because the initial state has flag=0 (empty), the first push makes flag=1 and stores at room[1]. Then a pop decrements flag to 0 and prints room[1] — which is correct for the first pop. However, if two pops occur on an empty stack: first pop sets flag=-1 → prints "error", second pop sets flag=-2 → also prints "error". That part is okay. The real issue is missing stack full check during push and incorrect indexing logic that leads to off-by-one in capacity handling. Also, after printing an error for underflow, the program continues with negative 'flag', which may cause future pops to access invalid indices even after pushes (because pushes start from room[++flag], so if flag=-1, next push goes to room[0], but then pop will print room[0+1]=room[1], which is wrong).
            }
        }
    }
    return 0;
}