#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <malloc.h>
#define MAXLEN 100
int N, LINE, DEL;
int graph[MAXLEN][MAXLEN];
int visited[MAXLEN];
void DFS(int v)
{
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < N; i++)
    {
        if (graph[v][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}
int queue[MAXLEN];
int front = 0, rear = -1;
void BFS(int v)
{
    visited[v] = 1;
    queue[++rear] = v;
    while (front <= rear)
    {
        v = queue[front++];
        printf("%d ", v);
        for (int i = 0; i < N; i++)
        {
            if (graph[v][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}
int main()
{
    scanf("%d %d", &N, &LINE);
    { //图的录入
        int a, b;
        for (int i = 0; i < LINE; i++)
        {
            scanf("%d %d", &a, &b);
            graph[a][b] = 1;
            graph[b][a] = 1;
        }
        scanf("%d", &DEL);
    }
    DFS(0);
    printf("\n");
    memset(visited, 0, sizeof(visited));
    BFS(0);
    printf("\n");
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < N; i++)
    {
        graph[DEL][i] = 0;
        graph[i][DEL] = 0;
    }
    DFS(0);
    printf("\n");
    memset(visited, 0, sizeof(visited));
    BFS(0);
    return 0;
}
