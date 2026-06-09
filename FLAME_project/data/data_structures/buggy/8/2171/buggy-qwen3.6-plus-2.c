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
    scanf("%d",&del);
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
    for(int i = 0;i < G.arcnum;i++)
    {
        for(int j = 0;j < G.arcnum;i++) // @@ The loop variable 'i' is incremented instead of 'j', causing an infinite loop or out-of-bounds access. It should be 'j++'. Also, the initialization logic is flawed as it uses arcnum for matrix dimensions and sets values to MAXINT instead of 0, but since this function is never called in main, it doesn't affect the current output. However, if it were called, it would be erroneous.
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
    int i,head = 0,tail = i,tmp; // @@ 'tail' is initialized with uninitialized variable 'i'. It should be initialized to 1 (since head=0 and we just added one element) or 0 depending on logic. Given head=0 and que[head]=v, tail should be 1.
    que[head] = v;
    while(head <= tail)
    {
        tmp = que[head];
        head++;
        if(visit[tmp] == 1) // @@ The condition checks if visited *after* dequeuing. In the reference correct code, BFS marks visited when printing/processing. Here, if a node is added to the queue multiple times (which can happen if not checked before enqueue), it might be processed incorrectly. However, the main issue is that neighbors are added to the queue without checking if they are already in the queue or visited, relying on the check here. But crucially, the initial 'tail' initialization error causes undefined behavior.
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