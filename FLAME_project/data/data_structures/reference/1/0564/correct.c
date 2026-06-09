#include<stdio.h>
int ans[11],n;
int f()
{
    int i,j,m,i1,i2,t;
    for(i=n-1;i>0;i--)
    {
        if(ans[i]<ans[i+1])
        {
            i1=i;
            for(j=n;j>i;j--) if(ans[j]>ans[i]) {i2=j;break;}
            t=ans[i1];
            ans[i1]=ans[i2];
            ans[i2]=t;
            for(m=n,j=i1+1;m>j;m--,j++)
            {
                t=ans[m];
                ans[m]=ans[j];
                ans[j]=t;
            }
            for(i=1;i<=n;i++) printf("%d ",ans[i]);
            printf("\n");
            return 1;
        }
    }
    return -1;

}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        ans[i]=i;
        printf("%d ",ans[i]);
    }
    printf("\n");
    for(;f()==1;);
    return 0;
}

























