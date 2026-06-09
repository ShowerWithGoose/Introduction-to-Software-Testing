#include<stdio.h>
int a[105];
int i,j,n,key,top;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1)
            break;
        if(n==0)
        {
            if(top<=0)
                printf("error ");
            else
                printf("%d ",a[top--]);
        }
        if(n==1)
        {
            scanf("%d",&key);
            if(top>=99)
                printf("error ");
            else
                a[++top]=key;
        }
    }
    return 0;
}

