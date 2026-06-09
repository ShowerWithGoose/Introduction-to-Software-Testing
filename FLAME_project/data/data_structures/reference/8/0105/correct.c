#include <stdio.h>
#include <string.h>
int graph[300][300], visited[300] = {0}, Que[200];
int G, L;
void DFSofgraph(int p)
{
    printf("%d ", p);
    visited[p] = 1;
    for (int i = 0; i < G; i++)
    {
        if (graph[p][i] && !visited[i])
        {
            DFSofgraph(i);
        }
    }
}
void BFSofgraph(int p)
{
    int h = 0, t = 1, tmp;
    Que[h] = p;
    while (h <= t)
    {
        tmp = Que[h++];
        if (!visited[tmp])
        {
            printf("%d ", tmp);
            visited[tmp] = 1;
            for (int i = 0; i < G; i++)
            {
                if (graph[tmp][i] && !visited[i])
                {
                    Que[t++] = i;
                }
            }
        }
    }
}
void del()
{
    printf("\n");
    for (int i = 0; i < G; i++)
    {
        visited[i] = 0;
    }
}
int main()
{
    int n, m, d;
    scanf("%d%d", &G, &L);
    for (int i = 0; i < L; i++)
    {
        scanf("%d %d", &n, &m);
        graph[n][m] = 1;
        graph[m][n] = 1;
    }
    scanf("%d", &d);
    DFSofgraph(0);
    del();
    BFSofgraph(0);
    del();
    for (int i = 0; i < G; i++)
    {
        for (int j = 0; i < G; i++)
        {
            if (i == d || j == d)
            {
                graph[i][j] = 0;
            }
        }
    }
    visited[d] = 1;
    DFSofgraph(0);
    del();
    visited[d] = 1;
    BFSofgraph(0);
    del();
}
