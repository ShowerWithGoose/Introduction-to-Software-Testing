#include<stdio.h>

int a[200][200];    //edge info
int visited[200];
int queue_bfs[200];
int front = 0, end = -1;    //queue

void traverse_graph_dfs(int vertex, int num_vertex);
void traverse_graph_bfs(int num_vertex);

void reset_visited()
{
    int i;
    for(i = 0; i < 200; i++)
        visited[i] = 0;
}

int main()
{
    int n, num_edge, i;
    scanf("%d%d", &n, &num_edge);
    for(i = 0; i < num_edge; i++)
    {
        int vertex_a, vertex_b;
        scanf("%d%d", &vertex_a, &vertex_b);
        a[vertex_a][vertex_b] = a[vertex_b][vertex_a] = 1;
    }
    traverse_graph_dfs(0, n);
    printf("\n");
    reset_visited();
    traverse_graph_bfs(n);
    printf("\n");
    reset_visited();
    int vertex_del;
    scanf("%d", &vertex_del);
    for(i = 0; i < n; i++)
        a[vertex_del][i] = a[i][vertex_del] = 0;
    traverse_graph_dfs(0, n);
    printf("\n");
    reset_visited();
    traverse_graph_bfs(n);
    return 0;
}

void traverse_graph_dfs(int vertex, int num_vertex)
{
    printf("%d ", vertex);
    visited[vertex] = 1;
    int i;
    for(i = 0; i < num_vertex; i++)
        if(a[vertex][i] && !visited[i])
            traverse_graph_dfs(i, num_vertex);
}

void traverse_graph_bfs(int num_vertex)
{
    queue_bfs[++end] = 0;
    visited[0] = 1;
    while(front <= end)
    {
        int vertex_cur = queue_bfs[front++];
        printf("%d ", vertex_cur);
        int i;
        for(i = 0; i < num_vertex; i++)
            if(a[vertex_cur][i] && !visited[i])
                queue_bfs[++end] = i, visited[i] = 1;
    }
}
