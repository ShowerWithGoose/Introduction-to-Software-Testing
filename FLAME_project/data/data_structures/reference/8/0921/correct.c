#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
int weights[200][200], visited[200] = {0}, que[200];
int n, m, lf;
void travelDFS(int v)
{
    int i;
    printf("%d ", v);
    visited[v] = 1;
    for (i = 0; i < n; i++)
        if (weights[v][i] && !visited[i])
        {
            travelDFS(i);
        }
}
void travelBFS(int v)
{
    int i, head = 0, tail = 1, tmp;
    que[head] = v;
    while (head <= tail)
    {
        tmp = que[head];
        head++;
        if (visited[tmp])
            continue;
        else
        {
            printf("%d ", tmp);
            visited[tmp] = 1;
            for (i = 0; i < n; i++)
                if (weights[tmp][i] && !visited[i])
                    que[tail++] = i;
        }
    }
}
int read()
{
    int x = 0, f = 1, c = getchar();
    while (c < '0' || c > '9')
        (c == '-') ? (f = -1) : 0, c = getchar();
    while (c >= '0' && c <= '9')
        x = x * 10 + c - '0', c = getchar();
    return x * f;
}

int main()
{
    int u, v, i, d;
    n = read();
    m = read();
    for (i = 0; i < m; i++)
    {
        u = read();
        v = read();
        weights[u][v] = 1;
        weights[v][u] = 1;
        lf++;
    }
    travelDFS(0);
    if (lf)
    {
        puts("");
    }
    for (i = 0; i < 200; i++)
    {
        visited[i] = 0;
    }
    travelBFS(0);
    puts("");

    d = read();
    for (i = 0; i < 200; i++)
    {
        visited[i] = 0;
    }
    visited[d] = 1;
    travelDFS(0);
    puts("");
    for (i = 0; i < 200; i++)
    {
        visited[i] = 0;
    }
    for (i = 0; i < 200; i++)
    {
        que[i] = 0;
    }
    visited[d] = 1;
    travelBFS(0);
    printf(" ");
    return 0;
}


