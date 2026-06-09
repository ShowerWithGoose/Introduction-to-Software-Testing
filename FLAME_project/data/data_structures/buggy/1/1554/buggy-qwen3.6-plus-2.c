#include <stdio.h>

int n;
int vis[100];
void dfs(int x,int num)
{
    int i;
    if(x==n+1)
    {
        printf("%d\n",num); // @@ The problem requires integers to be separated by spaces. This line prints the accumulated number as a single integer without spaces (e.g., "12" instead of "1 2"). Additionally, for N>=10, this approach fails because digits cannot be distinguished in a single integer variable. A proper implementation should store the permutation in an array and print elements with spaces.
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