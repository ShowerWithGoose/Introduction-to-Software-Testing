#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>

#define MVNUM 100                //最大顶点数
#define MAXINT 32767

typedef struct
{
    char vexs[MVNUM];            //顶点数据数组
    int arr[MVNUM][MVNUM];            //邻接矩阵
    int vexnum, arcnum;            //现有顶点数与边数
}AMGraph;

int visit[200] = {0},que[200];

void initGraph(AMGraph G);
void dfsAM(AMGraph G,int i);
void bfsAM(AMGraph G,int i);

int main(void){
    int i,u,v,del;
    AMGraph G;
    scanf("%d %d",&G.vexnum,&G.arcnum);
    for(i = 0;i < G.arcnum;i++)
    {
        scanf("%d %d",&u,&v);
        G.arr[u][v] = 1;
        G.arr[v][u] = 1;
    }
    scanf("%d",&del); // @@ [The deletion vertex is read BEFORE performing the initial DFS/BFS traversals, but it should be read AFTER them. This causes the 'del' value to be used prematurely in logic that assumes it's only applied later. However, more critically, the graph matrix 'arr' is not initialized to 0, so unassigned entries may contain garbage values, leading to incorrect adjacency checks.]
    dfsAM(G,0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    
    bfsAM(G,0);
    printf("\n");
    memset(visit,0,sizeof(visit));

    visit[del] = 1;
    dfsAM(G,0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    
    visit[del] = 1;
    bfsAM(G,0);
    printf("\n");

    return 0;
}

void initGraph(AMGraph G)
{
    for(int i = 0;i < G.arcnum;i++) // @@ [This loop uses G.arcnum (number of edges) instead of G.vexnum (number of vertices), causing incomplete initialization of the adjacency matrix. Also, the inner loop increments 'i' instead of 'j', leading to infinite loop or undefined behavior. But even worse: this function is never called, so the adjacency matrix contains uninitialized garbage values, which breaks traversal logic.]
    {
        for(int j = 0;j < G.arcnum;i++) // @@ [Typo: incrementing 'i' instead of 'j'; also wrong bound (should be G.vexnum).]
        {
            G.arr[i][j] = MAXINT;
        }
    }
}
void dfsAM(AMGraph G,int v)
{
    printf("%d ",v);
    visit[v] = 1;
    for(int i = 0;i < G.vexnum;i++)
    {
        if(G.arr[v][i] == 1&&visit[i] != 1)
        {
            dfsAM(G,i);
        }
    }
}
void bfsAM(AMGraph G,int v)
{
    int i,head = 0,tail = i,tmp; // @@ [Variable 'i' is uninitialized here, so 'tail = i' results in undefined behavior. It should be 'tail = 1' or similar to start with one element in queue.]
    que[head] = v;
    while(head <= tail)
    {
        tmp = que[head];
        head++;
        if(visit[tmp] == 1)
        {
            continue;
        }
        else
        {
            printf("%d ",tmp);
            visit[tmp] = 1;
            for(i = 0;i < G.vexnum;i++)
            {
                if(G.arr[tmp][i] == 1&&visit[i] != 1)
                {
                    que[tail++] = i;
                }
            }
        }
    }
}