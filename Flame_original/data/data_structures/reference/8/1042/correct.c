#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAXSIZE 1000
#define MaxV 200        //最大顶点个数
typedef struct edge{
    int adjvex;         //adjvex 域存放以第i个顶点为出发点的一条边的另一端点在头结点数组中的位置。
    int weight;         //weight 域为权值域(若图不带权,则无此域);
    struct edge *next;
}ELink;                 //边节点
typedef struct ver{
    int vertex;         //vertex 域存放某个顶点的数据信息;
    ELink *link;
}VLink;                 //顶点节点
VLink G[MaxV];
int edgeNum,pointNum;
void createGraph(VLink []);
ELink *insertEdge(ELink *,int );
int Visited[MaxV]={0};     //标识顶点是否被访问过，N为顶点数；
void travelDFS(VLink [],int ,int );//深度优先遍历, 第三个变量为删除的点
void DFS(VLink [],int );
void  travelBFS(VLink [], int ,int );//广度优先遍历
void BFS(VLink [],int );
//队列操作
int Q[MAXSIZE];
int Front,Rear,Count;
void initQueue();
int isEmpty();
int isFull();
void enQueue(int *,int );
int deQueue(int []);

int main()
{
    initQueue();
    createGraph(G);
    travelDFS(G,pointNum,-1);//-1表示不删除顶点
    travelBFS(G,pointNum,-1);
    int del;
    scanf("%d",&del);
    travelDFS(G,pointNum,del);
    travelBFS(G,pointNum,del);
    return 0;
}

ELink *insertEdge(ELink *head,int avex)
{
    ELink *e,*p,*q=NULL;
    e=(ELink *)malloc(sizeof(ELink));
    e->adjvex=avex;
    e->weight=1;
    e->next=NULL;
    if(head==NULL) {head=e; return head;}
    for(p=head;p!=NULL&&avex>p->adjvex;q=p,p=p->next);
    if(p==head){
        e->next=p;
        return e;
    }
    else{
        q->next=e;
        e->next=p;
        return head;
    }
}
void createGraph(VLink graph[])
{
    int i,v1,v2;
    scanf("%d%d",&pointNum,&edgeNum);
    for(i=0;i<edgeNum;i++)
    {
        scanf("%d%d",&v1,&v2);
        graph[v1].link=insertEdge(graph[v1].link,v2);
        graph[v2].link=insertEdge(graph[v2].link,v1);
    }
}
void travelDFS(VLink G[],int n,int del)
{
    int i;
    for(i=0;i<n;i++)    Visited[i]=0;
    if(del>=0)//不是-1的话删除掉del(即标记为遍历过)
        Visited[del]=1;
    for(i=0;i<n;i++)
        if(!Visited[i]) DFS(G,i);
        printf("\n");
}
void DFS(VLink G[],int v)
{
    ELink *p;
    Visited[v]=1;//标识顶点被访问过
    printf("%d ",v);//访问顶点
    for(p=G[v].link;p!=NULL;p=p->next)
        if(!Visited[p->adjvex])
            DFS(G,p->adjvex);
}
void  travelBFS(VLink  G[], int n,int del)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    if(del>=0)//置1删除
        Visited[del]=1;
    for(i=0; i<n; i++)
        if( !Visited[i] ) BFS(G, i);
    printf("\n");
}
void BFS(VLink  G[], int v)
{
    ELink  *p;
    initQueue();
    Visited[v] = 1; //标识某顶点已入队
    enQueue(Q, v);
    while( !isEmpty()){
         v = deQueue(Q);  //取出队头元素
        printf("%d ",v); //访问当前顶点
         for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
             if( !Visited[p->adjvex] ) {
                    Visited[p->adjvex] = 1; //标识某顶点入队
                    enQueue(Q, p->adjvex);
           }
     }
}
//队列操作
void initQueue()
{
    Front=0;
    Rear=MAXSIZE-1;
    Count=0;
}
int deQueue(int queue[])
{
    int e;
    if(isEmpty())
        printf("Empty queue!");
    else{
        e=queue[Front];
        Count--;
        Front=(Front+1)%MAXSIZE;
        return e;
    }
    return 0;
}
int isEmpty()
{
    return Count == 0;
}
int isFull()
{
    return Count==MAXSIZE;
}
void enQueue(int *queue,int item)
{
    if(isFull())   
        printf("Fill queue");
    else
    {
        Rear=(Rear+1)%MAXSIZE;
        queue[Rear]=item;
        Count++;
    }
}

