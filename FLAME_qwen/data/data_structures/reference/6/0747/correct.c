#include<stdio.h>
int main()
{
    int a[100]={0};
    int i=0,op,x;
    scanf("%d",&op);
    while(op!=-1)
    {
        if(op==1)
        {
            if(i<100)
            {
                scanf("%d",&x);
                a[i]=x;
                i++;
            }
            else
                printf("error ");
        }
        else if(op==0)
        {
            if(i==0)
            {
                if(a[0]==0)
                    printf("error ");
                else
                {
                    printf("%d ",a[0]);
                    a[0]=0;
                }
            }
            else
            {
                printf("%d ",a[i-1]);
                a[i-1]=0;
                i--;
            }
        }
        scanf("%d",&op);
    }
    return 0;
}

