#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct 
{
    int vertices;
    int edges;
    int adj[MAX_VERTICES][MAX_VERTICES];
}graph;

void dfs(graph *graph,int start,int *visit_record)
{
    visit_record[start] = 1;
    printf("%d ",start);
    for(int i=0;i<graph->vertices;++i)
    {
        if(graph->adj[start][i] == 1 && visit_record[i] == 0)
        {
            dfs(graph,i,visit_record);
        }
    }
}

void bfs(graph *graph,int start,int *visit_record)
{
    int queue[MAX_VERTICES];
    int front = 0,back = 0;
    queue[back++] = start;
    visit_record[start] = 1;
    //printf("%d",start);
    while(front<back)
    {
        int x = queue[front++];
        printf("%d",x); // @@ Missing space between numbers; should be "%d " to match expected output
        for(int i=0;i<graph->vertices;++i)
        {
            if(graph->adj[x][i] == 1 && visit_record[i] == 0)
            {
                queue[back++] = i;
                visit_record[i] = 1;
            }
        }
    }
}

int main()
{
    graph graph;
    scanf("%d %d",&graph.vertices,&graph.edges);

    //初始化
    for(int i=0;i<graph.vertices;++i)
    {
        for(int j=0;j<graph.vertices;++j)
        {
            graph.adj[i][j] = 0;
        }
    }

    //读取图
    for(int i=0;i<graph.edges;++i)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        graph.adj[u][v] = 1;
        graph.adj[v][u] = 1;
    }

    int visit_record[MAX_VERTICES] = {0};
    dfs(&graph,0,visit_record);
    bfs(&graph,0,visit_record); // @@ Logical error: visit_record is already fully marked by dfs, so bfs will output nothing. Need to reset visit_record before bfs.

    int need_remove_vertex;
    scanf("%d",&need_remove_vertex);
    for(int i=0;i<graph.vertices;++i)
    {
        graph.adj[need_remove_vertex][i] = 0;
        graph.adj[i][need_remove_vertex] = 0;
    }

    int visit_record[MAX_VERTICES] = {0}; // @@ Compilation error: redefinition of 'visit_record'; previous definition at line above inside same function. Use a different variable name or reset the existing array.
    dfs(&graph,0,visit_record);
    bfs(&graph,0,visit_record); // @@ Same logical error: visit_record is not reset after the second dfs.
    return 0;
}