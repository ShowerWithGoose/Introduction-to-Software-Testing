#include<math.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int stack[105];
int op,tail;
signed main()
{
    scanf("%d",&op);
    while(op!=-1)
    {

        if(op==1)
        {
            scanf("%d",&stack[tail]);
            tail++;
        }
        else if(op==0)
        {
            if(tail==0)
            printf("error ");
            else 
            {
                tail--;
                printf("%d ",stack[tail]);
            }
        }
        
        scanf("%d",&op);
    }
    return 0;
}
