#include<stdio.h>
#include<string.h>

int mark[10]; // @@ Array size should be at least 11 to safely index up to mark[10] when N=10
int a[10]; // @@ Array size should be at least 11 to safely index up to a[10] when N=10
int n;

void dfs(int x)
{
    int i;
    if(x == n + 1)
    {
        for(i = 1; i <= n; i++)
        {
            printf("%d",a[i]); // @@ Missing space after each number; should be "%d " to match expected output format
        }
        puts("");
        return ;
    }
    for(i = 1; i <= n; i++)
    {
        if(!mark[i])
        {
            mark[i] = 1;
            a[x] = i;
            dfs(x + 1);
            mark[i] = 0;    
        }
    }
}

int main()
{
    scanf("%d", &n);
    dfs(1);
    return 0;
}