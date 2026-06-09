#include <stdio.h>

int main()
{
    int stack[100] = {0};
    int *p = stack - 1, mode, n;
    const int *begin = stack - 1, *end = stack + 100;
    for(;;)
    {
        scanf("%d",&mode);
        if(mode == -1)  
            break;
        else if(mode == 0)
        {
            if(p == begin)
                printf("error ");
            else
            {
                printf("%d ",*p);
                p-=1;
            }
        }
        else if(mode == 1)
        {
            p++;
            if(p == end)
                printf("error ");
            else
            {
                scanf("%d",&n);
                *p = n;
            }
        }
    }
    return 0;
}
