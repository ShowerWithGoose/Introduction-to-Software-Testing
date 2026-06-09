#include<stdio.h>
#include<string.h>

int mark[10]; // @@ [Array size is too small; for N=10, indices 1..10 are used, but mark[10] only has indices 0..9, leading to out-of-bounds access]
int a[10]; // @@ [Array size is too small; for N=10, a[1] to a[10] are accessed, but a[10] only has indices 0..9, causing buffer overflow]
int n;

void dfs(int x)
{
    int i;
    if(x == n + 1)
    {
        for(i = 1; i <= n; i++)
        {
            printf("%d",a[i]); // @@ [Missing space between numbers as required by output format; should be "%d "]
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