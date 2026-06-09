#include <stdio.h>

int n;
int vis[100];
void dfs(int x,int num)
{
    int i;
    if(x==n+1)
    {
        printf("%d\n",num); // @@ The output format requires integers to be separated by spaces, but this prints the accumulated number as a single integer. Additionally, for N>=10, integer accumulation overflows or concatenates incorrectly.
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            dfs(x+1,num*10+i); // @@ Using an integer to accumulate permutation values is incorrect for N>=10 and prevents space-separated output. An array should be used to store the current permutation.
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