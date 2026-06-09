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
            printf("%d",ans[i]); // @@ Missing spaces between numbers; should print with spaces like "%d " and handle last number without trailing space
        }
        printf("\n"); 
        return dfs(x-1); // @@ Incorrect recursive call; should just return, not call dfs(x-1) which causes infinite recursion
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