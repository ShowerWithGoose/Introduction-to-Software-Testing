#include <stdio.h>

int V = 0, E = 0, pd = 0, data[110][110] = {0};
int md1[110] = {0}, md2[110] = {0};
void dfs(int p);
void bfs(int p);

int main()
{
    int m = 0, n = 0;
    int i = 0, j = 0;
    scanf("%d %d", &V, &E);
    for (i = 0; i < E; i++)
    {
        scanf("%d %d", &m, &n);
        data[m][n] = 1;
        data[n][m] = 1;
    }
    dfs(0);
    printf("\n");

    pd = 0;
    for (i = 0; i < 110; i++)
    {
        md1[i] = 0;
    }
    bfs(0);
    printf("\n");

    pd = 0;
    for (i = 0; i < 110; i++)
    {
        md1[i] = 0;
    }
    scanf("%d", &m);
    md1[m] = 1;
    dfs(0);
    printf("\n");

    pd = 0;
    for (i = 0; i < 110; i++)
    {
        md1[i] = 0;
    }
    md1[m] = 1;
    bfs(0);
    printf("\n");

    pd = 0;
    for (i = 0; i < 110; i++)
    {
        md1[i] = 0;
    }
    return 0;
}

void dfs(int p)
{
    int i = 0;
    if (pd == 0)
    {
        pd = 1;
        printf("%d", p);
    }
    else
    {
        printf(" %d", p);
    }
    md1[p] = 1;
    for (i = 0; i < V; i++)
    {
        if (md1[i] == 0)
        {
            if (data[p][i] == 1)
            {
                dfs(i);
            }
        }
    }
}

void bfs(int p)
{
    int i = 0, j = 0, r = 0;
    int mid = 0;
    md2[1] = p;
    for (j = 1, r = 1; j <= r; 1)
    {

        mid = md2[j];
        j++;
        if (md1[mid] == 1)
            continue;
        if (pd == 0)
        {
            printf("%d", mid);
            pd = 1;
        }
        else
            printf(" %d", mid);
        md1[mid] = 1;
        for (i = 0; i < V; i++)
        {
            if (data[mid][i] == 1 && md1[i] == 0)
            {
                r++;
                md2[r] = i;
            }
        }
    }
}
