#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int G[105][105]; //邻接矩阵
int visited[105];
int QUE[100], rear = -1, front = -1;

int FIRSTADJ(int G[][105], int v);
int NEXTADJ(int G[][105], int v);

void DFS(int G[][105], int v)
{
    int w;
    printf("%d ", v);
    visited[v] = 1;
    w = FIRSTADJ(G, v);
    while (w != -1)
    {
        if (visited[w] == 0)
            DFS(G, w);
        w = NEXTADJ(G, v);
    }
}

void TRAVEL_DFS(int G[][105], int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (visited[i] == 0)
            DFS(G, i);
}

void BFS(int G[][105], int v)
{
    int w;
    printf("%d ", v);
    visited[v] = 1;
    QUE[++rear] = v;
    while (front != rear)
    {
        v = QUE[++front];
        w = FIRSTADJ(G, v);
        while (w != -1)
        {
            if (visited[w] == 0)
            {
                printf("%d ", w);
                QUE[++rear] = w;
                visited[w] = 1;
            }
            w = NEXTADJ(G, v);
        }
    }
}

void TRAVEL_BFS(int G[][105], int n)
{
    int i;
    for (i = 0; i < n; i++)
        if (visited[i] == 0)
            BFS(G, i);
}

int main()
{
    int points, edges, delete;
    scanf("%d%d", &points, &edges);

    int m, n;
    for (int i = 0; i < edges; i++)
    {
        scanf("%d%d", &m, &n);
        G[m][n] = 1, G[n][m] = 1;
    }

    memset(visited, 0, sizeof(visited));
    TRAVEL_DFS(G, points);
    printf("\n");

    memset(visited, 0, sizeof(visited));
    TRAVEL_BFS(G, points);
    printf("\n");

    scanf("%d", &delete);
    visited[delete] = 1;

    memset(visited, 0, sizeof(visited));
    visited[delete] = 1;
    TRAVEL_DFS(G, points);
    printf("\n");

    memset(visited, 0, sizeof(visited));
    visited[delete] = 1;
    TRAVEL_BFS(G, points);
    printf("\n");

    return 0;
}

int FIRSTADJ(int G[][105], int v)
{
    int i;
    for (i = 0; i < 105; i++)
        if (G[v][i] == 1 && visited[i] == 0)
            return i;
    return -1;
}

int NEXTADJ(int G[][105], int v)
{
    int i;
    for (i = 0; i < 105; i++)
        if (G[v][i] == 1 && visited[i] == 0)
            return i;
    return -1;
}
