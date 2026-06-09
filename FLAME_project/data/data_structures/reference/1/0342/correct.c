/*
 * @Author:
 * @Date: 2022-03-03 20:50:39
 * @LastEditors:
 * @LastEditTime: 2022-03-03 20:54:27
 * @FilePath: permutation.c
 */
#include <stdio.h>
#define MAXN 10
int n;
int vis[MAXN],A[MAXN];

void dfs(int x)
{
    if(x > n)
    {
        for(int i=1;i<=n;++i)
            printf("%d ",A[i]);
        putchar('\n');
        return ;
    }
    for(int i=1;i<=n;++i)
    if(!vis[i])
    {
        A[x] = i;
        vis[i] = 1;
        dfs(x+1);
        vis[i] = 0;
    }
    return;
}

int main()
{
    scanf("%d",&n);
    dfs(1);
    return 0;
}


