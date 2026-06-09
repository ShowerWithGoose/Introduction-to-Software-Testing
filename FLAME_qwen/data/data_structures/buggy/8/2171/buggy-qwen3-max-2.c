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
        for(int j = 0;j < G.arcnum;i++) // @@ [The inner loop increments 'i' instead of 'j', causing an infinite loop or incorrect initialization. Also, the loop bounds should be based on vexnum, not arcnum.]
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
    int i,head = 0,tail = i,tmp; // @@ [Variable 'i' is uninitialized when used to initialize 'tail', leading to undefined behavior. Should initialize tail to 1 or 0 depending on queue logic.]
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