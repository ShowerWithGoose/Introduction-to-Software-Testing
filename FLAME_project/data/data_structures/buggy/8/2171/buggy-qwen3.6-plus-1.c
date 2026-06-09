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
        for(int j = 0;j < G.arcnum;i++) // @@ [Error 1: The loop variable should be 'j++' instead of 'i++', causing an infinite loop or incorrect initialization. Also, the loop bounds should likely be based on G.vexnum, not G.arcnum, to initialize the whole matrix.]
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
    int i,head = 0,tail = i,tmp; // @@ [Error 2: 'tail' is initialized with 'i', which is uninitialized at this point. It should be initialized to 1 (since head=0 and we just added one element) or 0 depending on logic, but typically tail starts at 1 after que[0]=v. Here que[head]=v happens next, so tail should start at 1.]
    que[head] = v;
    while(head <= tail)
    {
        tmp = que[head];
        head++;
        if(visit[tmp] == 1) // @@ [Error 3: The condition checks if visited == 1 to continue (skip). However, in BFS, we usually check if NOT visited to process. If it is already visited, we skip. This logic seems okay for skipping duplicates in queue, BUT look at Error 4.]
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