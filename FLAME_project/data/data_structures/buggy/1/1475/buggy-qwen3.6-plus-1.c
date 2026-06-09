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
            printf("%d",ans[i]); // @@ [Missing space between numbers. The output format requires integers to be separated by a space, e.g., "1 2" instead of "12".]
        }
        printf("\n"); 
        return dfs(x-1); // @@ [Logical error: 'return dfs(x-1)' is invalid syntax for void function and logically incorrect. After printing a permutation, the function should simply return to backtrack. Calling dfs(x-1) disrupts the recursion stack and backtracking logic.]
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