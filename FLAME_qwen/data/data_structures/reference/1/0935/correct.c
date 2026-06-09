#include<stdio.h>
#include<string.h>
int v[100]; 
int a[100];
void dfs(int in,int n)
{
    if(in==n)
    {
        for(int i=0;i<n;i++)
        {
            printf("%d ",a[i]);
        }
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(v[i]==0)
        {
            v[i]=1;
            a[in]=i;
            dfs(in+1,n);
            v[i]=0;
        }
    }
}
int main()
{   int n;  
    scanf("%d",&n);
    dfs(0,n);
    return 0;
}



