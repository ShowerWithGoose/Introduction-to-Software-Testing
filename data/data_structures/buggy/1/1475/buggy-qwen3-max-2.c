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
            printf("%d",ans[i]); // @@ [Missing space between numbers as required by output format]
        }
        printf("\n"); 
        return dfs(x-1); // @@ [Incorrect recursive return: should just return, not call dfs again; causes infinite recursion and wrong control flow]
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
    dfs(1); // @@ [Starting index is 1, but condition checks x>n instead of x==n+1 or x==n; leads to off-by-one logic error in base case]
    
return 0;
}