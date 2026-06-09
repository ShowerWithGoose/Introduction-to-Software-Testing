#include <stdio.h>

int n;
int vis[100];
void dfs(int x,int num)
{
    int i;
    if(x==n+1)
    {
        printf("%d\n",num); // @@ Error: This prints the permutation as a single integer without spaces between digits. The problem requires each integer to be separated by a space, and the output should be in lexicographical order. Using integer concatenation (num*10+i) does not preserve leading zeros or proper digit separation for numbers > 9, and fails to output spaces.
        return;
    }
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
        {
            vis[i]=1;
            dfs(x+1,num*10+i); // @@ Error: This approach concatenates digits into a single integer, which cannot handle N > 9 (since digits like 10 would be misinterpreted) and does not produce space-separated output as required.
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