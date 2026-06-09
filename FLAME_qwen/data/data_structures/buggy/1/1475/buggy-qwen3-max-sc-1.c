#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 10
int n;
int vis[N];
int ans[N];
void dfs(int x)
{
    if(x>n)
    {
        for(int i=1;i<=n;i++)
        {
            printf("%d",ans[i]); // @@ [Missing space between numbers as required by output format; should print "%d " instead of "%d"]
        }
        printf("\n"); 
        return dfs(x-1); // @@ [Incorrect recursive return: should just 'return;' instead of 'return dfs(x-1);' which causes infinite recursion and undefined behavior]
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
    dfs(1); // @@ [Starting index is 1, but condition checks x>n; this leads to generating n+1 elements instead of n. Should start at 0 or adjust condition to x==n]
    
return 0;
}