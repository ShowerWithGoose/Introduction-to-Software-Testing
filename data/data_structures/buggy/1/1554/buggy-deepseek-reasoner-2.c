#include <stdio.h>

int n;
int vis[100];
void dfs(int x,int num)
{
    int i;
    if(x==n+1)
    {
        printf("%d\n",num); // @@ Error: Output format requires each integer separated by space, not a concatenated number. Also fails for N=10 because 10 is two digits.
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            dfs(x+1,num*10+i);
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