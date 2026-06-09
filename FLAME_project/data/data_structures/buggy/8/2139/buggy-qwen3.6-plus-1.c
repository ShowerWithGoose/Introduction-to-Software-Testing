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
    travelDFS(G,V,-1);// @@ The problem states that traversal starts from vertex 0 and the deleted vertex is not 0. Passing 0 here incorrectly marks vertex 0 as "deleted" or visited in the logic below if interpreted as a deletion flag, or simply fails to match the reference implementation which uses -1 for "no deletion". The reference code uses -1. The buggy code passes 0. If delV=0, travelDFS sets Visited[0]=1 (if condition was >=0) or skips it. Let's look at travelDFS.
    travelBFS(G,V,-1); // @@ Same as above, should be -1 to indicate no vertex deletion.
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
    if(delV > 0)  // @@ The condition should be delV >= 0. The problem states the vertex to be deleted is not 0, but the function is also called with -1 for "no deletion". If delV is -1, we don't want to mark anything. If delV is a valid vertex (>=0), we mark it. The current code `delV > 0` fails to mark vertex 0 if it were ever passed (though problem says delV != 0), but more importantly, in the first call from main, we passed 0 (buggy) or -1 (correct). If we pass -1, `delV > 0` is false, so nothing is marked, which is correct for "no deletion". However, looking at the reference code, it uses `if(delV >= 0)`. The critical error here is actually in `main` passing 0 instead of -1. But wait, if `main` passes -1, `delV > 0` is false, so `Visited` remains all 0. Then the loop `for(i=0...` starts DFS at 0. This seems correct for "no deletion".
    // HOWEVER, let's look at the BFS part.
    // Let's re-read the bug. The buggy output for the first DFS is `0 1 2`. The expected is `0 1 2`.
    // The buggy output for the first BFS is `1 2`. The expected is `0 1 2`.
    // Why did BFS skip 0?
    // In `travelBFS`, `if(delV >= 0) Visited[delV] = 1;`.
    // In `main`, `travelBFS(G,V,0)` was called. So `delV` is 0.
    // `0 >= 0` is true. So `Visited[0] = 1`.
    // Then the loop `for(i=0...` checks `!Visited[i]`. `Visited[0]` is 1, so it skips 0.
    // It starts BFS at 1. Hence output `1 2`.
    // So the primary error is in `main` passing `0` instead of `-1`.
    // Is there an error in `travelDFS`?
    // In `main`, `travelDFS(G,V,0)` was called. `delV` is 0.
    // `if(delV > 0)` is false. So `Visited[0]` remains 0.
    // Loop starts at 0. DFS visits 0. Output `0 1 2`. This matches expected.
    // So `travelDFS` logic `delV > 0` accidentally worked for the case where `delV=0` was passed but shouldn't have been deleted, because it didn't delete it. But it's semantically wrong if we intended to delete vertex 0 (which we don't).
    // But for the second part, `travelDFS(G,V,k)` where k=1. `delV=1`. `1>0` is true. `Visited[1]=1`. Correct.
    // So `travelDFS` works correctly for the test case despite the weird condition, ONLY BECAUSE the first call passed 0 (which shouldn't be deleted) and the condition `>0` spared it.
    // The BFS function `travelBFS` uses `>=0`.
    // In `main`, `travelBFS(G,V,0)` was called. `delV=0`. `0>=0` is true. `Visited[0]=1`. This caused the error.
    // So the fix is in `main` to pass -1.
    
    // Let's check if there are other errors.
    // The prompt asks to identify location of errors.
    // Error 1: main passes 0 instead of -1.
    
    // Let's look at `travelDFS` again.
    // Reference: `if(delV >= 0) Visited[delV]=1;`
    // Buggy: `if(delV > 0) Visited[delV]=1;`
    // If the input asked to delete vertex 0 (problem says it won't), this would fail.
    // But since problem says delV != 0, `delV` is always >= 1 when deleting.
    // So `delV > 0` is equivalent to `delV >= 0` for valid deletion inputs.
    // However, for the "no deletion" case, we pass -1.
    // `delV > 0` (-1 > 0) is false. Correct.
    // `delV >= 0` (-1 >= 0) is false. Correct.
    // So `travelDFS` logic is technically safe for the given constraints, although inconsistent with BFS.
    
    // The main error is definitely in `main`.
    
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