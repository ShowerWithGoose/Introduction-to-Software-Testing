#include <stdio.h>
int m[200];
int main()
{
    int i=0,op,n;
    for(i=0;;)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d",&n);
            if(i==100)
                printf("error ");
            else
                m[i++]=n;
        }
        if(op==0)
        {
            if(i==0)
                printf("error ");
            else
                printf("%d ",m[--i]);
        }
        if(op==-1)
            break;
    }
}



