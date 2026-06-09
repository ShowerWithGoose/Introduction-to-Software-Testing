#include <stdio.h>
#include <string.h>
int graph[105][106], wg[105] = {0};
int i, j, k, num1, num2, p, queue[105], f = 0, r = -1;
void dfs(int v)
{
    int i;
    wg[v] = 1;
    printf("%d ", v);
    for (i = 0; i <= num1; i++)
    {
        if (graph[v][i] == 1 && wg[i] != 1)
        {
            dfs(i);
        }
    }
    return;
}
void bfs(int v)
{
    int i, t;
    queue[0] = v;
    for (f = 0, r = 0; f <= r;)
    {
        t = queue[f++];
        if (wg[t] == 1)
        {
            continue;
        }
        printf("%d ", t);
        wg[t] = 1;
        for (i = 0; i < num1; i++)
        {
            if (graph[t][i] == 1 && wg[i] != 1)
            {
                queue[++r] = i;
            }
        }
    }
    return;
}
int main()
{
    scanf("%d%d", &num1, &num2);
    for (k = 0; k < num2; k++)
    {
        scanf("%d%d", &i, &j);
        graph[i][j] = 1;
        graph[j][i] = 1;
        graph[i][105] = 1;
    }
    scanf("%d", &p);
    dfs(0);
    printf("\n");
    memset(wg, 0, 105);
    bfs(0);
    printf("\n");
    for (i = 0; i < num1; i++)
    {
        graph[p][i] = 0;
    }
    for (i = 0; i < num2; i++)
    {
        graph[i][p] = 0;
    }
    memset(wg, 0, 105);
    dfs(0);
    printf("\n");
    memset(wg, 0, 105);
    bfs(0);
    printf("\n");
    return 0;
}
