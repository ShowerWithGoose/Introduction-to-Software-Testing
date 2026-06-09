#include<stdio.h>
#include<string.h>
int a[10]={1,2,3,4,5,6,7,8,9,10};
void pl(int ,int ,int [],int []); 
int main()
{
    int n,i,z[10],ans[10];
    memset(z,0,sizeof(z));
    scanf("%d",&n);
    pl(n,0,z,ans);
    return 0;
}
void pl(int n,int i,int z[],int ans[])
{
    int j,k;
    if(i==n)
    {
        for(k=0;k<n;k++)
        {
            printf("%d ",ans[k]);
        }
        putchar(10); 
    }
    else
    {
        for(j=0;j<n;j++)
        {
            if(z[j]==0)
            {
                ans[i]=a[j];
                z[j]=1;
                pl(n,i+1,z,ans);
                z[j]=0;
            }
        }
    }
}


