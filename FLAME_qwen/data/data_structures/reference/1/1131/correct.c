#include<stdio.h>
#include<string.h>

    int n;
    int  a[15],re[15];
    int vis[15];
    void dfs(int step) {
        int i;
        if (step == n + 1)
        {
            for (i = 1;i <= n;i++)
                printf("%d ", re[i]);
            printf("\n");
            return;
        }
        for (i = 1;i <= n;i++)
        {
            if (vis[i] == 0)
            {
                re[step] = a[i];
                vis[i] = 1;
                dfs(step + 1);
                vis[i] = 0;
            }
        }
        return;
    }

    int main() {
        int i, t;
        scanf("%d", &t);
        n = t;
        for (i = 1;i <= n;i++) 
            a[i] = i;
        dfs(1);
        return 0;
    }

