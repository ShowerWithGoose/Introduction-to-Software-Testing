#include <stdio.h>
#include <string.h>

#define MAXV 105

void dfs(int vertex, int graph[][MAXV], int position);
void bfs(int vertex, int graph[][MAXV], int position);

int main()
{
    int vertex, edge;
    int graph[MAXV][MAXV] = {{0}};
    scanf("%d%d", &vertex, &edge);

    for (int i = 0; i < edge; i++)
    {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        // init graph
        graph[v1][v2] = graph[v2][v1] = 1;
    }

    int DeNum;
    scanf("%d", &DeNum);

    dfs(vertex, graph, 0);
    bfs(vertex, graph, 0);
    // delete
    for (int i = 0; i < vertex; i++)
        graph[i][DeNum] = graph[DeNum][i] = 0;

    dfs(vertex - 1, graph, 0);
    bfs(vertex - 1, graph, 0);
}

int passed[MAXV], record[MAXV], cnt;
void dfs(int vertex, int graph[][MAXV], int position)
{
    if (cnt >= vertex)
        return;
    passed[position] = 1;
    printf("%d ", position);
    for (int i = 0; i < vertex + 1; i++)
        if (!passed[i] && graph[position][i])
        {
            dfs(vertex, graph, i);
            cnt++;
        }
    cnt = 0;
}

int queue[MAXV];
void bfs(int vertex, int graph[][MAXV], int position)
{
    putchar('\n');
    memset(passed, 0, MAXV);
    putchar('0');
    queue[cnt++] = position;
    for (int i = 0; i < vertex; i++)
    {
        passed[queue[i]] = 1;
        for (int j = 0; j < vertex + 1; j++)
        {
            if (!passed[j] && graph[queue[i]][j])
            {
                printf(" %d", j);
                passed[j] = 1;
                queue[cnt++] = j;
                if (cnt == vertex)
                    break;
            }
        }
        if (cnt == vertex)
            break;
    }
    putchar('\n');
    cnt = 0;
    memset(passed, 0, MAXV);
}


