#include <stdio.h>
int N,vis[15],fl[15];
void dfs(int cnt)
{
    if(cnt==N+1)
    {
        for(int i=1;i<=N;i++)
        {
            printf("%d ",fl[i]);
        }
        puts(" ");
        return;
    }
    for(int i=1;i<=N;i++)
    {
        if(!vis[i])
        {
            fl[cnt]=i;
            vis[i]=1;
            dfs(cnt+1);
            vis[i]=0;
        }
    }
}

int main()
{
    scanf("%d",&N);
    dfs(1);
    return 0;
}
