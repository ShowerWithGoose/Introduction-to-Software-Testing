#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int graph[200][200];
int visit[200];
int line[200];
int num_vertev, num_edge;
void traval_DFS(int temp);
void traval_BFS(int data);
int main()
{
    int vertex, edge;
    int i;
    int m, n;
    int delete_vertex;
    scanf("%d%d", &num_vertev, &num_edge);
    for (i = 0; i < num_edge; i++)
    {
        scanf("%d%d", &m, &n);
        graph[m][n] = 1;
        graph[n][m] = 1;
    }
    scanf("%d", &delete_vertex);
    traval_DFS(0);
    printf("\n");
    memset(visit, 0, sizeof(visit));
    traval_BFS(0);
    printf("\n");
    memset(visit, 0, sizeof(visit));
    visit[delete_vertex] = 1;
    traval_DFS(0);
    printf("\n");
    memset(visit, 0, sizeof(visit));
    memset(line, 0, sizeof(line));
    visit[delete_vertex] = 1;
    traval_BFS(0);
    printf("\n");
    return 0;
}
void traval_DFS(int data)
{
    int i;
    printf("%d ", data);
    visit[data] = 1;
    for (i = 0; i < num_vertev; i++)
    {
        if (graph[data][i] && visit[i] == 0)
        {
            traval_DFS(i);
        }
    }
}
void traval_BFS(int data)
{
    int head = 0, end = 1;
    int temp;
    int i;
    line[head] = data;
    while (head <= end)
    {
        temp = line[head];
        head++;
        if (visit[temp] == 1)
        {
            continue;
        }
        else
        {
            printf("%d ", temp);
            visit[temp] = 1;
            for (i = 0; i < num_vertev; i++)
            {
                if (graph[temp][i] && visit[i] == 0)
                {
                    line[end] = i;
                    end++;
                }
            }
        }
    }
}

