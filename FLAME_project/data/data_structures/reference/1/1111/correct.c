#include<stdio.h>
#include<string.h>

int n;
int a[11];
int vis[15];
void dfs(int step)
{
    int i;
    if(step==n+1)
    {
        for(i=1;i<=n;i++)
            printf("%d ",a[i]);
        printf("\n");
        return ;
    }
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            a[step]=i;
            vis[i]=1;
            dfs(step+1);
            vis[i]=0;
        }
    }
    return ;
}

int main(void)
{

    scanf("%d",&n);
    dfs(1);
    return 0;
}

