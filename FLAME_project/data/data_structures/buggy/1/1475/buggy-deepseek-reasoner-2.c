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
            printf("%d",ans[i]); // @@ missing space separator between numbers
        }
        printf("\n"); 
        return dfs(x-1); // @@ incorrect return; should be just 'return;' (invalid void return expression)
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