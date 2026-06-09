#include <stdio.h>
#include <stdlib.h>

//图的邻接表定义
#define MaxV 256
//循环队列
#define MAXSIZE    100
int  Q[MAXSIZE];
int  Front=0, Rear=MAXSIZE-1,Count=0;
typedef struct edge{
    int  adj;
    int  wei;
    struct edge  *next;
} ELink;

typedef struct ver{
    ELink  *link;
} VLink;
VLink  G[MaxV];

int V, E; //顶点(vertex)数，边(edge)数

void createGraph(VLink graph[]);

void  travelDFS(VLink  G[ ], int n, int delV);
void  travelBFS(VLink  G[ ], int n, int delV);

int main() {
    int k;
    scanf("%d %d",&V,&E); //输入图的顶点(vertex)个数和边(edge)的个数
    createGraph(G);//建立无向图，需要排序！
    travelDFS(G,V,-1);//-1表示不删除顶点 @@ [The original call used 0 instead of -1, which incorrectly marks vertex 0 as deleted during the "before deletion" traversal. According to problem, deletion vertex is not 0 and before deletion should traverse full graph starting at 0. Using 0 here causes Visited[0]=1 in travelDFS due to condition 'if(delV > 0)' being false but later logic mishandles it. However, the real issue is that the first two calls should pass -1 (as in reference) to indicate no deletion, but code passes 0.]
    travelBFS(G,V,-1); // @@ [Same error: should pass -1 for "before deletion", but passed 0, causing incorrect behavior if delV=0 were interpreted as delete vertex 0, but problem states deleted vertex is not 0. However, in travelDFS, condition is 'if(delV > 0)', so passing 0 skips marking any vertex as deleted — which accidentally works for BFS because its condition is 'if(delV >= 0)'. But inconsistency leads to mismatched logic. The core bug is that both initial traversals must simulate no deletion, so delV should be -1 (as in reference). Passing 0 to travelDFS does NOT mark any vertex as deleted (since 0>0 is false), so DFS works by accident. But for BFS, passing 0 causes 'if(delV >=0)' to be true, so Visited[0]=1, which prevents traversal from starting at 0 — this explains why BFS before deletion outputs "1 2" instead of "0 1 2".]
    scanf("%d",&k);//输入要删除的顶点编号
    travelDFS(G,V,k);//删除k顶点，采用懒惰删除，即置Visted[k]=1
    travelBFS(G,V,k);
    return 0;
}
/* 设head是一个有序增序链表，将元素avex插入到相应位置上 */
ELink  *insertEdge(ELink *head, int avex)
{
    ELink *e,*p,*q = NULL;
    e =(ELink *)malloc(sizeof(ELink)); /* 创建一个数据项为avex的新结点 */
    e->adj= avex; e->wei=1; e->next = NULL;
    if(head == NULL)  /* head是一个空表 */
        return e;
    for(p=head; p != NULL && avex > p->adj;  q = p, p = p->next) /* 找到插入位置 */
        ;
    if( p == head){  /* 在头结点前插入 */
        e->next = p;
        return e;
    }
    else {           /* 在结点p前插入一个结点 */
        q->next = e;
        e->next = p;
        return head;
    }
}

void createGraph(VLink graph[])
{
    for(int i=0;i<E;i++)
    {
        int v1,v2;
        scanf("%d %d",&v1,&v2);
        graph[v1].link=insertEdge(graph[v1].link, v2);
        graph[v2].link=insertEdge(graph[v2].link, v1);
    }
}


int Visited[MaxV]={0}; //标识顶点是否被访问过，N为顶点数

/* 深度优先遍历 */
void DFS(VLink  Gin[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; //标识某顶点被访问过
    printf("%d ", v);
    //VISIT(G, v); //访问某顶点
    for(p = G[v].link; p !=NULL;  p=p->next)
        if( !Visited[p->adj] )
            DFS(Gin, p->adj);
}

void  travelDFS(VLink  Gin[ ], int n, int delV)
{
    int i;
    for(i=0; i<n; i++)
        Visited[i] = 0 ;
    if(delV > 0)  //处理删除 @@ [This condition should be 'if(delV >= 0)' to match the BFS function and correctly handle deletion when delV is non-negative. In the test case, delV=1, so it works, but when delV=0 (which shouldn't happen per problem), it would fail. However, the main issue is in the initial call: passing 0 as delV here does NOT mark vertex 0 as deleted (since 0>0 is false), so DFS before deletion works correctly by accident. But the inconsistency with BFS causes the real bug.]
        Visited[delV] = 1;
    for(i=0; i<n; i++)
        if( Visited[i]==0 ) DFS(Gin, i);
    printf("\n");
}


/* 广度优先遍历 */



int  isEmpty()
{
    return Count == 0;
}
int  isFull()
{
    return Count == MAXSIZE;
}
void enQueue(int queue[], int item)
{
    if(isFull()==1)                       /* 队满，插入失败 */
        printf("Full queue!");
    else{                              /* 队未满，插入成功 */
        Rear = (Rear+1) % MAXSIZE;
        queue[Rear]=item;
        Count++;
    }
}
int  deQueue(int Queue[ ])
{
    int e;
    if(isEmpty())                    /* 队空，删除失败 */
        printf("Empty queue!");
    else{                            /* 队非空，删除成功 */
        e=Queue[Front];
        Count--;
        Front = (Front+1) % MAXSIZE;
        return e;
    }
    return 0;
}


void BFS(VLink  G[ ], int v)
{
    ELink  *p;
    Front=0,Rear=MAXSIZE-1,Count=0; //初始化队
    Visited[v] = 1; //标识某顶点已入队
    enQueue(Q, v);
    while( !isEmpty()){
        v = deQueue(Q);  //取出队头元素
        printf("%d ",v);
        //VISIT(G, v); //访问当前顶点
        for(p=G[v].link; p!=NULL; p=p->next ) //访问该顶点的每个邻接顶点
            if( !Visited[p->adj] ) {
                Visited[p->adj] = 1; //标识某顶点入队
                enQueue(Q, p->adj);
            }
    }
}

void  travelBFS(VLink  G[ ], int n, int delV)
{
    int i;
    for(i=0; i<n; i++)
        Visited[i] = 0 ;
    if(delV >= 0)  //处理删除
        Visited[delV] = 1;
    for(i=0; i<n; i++)
        if( !Visited[i] )
            BFS(G, i);
    printf("\n");
}