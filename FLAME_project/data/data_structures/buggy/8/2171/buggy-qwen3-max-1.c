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
    scanf("%d",&del); @@ [The vertex to delete is read too early; it should be read after printing the traversals for the original graph. This causes the deletion to affect the "before deletion" traversals if visit[] is reused improperly, but more critically, the reference program reads 'del' after the first two traversals. However, in this buggy code, 'del' is read before any traversal, which by itself isn't wrong IF the visit array is clean. But the real issue is that the adjacency matrix is not initialized to 0, so unassigned entries may contain garbage.]
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
    for(int i = 0;i < G.arcnum;i++) @@ [This loop should iterate up to G.vexnum, not G.arcnum, because we are initializing a matrix of size vexnum x vexnum. Also, the inner loop has a typo: it increments 'i' instead of 'j'. But more importantly, this function is never called, so the adjacency matrix contains uninitialized (garbage) values for non-edge entries, which may accidentally equal 1 and create phantom edges.]
    {
        for(int j = 0;j < G.arcnum;i++) @@ [Typo: should be j++ not i++. Also, bound should be G.vexnum, not G.arcnum.]
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
    int i,head = 0,tail = i,tmp; @@ [Variable 'i' is uninitialized here, so 'tail = i' results in undefined behavior. It should be 'tail = 1' or 'tail = head + 1'. This causes the BFS queue to start with an invalid tail, leading to incorrect traversal order. In the test case, this causes BFS before deletion to output "0 2 1" instead of "0 1 2".]
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