//图的深度优先和广度优先遍历
#include<stdio.h>
typedef struct Graph
{
    int numVertexes;
    int numEdges;
    int edges[100][100];
}Graph;
//深度优先遍历
void DFS(Graph *g,int i,int *visited)
{
    visited[i]=1;
    printf("%d ",i);
    for(int j=0;j<g->numVertexes;j++)
    {
        if(g->edges[i][j]==1&&visited[j]==0)
        {
            DFS(g,j,visited);
        }
    }
}
//广度优先遍历
void BFS(Graph *g,int i,int *visited)
{
    int queue[100];
    int front=0;
    int rear=0;
    queue[rear]=i;
    rear++;
    visited[i]=1;
    while(front!=rear)
    {
        front++;
        int j=queue[front-1];
        printf("%d ",j);
        for(int k=0;k<g->numVertexes;k++)
        {
            if(g->edges[j][k]==1&&visited[k]==0)
            {
                queue[rear]=k;
                rear++;
                visited[k]=1;
            }
        }
    }
}

int main()
{
    Graph G,*g=&G;
    scanf("%d %d",&G.numVertexes,&G.numEdges);
    for(int i=0;i<G.numEdges;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        G.edges[a][b]=1;
        G.edges[b][a]=1;
    }
    int visited[100];
    for(int i=0;i<G.numVertexes;i++)
    {
        visited[i]=0;
    }
    DFS(g,0,visited);
    printf("\n");
    for(int i=0;i<G.numVertexes;i++)
    {
        visited[i]=0;
    }
    BFS(g,0,visited);
    printf("\n");
    int delete_vertex;
    scanf("%d",&delete_vertex);
    for(int i=0;i<G.numVertexes;i++)
    {
        G.edges[delete_vertex][i]=0;
        G.edges[i][delete_vertex]=0;
    }
    for(int i=0;i<G.numVertexes;i++)
    {
        visited[i]=0;
    }
    DFS(g,0,visited);
    printf("\n");
    for(int i=0;i<G.numVertexes;i++)
    {
        visited[i]=0;
    }
    BFS(g,0,visited);
    printf("\n");
    return 0;
}
