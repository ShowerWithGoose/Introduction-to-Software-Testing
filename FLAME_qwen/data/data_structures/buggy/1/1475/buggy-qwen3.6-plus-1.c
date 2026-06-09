#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 10
int n;
int vis[N]; // @@ Array size N is insufficient for 1-based indexing when N=10, causing out-of-bounds access.
int ans[N]; // @@ Array size N is insufficient for 1-based indexing when N=10, causing out-of-bounds access.
void dfs(int x)
{
    if(x>n)
    {
        for(int i=1;i<=n;i++)
        {
            printf("%d",ans[i]); // @@ Missing space separator between integers as required by the output format.
        }
        printf("\n");
        return dfs(x-1); // @@ Compilation error: 'dfs' returns void, so it cannot be used in a return statement. Logically, it should just be 'return;' to backtrack.
    }

    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            ans[x]=i;
            vis[i]=1;
            dfs(x+1);
            vis[i]=0;
        }
    }
}

int main ()
{
    scanf("%d",&n);
    dfs(1);

return 0;
}