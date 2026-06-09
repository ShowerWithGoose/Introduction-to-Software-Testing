#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 10
int n;
int vis[N];
int ans[N];
void dfs(int x)
{
    if(x>n) // @@ [The base case condition is incorrect. It should be x == n+1 or x == n depending on indexing, but the loop prints from 1 to n while using 1-based indexing for ans[]. However, the bigger issue is the recursive return call below.]
    {
        for(int i=1;i<=n;i++)
        {
            printf("%d",ans[i]); // @@ [Missing space between numbers as required by the output format. Should be "%d " instead of "%d".]
        }
        printf("\n"); 
        return dfs(x-1); // @@ [Incorrect recursive call after printing. This causes infinite recursion and undefined behavior. Should just be 'return;' since we are backtracking via the call stack.]
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
    dfs(1); // @@ [Starting dfs at index 1 is okay with 1-based logic, but combined with the flawed base case (x > n), it leads to accessing ans[n+1] which is out of intended bounds and causes incorrect termination. Also, the reference uses 0-based indexing which naturally fits x == n as base case.]
    
return 0;
}