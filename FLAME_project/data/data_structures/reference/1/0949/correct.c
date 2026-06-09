#include<stdio.h>
int n,vis[15],array[15];
void dfs(int sum)
{
    if(sum==n)
    {
        for(int i=0;i<n;i++)
        printf("%d ",array[i]);
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++)
    if(!vis[i])
    {
        vis[i]=1;
        array[sum]=i;
        dfs(sum+1);
        vis[i]=0;
    }
}
int main()
{
    scanf("%d",&n);
    dfs(0);
    return 0;
}


