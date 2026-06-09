#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 10
int n;
int vis[N]; // @@ Array size should be N+1 to prevent out-of-bounds access when n=10
int ans[N]; // @@ Array size should be N+1 to prevent out-of-bounds access when n=10
void dfs(int x)
{
    if(x>n)
    {
        for(int i=1;i<=n;i++)
        {
            printf("%d",ans[i]); // @@ Missing space separator between numbers as required by the output format
        }
        printf("\n"); 
        return dfs(x-1); // @@ Compilation error: void function cannot return a value; logically should just be 'return;' to backtrack
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