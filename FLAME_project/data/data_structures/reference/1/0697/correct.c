#include<stdio.h>
#include<string.h>
int n;
int v[100000];
int q[100000];
void dfs(int dep)
{
    if(dep==n+1)
    {
        for(int i=1;i<=n;i++)printf("%d ",q[i]);
        puts("");return;
    }
    for(int i=1;i<=n;i++)
    if(!v[i])
    {
        v[i]=1;q[dep]=i;dfs(dep+1);v[i]=0;
    }
}
signed main()
{
    scanf("%d",&n);
    dfs(1);
}


