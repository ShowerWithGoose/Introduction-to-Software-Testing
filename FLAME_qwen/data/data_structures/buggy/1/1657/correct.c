#include<stdio.h>
int n;
void cal(int a[],int flg[],int i,int ans[])
{
    int j,k;
    if(i==n)
    {
        for(k=0;k<n;k++)
            printf("%d ",ans[k]);
        printf("\n");
    }
    else
        for(j=0;j<n;j++)
            if(flg[j]==0)
            {
                ans[i]=a[j];
                flg[j]=1;
                cal(a,flg,i+1,ans);
                flg[j]=0;
            }
}
int main()
{
    int i,flg[20],a[20],ans[20];
    scanf("%d",&n);
    for(int i=0;i<n;i++) a[i]=i+1;
    for(i=0;i<n;i++) flg[i]=0;
    cal(a,flg,0,ans);
    return 0;
}
