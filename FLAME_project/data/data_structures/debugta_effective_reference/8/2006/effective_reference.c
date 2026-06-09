#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXSIZE 10000
typedef int ElemType;      //(int)依条件替换
ElemType queue[MAXSIZE];
int Front=0, Rear=MAXSIZE-1,Count=0;
//Front 队头；Rear 队尾；Count 队长度

#define MaxV 120
typedef int vertype;
typedef struct edge
{
    int adjvex;
    int weight;
    struct edge *next;
} Elink, *Elinkptr;
typedef struct ver
{
    vertype vertex;
    Elink *link;
} Vlink, *Vlinkptr;
Vlink G[MaxV];
int Visited[MaxV]={0}; //标识顶点是否被访问过，N为顶点数

int isEmpty()
{
    return Count == 0;
}
void enQueue(ElemType queue[], ElemType item) //进队
{
    if(Count == MAXSIZE)
        printf("Full queue!"); /* 队满，插入失败 */
    else
    {
        Rear = (Rear+1) % MAXSIZE;
        queue[Rear]=item;
        Count++;
        /* 队未满，插入成功 */
    }
}
ElemType deQueue(ElemType queue[]) //出队
{
    ElemType e;
    if(Count == 0)
        printf("Empty queue!");  /* 队空，删除失败 */
    else
    {
        e=queue[Front];
        Count--;    /* 队非空，删除成功 */
        Front = (Front+1) % MAXSIZE;
        return e;
    }
}

Elinkptr insertEdge(Elinkptr head, int avex)
{
    Elinkptr e,lp,p,nextp;
    e=(Elinkptr)malloc(sizeof(Elink));
    e->adjvex=avex;
    e->weight=1;
    e->next=NULL;
    if(head==NULL)
        head=e;
    else
    {

        for(p=head;p!=NULL;lp=p,p=p->next)
        {
            if(avex < p->adjvex)
            {
                nextp=(Elinkptr)malloc(sizeof(Elink));
                *nextp=*p;
                *p = *e;
                p->next=nextp;
                free(e);
                break;
            }
        }
        if(p==NULL)
            lp->next=e;
    }
    return head;
}

void VISIT(Vlink G[],int n)
{
    if(G[n].vertex!=-1)
        printf("%d ",G[n].vertex);
}

void DFS(Vlink G[], int v)
{
    Elink *p; //Elink是结点邻接链表
    Visited[v] = 1; //标识某顶点被访问过
    VISIT(G,v); //访问某顶点
    for(p = G[v].link; p !=NULL;  p=p->next)
        if( !Visited[p->adjvex] ) //asjvex是每个结点的编号
            DFS(G, p->adjvex);
}
void travelDFS(Vlink G[], int n, int v) //Vlink是全部结点的数组
{
    int i;
    for(i=0; i<n; i++)
        if(i!=v)
            Visited[i] = 0 ;
        else
            Visited[i] = 1 ;
    for(i=0; i<n; i++)
    if( !Visited[i] ) DFS(G, i);
    printf("\n");
}


void BFS(Vlink G[], int v)
{
    Elink *p;
    Visited[v] = 1; //标识某顶点已入队
    enQueue(queue, v);
    while(!isEmpty())
    {
        v = deQueue(queue);  //取出队头元素
        VISIT(G, v); //访问当前顶点
        for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
        if( !Visited[p->adjvex] ) 
        {
            Visited[p->adjvex] = 1; //标识某顶点入队
            enQueue(queue, p->adjvex);
        }
    }
}
void travelBFS(Vlink G[ ], int n, int v)
{
    int i;
    for(i=0; i<n; i++)
        if(i!=v)
            Visited[i] = 0 ;
        else
            Visited[i] = 1 ;
    for(i=0; i<n; i++)
        if( !Visited[i] ) BFS(G, i);
    printf("\n");
}


void deleteVex(Vlink G[], int n, int v)
{
    int i;
    Elinkptr p,nextp=NULL;
    G[v].vertex=-1;
    for(i=0; i<n; i++)
    {
        if(i!=v)
            for(p=G[i].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
                if( p->adjvex==v )
                {
                    nextp=p->next;
                    *p = *nextp;
                    free(nextp);
                    break;
                }
    }
}

int main()
{
    int n=0,m=0,a,b,c;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&a,&b);
        G[a].vertex=a;
        G[b].vertex=b;
        G[a].link=insertEdge(G[a].link,b);
        G[b].link=insertEdge(G[b].link,a);
    }
    scanf("%d",&c);
    travelDFS(G,n,-1);
    travelBFS(G,n,-1);
    //deleteVex(G,node_num,del_data);
    travelDFS(G,n,c);
    travelBFS(G,n,c);
}
