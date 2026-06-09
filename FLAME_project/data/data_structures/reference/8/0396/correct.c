#include <stdio.h>
#include <stdlib.h>

typedef struct Graph G;
struct Graph
{
    int Vex[100];       //顶点标记为1表示存在,否则为不存在
    int Edge[100][100]; //边标记为1表示存在,否则不存在
    int Vexnum, Edgenum;
};
G graph;
int visited[100] = {0}; //标记顶点是否被访问过的数组

void DFS(G, int);
void DFStraverse(G);
void BFStraverse(G);

int main()
{
    scanf("%d%d", &graph.Vexnum, &graph.Edgenum);
    for (int i = 0; i < graph.Edgenum; i++)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        graph.Edge[n][m] = 1;
        graph.Edge[m][n] = 1;
        graph.Vex[n] = 1;
        graph.Vex[m] = 1;
    }
    int DeleteVex;
    scanf("%d", &DeleteVex);
    DFStraverse(graph);
    printf("\n");
    BFStraverse(graph);
    printf("\n");
    graph.Vex[DeleteVex] = 0;
    for (int i = 0; i < graph.Vexnum; i++)
    {
        graph.Edge[i][DeleteVex] = 0;
        graph.Edge[DeleteVex][i] = 0;
    }
    DFStraverse(graph);
    printf("\n");
    BFStraverse(graph);
    return 0;
}
void DFS(G graph, int i)
{
    printf("%d ", i); //访问第i个顶点
    visited[i] = 1;   //标记第i个顶点已访问
    for (int j = 0; j < graph.Vexnum; j++)
    {
        if (graph.Edge[i][j] == 1 && visited[j] == 0 && graph.Vex[i] == 1)
            DFS(graph, j);
    }
}
void DFStraverse(G graph)
{
    for (int i = 0; i < graph.Vexnum; i++) //将访问数组初始化为0
        visited[i] = 0;
    for (int i = 0; i < graph.Vexnum; i++)
        if (visited[i] == 0 && graph.Vex[i] == 1) //对未访问的结点调用DFS
            DFS(graph, i);
}
void BFStraverse(G graph)
{
    int Queue[107] = {0};
    int right = 0, left = 0;
    for (int i = 0; i < graph.Vexnum; i++)
        visited[i] = 0;
    for (int i = 0; i < graph.Vexnum; i++)
    {
        if (visited[i] == 0 && graph.Vex[i] == 1)
        {
            printf("%d ", i);
            visited[i] = 1;
        }
        Queue[left++] = i;
        while (right != left)
        {
            i = Queue[right++];
            for (int j = 0; j < graph.Vexnum; j++)
            {
                if (graph.Edge[i][j] == 1 && visited[j] == 0 && graph.Vex[j] == 1)
                {
                    printf("%d ", j);
                    visited[j] = 1;
                    Queue[left++] = j;
                }
            }
        }
    }
}


