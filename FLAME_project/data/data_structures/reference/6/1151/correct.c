#include<stdio.h>
#include<string.h>
int a[105],tot;
signed main()
{
    int op,b;
    scanf("%d",&op);
    while(op!=-1)
    {
        if(op==1)
        {
            scanf("%d",&b);
            if(tot==100)
                printf("error ");
            else
                a[++tot]=b;
        }
        if(op==0)
        {
            if(!tot)
                printf("error ");
            else
                printf("%d ",a[tot--]);
        }
        scanf("%d",&op);
    }
}
