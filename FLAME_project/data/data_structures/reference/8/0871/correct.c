#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef char ElemType;
struct graph
{
    int vexnum;//顶点数
    int arcnum;//边数
    int vex[MAX];//存放顶点信息
    int arc[MAX][MAX];//存放边的信息
}picture,*P;
int m;
int sign=1;
int queue[MAX];
int visited[MAX];//顶点的访问标记数组
void CreGraph(struct graph *p,int n,int e);//建立一个图
void DFS(struct graph *q,int a);//从顶点a出发，深度遍历图q
void DFSGraph(struct graph *q);//深度优先
void BFS(struct graph *q,int b);//从顶点b出发，广度遍历图q
void BFSGraph(struct graph *q);//广度优先
int main()
{
    int i,j,k;
    P=&picture;
    scanf("%d%d",&picture.vexnum,&picture.arcnum);
    CreGraph(P,picture.vexnum,picture.arcnum);
    DFSGraph(P);
    printf("\n");
    memset(visited,0,sizeof(visited));
    BFSGraph(P);
    printf("\n");
    memset(visited,0,sizeof(visited));
    for(i=0;i<picture.arcnum;i++)
    {
        P->arc[i][m]=0;
        P->arc[m][i]=0;
        sign=0;
    }
    DFSGraph(P);
    printf("\n");
    memset(visited,0,sizeof(visited));
    BFSGraph(P);
    printf("\n");
    return 0;
}
void CreGraph(struct graph *p,int n,int e)
{
    int i,j,t;
    for(i=0;i<p->vexnum;i++)
    	p->vex[i]=i;
    for(t=0;t<p->vexnum;t++)
        for(i=0;i<p->vexnum;i++)
            p->arc[t][i]=0;
    for(j=0;j<e;j++)
        {
            scanf("%d%d",&t,&i);
            p->arc[i][t]=1;
            p->arc[t][i]=1;
        }
    scanf("%d",&m);//删除结点
}
void DFS(struct graph *q,int a)
{
    int i;
    if(sign!=0)
    printf("%d ",q->vex[a]);
    else if(q->vex[a]!=m)
    printf("%d ",q->vex[a]);
    visited[a]=1;
    for(i=0;i<q->vexnum;i++)
        if(!visited[i]&&q->arc[a][i])
        DFS(q,i);
}
void DFSGraph(struct graph *q)
{
    int i;
    for(i=0;i<q->vexnum;i++)
        if(!visited[i]) DFS(q,i);
}
void BFS(struct graph *q,int b)
{
	int front,rear,i;
	front=rear=0;
	if(sign!=0)
    printf("%d ",q->vex[b]);
    else if(q->vex[b]!=m)
    printf("%d ",q->vex[b]);
    visited[b]=1;
    queue[rear++]=b;
    while(front!=rear)
    {
        b=queue[front++];
        for(i=0;i<q->vexnum;i++)
            if(q->arc[b][i]&&!visited[i])
                {
                    printf("%d ",q->vex[i]);
                    visited[i]=1;
                    queue[rear++]=i;
                }
    }
}
void BFSGraph(struct graph *q)
{
	int i;
    for(i=0;i<q->vexnum;i++)
    if(!visited[i]) BFS(q,i);
}



