#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
int w[200][200], v[200], q[200], n, m, head, tail;

void DFS(int t)
{
    printf("%d ", t);
    v[t] = 1;
    for (int i = 0; i < n; i++)
    {
        if (w[t][i] && !v[i])
            DFS(i);
    }
}
void BFS()
{
    head = tail = 0;
    int top;
    q[tail++] = 0;
    while (head <= tail)
    {
        top = q[head++];
        if (v[top])
            continue;
        else
        {
            printf("%d ", top);
            v[top] = 1;
            for (int i = 0; i < n; i++)
            {
                if (w[top][i] && !v[i])
                    q[tail++] = i;
            }
        }
    }
}
int main()
{
    int x, y, del;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &x, &y);
        w[x][y] = 1;
        w[y][x] = 1;
    }
    DFS(0);
    printf("\n");

    memset(v, 0, sizeof(v));
    BFS();
    printf("\n");

    scanf("%d", &del);
    memset(v, 0, sizeof(v));
    v[del] = 1;
    DFS(0);
    printf("\n");

    memset(v, 0, sizeof(v));
    memset(q, 0, sizeof(q));
    v[del] = 1;
    BFS();
    printf("\n");
    //system("pause");
    return 0;
}

