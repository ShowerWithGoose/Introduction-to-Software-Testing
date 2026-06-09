#include <stdio.h>
#include <string.h>

int a[200][200], visited[400] = {0}, queue[400] = {0};
void dfs(int p, int n);
void bfs(int p, int n);

int main()
{
    int u = 0, v = 0, n = 0, m = 0;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d", &u, &v);
        a[u][v] = 1;
        a[v][u] = 1;
    }

    dfs(0, n);
    printf("\n");

    memset(visited, 0, sizeof(visited));
    bfs(0, n);
    printf("\n");

    memset(visited, 0, sizeof(visited));
    int delete = 0;
    scanf("%d", &delete);
    visited[delete] = 1;
    dfs(0, n);
    printf("\n");

    memset(visited, 0, sizeof(visited));
    memset(queue, 0, sizeof(int));
    visited[delete] = 1;
    bfs(0, n);

    return 0;
}

void dfs(int p, int n)
{
    visited[p] = 1;
    printf("%d ", p);
    for (int i = 0; i < n; ++i)
    {
        if (a[p][i] && visited[i] != 1)
        {
            dfs(i, n);
        }
    }
}

void bfs(int p, int n)
{
    int head = 0, rear = -1, q = 0;
    queue[++rear] = p;
    while (head <= rear)
    {
        q = queue[head++];
        if (visited[q])
            continue;
        else
        {
            printf("%d ", q);
            visited[q] = 1;
            for (int i = 0; i < n; ++i)
            {
                if (a[q][i] && visited[i] != 1)
                {
                    queue[++rear] = i;
                }
            }
        }
    }
}
