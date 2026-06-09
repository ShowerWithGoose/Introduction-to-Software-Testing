#include <stdio.h>

int n;
int vis[100];
void dfs(int x,int num)
{
    int i;
    if(x==n+1)
    {
        printf("%d\n",num); // @@ [This prints the permutation as a single integer, which fails when N >= 10 because digits are concatenated (e.g., 1 and 10 become 110), and even for N <= 9 it doesn't output space-separated values as required. Also, lexicographical order is not guaranteed due to numeric concatenation.]
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            dfs(x+1,num*10+i); // @@ [Storing permutation as an integer by num*10+i breaks for N>=10 (since numbers have more than one digit) and also causes incorrect lexicographical ordering for N<=9 because permutations like [1,2] and [12] would be indistinguishable if N were larger; but more critically, the problem requires space-separated integers per line, not a single integer.]
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