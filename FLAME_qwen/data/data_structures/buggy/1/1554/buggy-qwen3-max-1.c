#include <stdio.h>

int n;
int vis[100];
void dfs(int x,int num)
{
    int i;
    if(x==n+1)
    {
        printf("%d\n",num); // @@ [This prints the permutation as a single integer, which fails when N >= 10 because digits merge (e.g., 1 and 0 become 10). Also, it doesn't output space-separated values as required.]
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            dfs(x+1,num*10+i); // @@ [Storing permutation as an integer breaks for N >= 10 since multi-digit numbers cannot be represented correctly in a base-10 integer without separators.]
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