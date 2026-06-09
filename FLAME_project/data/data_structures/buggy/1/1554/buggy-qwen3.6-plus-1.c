#include <stdio.h>

int n;
int vis[100];
void dfs(int x,int num)
{
    int i;
    if(x==n+1)
    {
        printf("%d\n",num); // @@ The problem requires integers to be separated by spaces. This line prints the permutation as a single concatenated number (e.g., "12") instead of space-separated integers (e.g., "1 2"). Additionally, for N >= 10, integer overflow would occur with this approach, but even for small N, the format is incorrect.
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            dfs(x+1,num*10+i); // @@ Using arithmetic (num*10+i) to build the permutation is fragile and incorrect for the required output format. It prevents printing spaces between numbers. A standard approach uses an array to store the current permutation path.
            vis[i]=0;
        }
    }
}
int main()
{
    scanf("%d",&n);
    dfs(1,0);
    return 0;
}