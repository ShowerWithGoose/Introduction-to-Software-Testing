#include <stdio.h>
#include <string.h>
int ans[105], tag[105], map[105][105], cur;
void dfs(int point, int n)
{
    if (cur == n)
    {
        for (int i = 0; i < n; i++)
            printf("%d ", ans[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i < n + 1; i++)
        if (tag[i] == 0 && map[point][i] == 1)
        {
            tag[i] = 1;
            ans[cur++] = i;
            dfs(i, n);
        }
}
void bfs(int n)
{
    int queue[105], head = 0, tail = 1;
    queue[0] = 0;
    while (head < tail)
    {
        for (int i = 1; i < n + 1; i++)
            if (tag[i] == 0 && map[queue[head]][i] == 1)
            {
                tag[i] = 1;
                queue[tail++] = i;
            }
        ans[cur++] = queue[head++];
    }
    for (int i = 0; i < n; i++)
        printf("%d ", ans[i]);
    printf("\n");
    return;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        map[x][y] = 1;
        map[y][x] = 1;
    }
    int target;
    scanf("%d", &target);
    tag[0] = 1;
    cur = 1;
    dfs(0, n);
    memset(ans, 0, sizeof(int) * n);
    memset(tag, 0, sizeof(int) * n);
    tag[0] = 1;
    cur = 0;
    bfs(n);
    for (int i = 0; i < n; i++)
    {
        map[target][i] = 0;
        map[i][target] = 0;
    }
    memset(ans, 0, sizeof(int) * n);
    memset(tag, 0, sizeof(int) * n);
    tag[0] = 1;
    cur = 1;
    dfs(0, n - 1);
    memset(ans, 0, sizeof(int) * n);
    memset(tag, 0, sizeof(int) * n);
    tag[0] = 1;
    cur = 0;
    bfs(n - 1);
    return 0;
}
