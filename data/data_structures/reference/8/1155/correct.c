#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int v[200], a, b, m[200][200], q[200], l, r;

void dfs(int n);
void bfs(int n);

int main()
{
    int x, y, i, d;
    scanf("%d%d", &a, &b);
    for (i = 1; i <= b; i++)
    {
        scanf("%d%d", &x, &y);
        m[x][y] = 1;
        m[y][x] = 1;
    }
    dfs(0);
    printf("\n");
    memset(v, 0, sizeof(v));
    bfs(0);
    printf("\n");
    memset(v, 0, sizeof(v));
    memset(q, 0, sizeof(q));
    l = r = 0;
    scanf("%d", &d);
    v[d] = 1;
    dfs(0);
    printf("\n");
    memset(v, 0, sizeof(v));
    v[d] = 1;
    bfs(0);
    return 0;
}

void dfs(int n)
{
    printf("%d ", n);
    v[n] = 1;
    for (int i = 0; i < a; i++)
    {
        if (m[n][i] == 1 && v[i] == 0)
            dfs(i);
    }
    return;
}

void bfs(int n)
{
    printf("%d ", n);
    v[n] = 1;
    q[l++] = n;
    while (l >= r)
    {
        int t = q[r++];
        for (int i = 0; i < a; i++)
        {
            if (m[t][i] == 1 && v[i] == 0)
            {
                printf("%d ", i);
                v[i] = 1;
                q[l++] = i;
            }
        }
    }
    return;
}

