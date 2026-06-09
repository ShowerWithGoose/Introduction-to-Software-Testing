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
            printf("%d",ans[i]); // @@ The output format is incorrect. Integers should be separated by spaces, but here they are printed consecutively without spaces.
        }
        printf("\n"); 
        return dfs(x-1); // @@ This line causes undefined behavior or logical error. 'dfs' is a void function, so returning its result is invalid. Furthermore, after printing a permutation, the function should simply return to backtrack, not call dfs again with x-1.
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