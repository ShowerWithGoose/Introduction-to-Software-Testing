#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 10
int n;
int vis[N];
int ans[N];
void dfs(int x)
{
    if(x>n) // @@ [The base case condition is incorrect. It should be x == n + 1 or better yet, use 0-based indexing consistently. Since the recursion starts at x=1 and goes to x=n, the correct termination is when x == n+1, but printing should happen when x == n+1, however the loop prints from i=1 to n which is okay. However, the bigger issue is the recursive call in the base case.]
    {
        for(int i=1;i<=n;i++)
        {
            printf("%d",ans[i]); // @@ [Missing space between numbers as required by the output format. Should be "%d " instead of "%d".]
        }
        printf("\n"); 
        return dfs(x-1); // @@ [Invalid recursive call in base case. This causes infinite recursion and undefined behavior. Should just return;]
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