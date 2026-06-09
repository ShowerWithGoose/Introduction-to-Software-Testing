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
            room[++flag] = num; // @@ [Pushes without checking if stack is full (capacity exceeded). Stack size is 100 but array allows 110 and flag starts at 0, so when flag reaches 100, it's already over capacity. Also, pre-increment causes room[1] to be first element, making room[0] unused and logic off-by-one.]
        }
        else if (op == 0)
        {
            flag--; // @@ [Decrements flag before checking if stack is empty. If flag is 0 (empty), this makes it -1, then checks, which leads to printing room[0] (uninitialized or leftover value) instead of handling error correctly. Should check before decrementing.]
            if (flag < 0)
            {
                printf("error ");
            }
            else
            {
                printf("%d ",room[flag+1]); // @@ [After decrementing flag, accesses room[flag+1], which is the element just popped, but due to earlier pre-increment during push, indexing is inconsistent and may access invalid or wrong data. Also, if previous pop caused flag=-1, this would access room[0], which was never written in push (since push uses ++flag starting from 0).]
            }
        }
    }
    return 0;
}