#include <stdio.h>

int n;
int vis[100];
void dfs(int x,int num)
{
    int i;
    if(x==n+1)
    {
        printf("%d\n",num); // @@ [This prints the permutation as a single integer, which fails when N >= 10 because digits are concatenated. Also, it does not output space-separated values as required, and for N=10, numbers like 10 cannot be represented as single digits in base-10 concatenation.]
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            dfs(x+1,num*10+i); // @@ [Storing permutation as an integer by num*10+i breaks when any number in permutation is >=10 (e.g., N=10 includes '10'), since 10 cannot be represented as a single digit in base-10 concatenation. This leads to incorrect or malformed output.]
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