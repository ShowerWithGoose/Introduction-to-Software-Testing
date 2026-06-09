#include<stdio.h>
int a[105]={0};
int main()
{
    int n,k;
    while(1)
    {
        scanf("%d",&n);
        if(n==-1)break;
        if(n==1)
        {
            scanf("%d",&k);
            if(a[0]==100)
            {
                printf("error ");
                continue;
            }
            a[++a[0]]=k;
        }
        else if(n==0)
        {
            // scanf("%d",&k);
            if(a[0]==0)
            {
                printf("error ");
                continue;
            }
            printf("%d ",a[a[0]]);
            a[0]--;
        }
    }
    return 0;
}
