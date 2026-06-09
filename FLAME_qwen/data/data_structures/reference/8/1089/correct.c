#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, m;
int s[200][200], p[200] = {0}, q[200];
void dfs(int c);
void travel(int c);
int main()
{
    int a, c, d;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &c, &d);
        s[c][d] = 1;
        s[d][c] = 1;
    }
    dfs(0);
    puts("");
    memset(p, 0, sizeof(p));
    travel(0);
    puts("");
    scanf("%d", &a);
    memset(p, 0, sizeof(p));
    p[a] = 1;
    dfs(0);
    puts("");
    memset(p, 0, sizeof(p));
    memset(q, 0, sizeof(q));
    p[a] = 1;
    travel(0);
    puts("");
    return 0;
}
void dfs(int c)
{
    int i;
    printf("%d ", c);
    p[c] = 1;
    for (i = 0; i < n; i++)
    {
        if (s[c][i] && !p[i])
            dfs(i);
    }
}
void travel(int c)
{
    int i, tmp, head = 0, tail = 1;
    q[head] = c;
    while (head <= tail)
    {
        tmp = q[head];
        head++;
        if (p[tmp])
            continue;
        else
        {
            printf("%d ", tmp);
            p[tmp] = 1;
            for (i = 0; i < n; i++)
                if (s[tmp][i] && !p[i])
                    q[tail++] = i;
        }
    }
}
