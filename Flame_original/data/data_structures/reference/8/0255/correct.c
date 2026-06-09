#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
int vertex[105][105];
int visited[105];
int queue[500];
void DFS(int a[][105], int v, int ver);
void BFS(int a[][105], int v, int ver);
int main()
{

    int i, j, k;
    int ver, edge;
    int tmp1, tmp2;
    int delete_ver;
    scanf("%d %d", &ver, &edge);
    for (i = 0; i < edge;i++)
    {
        scanf("%d %d", &tmp1, &tmp2);
        vertex[tmp1][tmp2] = 1;
        vertex[tmp2][tmp1] = 1;
    }
    scanf("%d", &delete_ver);
    DFS(vertex, 0, ver);
    printf("\n");

    memset(visited, 0, sizeof(visited));
    BFS(vertex, 0, ver);
    printf("\n");

    memset(visited, 0, sizeof(visited));
    visited[delete_ver] = 1;
    DFS(vertex, 0, ver);
    printf("\n");

    memset(visited, 0, sizeof(visited));
    visited[delete_ver] = 1;
    BFS(vertex, 0, ver);
    printf("\n");
    return 0;
}
void DFS(int a[][105], int v,int ver)
{
    int i;
    printf("%d ", v);
    visited[v] = 1;
    for (i = 0; i < ver; i++)
    {
        if (a[v][i] == 1 && visited[i] == 0)
            DFS(a, i, ver);
    }
}
void BFS(int a[][105], int v, int ver)
{
    int i, tmp;
    int front = -1, rear = -1;
    printf("%d ", v);
    visited[v] = 1;
    queue[++rear] = v;
    while(front < rear)
    {
        tmp = queue[++front];
        for (i = 0; i < ver; i++)
        {
            if (a[tmp][i] == 1 && visited[i] ==0)
            {
                printf("%d ", i);
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}
