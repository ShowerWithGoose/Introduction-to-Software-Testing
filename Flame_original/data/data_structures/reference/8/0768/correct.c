#include <stdio.h>
#include <stdlib.h>
#define MaxV 256
typedef struct edge
{
    int adjvex;
    int weight;
    struct edge *next;
}Elink;
typedef struct ver
{
    Elink *link;
}Vlink;
Vlink G[MaxV];
int V,E,k, Count,Visited[MaxV];
Elink  *insertEdge(Elink *head, int avex)
{
    Elink *e,*p,*q = NULL;
    e =(Elink *)malloc(sizeof(Elink)); /* 创建一个数据项为avex的新结点 */
    e->adjvex= avex; e->weight=1; e->next = NULL;
    if(head == NULL) 
    {
        head=e;return head;
    }
    for(p=head; p != NULL&&avex>p->adjvex;q=p,p=p->next) //插入
        ;
    if( p == head)
    {
        e->next = p;
        return e;
    }
    else 
    {        
        q->next = e;
        e->next = p;
        return head;
    }
}
void createGraph(Vlink graph[])
{ 
    for(int i=0;i<E;i++)
    {
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        graph[v1].link=insertEdge(graph[v1].link, v2);
        graph[v2].link=insertEdge(graph[v2].link, v1);
    }
}
void DFS(Vlink  G[ ], int v)
{
    Elink  *p;
    Visited[v] = 1; //标识某顶点被访问过
    printf("%d ",v);//VISIT(G, v); //访问某顶点
    for(p = G[v].link; p !=NULL;  p=p->next)
        if( !Visited[p->adjvex] )
            DFS(G, p->adjvex);
}
void  travelDFS(Vlink  G[ ], int n, int delV)
{
    int i;
    for(i=0; i<n; i++) Visited[i] = 0 ;
    if(delV >= 0)  //处理删除
        Visited[delV] = 1;
    for(i=0; i<n; i++)
        if( !Visited[i] ) DFS(G, i);
    puts("");
}
/* 广度优先遍历 */
//循环队列
#define MAXSIZE 1024
int  Q[MAXSIZE];
int  Front, Rear,Count;
int  isEmpty(void)
{
    return Count == 0;
}
int  isFull(void)
{
    return Count == MAXSIZE;
}
void enQueue(int queue[ ], int item)
{
    if(isFull())                       /* 队满，插入失败 */
        printf("error:Full queue!");
    else
    {   
        Count++;                          /* 队未满，插入成功 */
        Rear = (Rear+1) % MAXSIZE;
        queue[Rear]=item;
    }
}
int  deQueue(int queue[ ])
{
    int e;
    if(isEmpty())                    /* 队空，删除失败 */
        printf("error:Empty queue!");
    else
    {                            /* 队非空，删除成功 */
        e=queue[Front];
        Count--;
        Front = (Front+1) % MAXSIZE;
        return e;
    }
    return 0;
}
void BFS(Vlink  G[ ], int v)
{
    Elink *p;
    Front = 0;
    Rear = MAXSIZE-1;
    Count = 0;
    Visited[v] = 1; //标识某顶点已入队
    enQueue(Q, v);
    while( !isEmpty()){
        v = deQueue(Q);  //取出队头元素
        printf("%d ",v);
        //VISIT(G, v); //访问当前顶点
        for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
            if( !Visited[p->adjvex] ) {
                Visited[p->adjvex] = 1; //标识某顶点入队
                enQueue(Q, p->adjvex);
            }
    }
}
void  travelBFS(Vlink  G[ ], int n, int delV)
{
    int i;
    for(i=0; i<n; i++)
        Visited[i] = 0 ;
    if(delV >= 0)  //处理删除
        Visited[delV] = 1;
    for(i=0; i<n; i++)
        if( !Visited[i] )
            BFS(G, i);
    puts("");
}
int main() 
{
    scanf("%d %d",&V,&E); //输入图的顶点(vertex)个数和边(edge)的个数    
    createGraph(G);//建立无向图
    travelDFS(G,V,-1);//-1表示不删除顶点
    travelBFS(G,V,-1);
    scanf("%d",&k);//输入要删除的顶点编号
    travelDFS(G,V,k);//删除k顶点，置Visted[k]=1
    travelBFS(G,V,k);
    return 0;
}
