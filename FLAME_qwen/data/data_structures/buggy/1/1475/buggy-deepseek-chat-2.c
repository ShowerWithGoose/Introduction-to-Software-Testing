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
            printf("%d",ans[i]);
        }
        printf("\n"); 
        return dfs(x-1); // @@ [Error: This should be 'return;' not 'return dfs(x-1);'. Calling dfs(x-1) here causes infinite recursion and incorrect backtracking. The function should simply return after printing a permutation.]
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