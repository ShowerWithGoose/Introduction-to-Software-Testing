#include <stdio.h>
#include <string.h>
#include <math.h>

int n;
int ans[15], check[15];
void dfs(int x) //ans的第几位
{
    if (x == n + 1)
    {
        for (int i = 1; i <= n; i ++ )
            printf("%d ", ans[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i <= n; i ++ )
    {
        if (!check[i])
        {
            ans[x] = i;
            check[i] = 1;
            dfs(x + 1);
            check[i] = 0;
        }
    }
}

int main()
{
    scanf("%d", &n);
    dfs(1);

    return 0;
}


