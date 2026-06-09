#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define Min(_A, _B) ((_A) < (_B) ? (_A) : (_B))
#define Max(_A, _B) ((_A) > (_B) ? (_A) : (_B))
#define rd() read()
#define maxn (105)
#define maxm (2005)

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

typedef struct
{
    int x1, x2, y1, y2;
} Link;

Link a[maxn];

int f[maxn];

int cmp(Link *a, Link *b)
{
    if (a->x1 == b->x1)
    {
        return (a->y1 - b->y1);
    }
    return (a->x1 - b->x1);
}

int cck(int i, int j)
{
    return a[i].x2 == a[j].x1 && a[i].y2 == a[j].y1;
}

int main()
{
    // freopen("data.in", "r", stdin);
    int n = rd();
    for (int i = 1; i <= n; ++i)
    {
        f[i] = 1;
        scanf("%d%d%d%d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
    }
    // for (int i = 1; i <= n; ++i)
    // {
    //     printf("%d %d %d %d\n", a[i].x1, a[i].y1, a[i].x2, a[i].y2);
    // }
    // puts("233");
    qsort(a + 1, n, sizeof(Link), cmp);
    for (int i = n; i >= 1; --i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            if (cck(i, j))
                f[i] = Max(f[j] + 1, f[i]);
        }
        // printf("%d %d %d %d\n", a[i].x1, a[i].y1, a[i].x2, a[i].y2);
    }
    int ans = 0, id;
    for (int i = 1; i <= n; ++i)
    {
        if (f[i] > ans)
        {
            ans = f[i];
            id = i;
        }
    }
    printf("%d %d %d", ans, a[id].x1, a[id].y1);
}
