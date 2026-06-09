#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define Min(_A, _B) ((_A) < (_B) ? (_A) : (_B))
#define Max(_A, _B) ((_A) > (_B) ? (_A) : (_B))
#define rd() read()
#define maxn (200)
#define maxm (1005)
#define maxk (30)

int read()
{
    register int x = 0, f = 0;
    register char ch;
    do
    {
        ch = getchar();
        f |= (ch == '-');
    } while (ch < '0' || ch > '9');
    do
    {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar();
    } while (ch >= '0' && ch <= '9');
    return f ? (-x) : x;
}

int g[maxn][maxn];
int vis[maxn];
int n, m, de;

void init()
{
    memset(vis, 0, sizeof(vis));
}

void dfs(int x)
{
    vis[x] = 1;
    printf("%d ", x);
    for (int i = 0; i < n; ++i)
    {
        if (vis[i] == 0 && g[x][i] == 1)
            dfs(i);
    }
}

int q[maxn];
int front, rear;
void bfs()
{
    front = rear = 0;
    q[rear++] = 0;
    vis[0] = 1;
    register int x;
    while (front < rear)
    {
        x = q[front++];
        printf("%d ", x);
        for (int i = 0; i < n; ++i)
        {
            if (vis[i] == 0 && g[x][i])
            {
                q[rear++] = i;
                vis[i] = 1;
            }
        }
    }
}

int main()
{
    // freopen("data.in", "r", stdin);
    init();
    n = rd(), m = rd();
    register int x, y;
    for (int i = 1; i <= m; ++i)
    {
        x = rd(), y = rd();
        g[x][y] = g[y][x] = 1;
    }
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < n; ++j)
    //         printf("%d ", g[i][j]);
    //     putchar('\n');
    // }
    de = rd();

    init();
    dfs(0);
    putchar('\n');

    init();
    bfs();
    putchar('\n');

    for (int i = 0; i < n; ++i)
        g[i][de] = g[de][i] = 0;
    init();
    dfs(0);
    putchar('\n');

    init();
    bfs();
    return 0;
}
