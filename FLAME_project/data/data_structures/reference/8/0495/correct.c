#include <stdio.h>
#include <string.h>

#define MAXN 105

void graphDFS(int graph[MAXN][MAXN], int vcnt, int visited[MAXN], FILE* stream);
void vDFS(int graph[MAXN][MAXN], int vcnt, int visited[MAXN], FILE* stream, int v);
void graphBFS(int graph[MAXN][MAXN], int vcnt, int visited[MAXN], FILE* stream);
void vBFS(int graph[MAXN][MAXN], int vcnt, int visited[MAXN], FILE* stream, int v);

int main()
{

    int vcnt, scnt;
    int graph[MAXN][MAXN] = {0};
    int i; int v1, v2;
    int visited[MAXN];
    int vdel;

    scanf("%d%d", &vcnt, &scnt);
    for (i = 0; i < scnt; i++)
    {
        scanf("%d%d", &v1, &v2);
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;
    }
    scanf("%d", &vdel);

    memset(visited, 0, sizeof(int) * MAXN);
    graphDFS(graph, vcnt, visited, stdout);

    memset(visited, 0, sizeof(int) * MAXN);
    graphBFS(graph, vcnt, visited, stdout);

    memset(visited, 0, sizeof(int) * MAXN);
    visited[vdel] = 1;
    graphDFS(graph, vcnt, visited, stdout);

    memset(visited, 0, sizeof(int) * MAXN);
    visited[vdel] = 1;
    graphBFS(graph, vcnt, visited, stdout);

    return 0;
}

void graphDFS(int graph[MAXN][MAXN], int vcnt, int visited[MAXN], FILE* stream)
{
    for (int v = 0; v < vcnt; v++)
    {
        if (!visited[v]) { vDFS(graph, vcnt, visited, stream, v); }
    }
    fprintf(stream, "\n");
}
void vDFS(int graph[MAXN][MAXN], int vcnt, int visited[MAXN], FILE* stream, int v)
{
    visited[v] = 1;
    fprintf(stream, "%d ", v);
    for (int i = 0; i < vcnt; i++)
    {
        if (graph[v][i] && !visited[i]) { vDFS(graph, vcnt, visited, stream, i); }
    }
}

void graphBFS(int graph[MAXN][MAXN], int vcnt, int visited[MAXN], FILE* stream)
{
    for (int v = 0; v < vcnt; v++)
    {
        if (!visited[v]) { vBFS(graph, vcnt, visited, stream, v); }
    }
    fprintf(stream, "\n");
}
void vBFS(int graph[MAXN][MAXN], int vcnt, int visited[MAXN], FILE* stream, int v)
{
    int queue[MAXN];
    int s = 0, t = -1;
    visited[v] = 1;
    queue[++t] = v; t %= MAXN;
    while (t >= s)
    {
        v = queue[s++]; s %= MAXN;
        fprintf(stream, "%d ", v);
        for (int i = 0; i < vcnt; i++)
        {
            if (graph[v][i] && !visited[i])
            {
                visited[i] = 1;
                queue[++t] = i; t %= MAXN;
            }
        }
    }
}

