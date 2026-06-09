#include <stdio.h>
#include <stdlib.h>
//#include <stdlib.h>
int tcc=0;
void cheat()
{
    tcc++;
    int i=0;
    i=rand();
    if(i==1234)return;
    cheat();
}
//图的邻接表定义
#define MaxV 256
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

int main(int argc, const char * argv[]) {
    cheat();
    scanf("%d %d",&V,&E); //输入图的顶点(vertex)个数和边(edge)的个数
    
    createGraph(G);//建立无向图，⚠️需要排序！
    
    travelDFS(G,V,-1);//-1表示不删除顶点
    travelBFS(G,V,-1);
    
    int k;
    scanf("%d",&k);//输入要删除的顶点编号
    
    travelDFS(G,V,k);//删除k顶点，采用懒惰删除，即置Visted[k]=1
    travelBFS(G,V,k);
    
    return 0;
}

//ELink  *insertEdge(ELink *head, int avex)
//{
//    ELink *e,*p;
//    e =(ELink *)malloc(sizeof(ELink));
//    e->adj= avex; e->wei=1; e->next = NULL;
//    if(head == NULL)  { head=e; return head; }
//    for(p=head; p->next != NULL; p=p->next)
//        ;
//    p->next = e;
//    return head;
//}

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
void DFS(VLink  G[ ], int v)
{
    ELink  *p;
    Visited[v] = 1; //标识某顶点被访问过
    printf("%d ", v);
    //VISIT(G, v); //访问某顶点
    for(p = G[v].link; p !=NULL;  p=p->next)
        if( !Visited[p->adj] )
            DFS(G, p->adj);
}

void  travelDFS(VLink  G[ ], int n, int delV)
{
    int i;
    for(i=0; i<n; i++)
        Visited[i] = 0 ;
    if(delV >= 0)  //处理删除
        Visited[delV] = 1;
    for(i=0; i<n; i++)
        if( !Visited[i] ) DFS(G, i);
    printf("\n");
}


/* 广度优先遍历 */

//循环队列
#define MAXSIZE     1000
int  Q[MAXSIZE];
int  Front, Rear,Count;
void  initQueue(void)
{
    Front = 0;
    Rear = MAXSIZE-1;
    Count = 0;
}
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
        printf("Full queue!");
    else{                              /* 队未满，插入成功 */
        Rear = (Rear+1) % MAXSIZE;
        queue[Rear]=item;
        Count++;
    }
}
int  deQueue(int queue[ ])
{
    int e;
    if(isEmpty())                    /* 队空，删除失败 */
        printf("Empty queue!");
    else{                            /* 队非空，删除成功 */
        e=queue[Front];
        Count--;
        Front = (Front+1) % MAXSIZE;
        return e;
    }
    return 0;
}


void BFS(VLink  G[ ], int v)
{
    ELink  *p;
    initQueue();  //初始化队
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
    printf("\n"); // @@ [The BFS and DFS traversal functions iterate over all vertices from 0 to n-1 and start a new traversal from any unvisited vertex. However, the problem states that the graph remains connected after deletion and traversal must always start from vertex 0. The current implementation may start additional traversals from other unvisited vertices if the graph were disconnected, but more critically, after marking the deleted vertex as visited, the loop in travelDFS and travelBFS still attempts to start DFS/BFS from every unvisited vertex—including those that are not reachable from 0 if the graph were disconnected. However, the real issue here is that the problem requires traversal to start ONLY from vertex 0, not from every unvisited vertex. Thus, the for-loop in both travelDFS and travelBFS should only call DFS/BFS on vertex 0, not iterate through all vertices. This causes incorrect output when the deleted vertex disconnects parts of the graph (though the problem states it remains connected), but more importantly, violates the requirement to start only from 0. In the test case, after deleting vertex 1, the code correctly marks it as visited, but then the loop in travelDFS starts at i=0 (which is unvisited) and calls DFS(0), which prints "0 2". Then i=1 is skipped (visited), and i=2 is already visited by the DFS from 0, so it works. However, the logic is flawed because it's designed for disconnected graphs, but the problem says the graph is connected. The actual runtime error likely comes from the recursive DFS causing a stack overflow due to infinite recursion in some cases, but in this test case, the output matches expected. However, looking closer: the real bug is that the insertEdge function does NOT maintain ascending order correctly when inserting equal elements or when inserting at the end. Specifically, the loop condition `p != NULL && avex > p->adj` stops when avex <= p->adj. But if avex equals an existing adj, it will insert before it, causing duplicates? No, edges are not repeated per problem. But more critically, when avex is larger than all existing, p becomes NULL, q points to last node, and we do q->next = e, which is correct. However, there's a subtle bug: the loop condition updates q = p only when the loop body executes. But in the for loop: `for(p=head; p != NULL && avex > p->adj;  q = p, p = p->next)` — the increment part `q = p, p = p->next` only runs if the condition is true. So when avex <= p->adj, the loop exits without updating q. That is correct. But what if we need to insert at the end? Example: head = [1->2], insert 3. Loop: p=1, 3>1 → q=1, p=2; 3>2 → q=2, p=NULL; exit. Then since p != head, we do q->next = e → 2->3. Correct. Now insert 0 into [1->2]: p=1, 0>1 false → exit. p==head → insert at front. Correct. Insert 1.5? Not integer. But what about inserting duplicate? Problem says no repeated edges. So insertEdge seems correct. Then why runtime error? Look at the BFS and DFS: they assume the graph is represented correctly. But the real issue is in the global variables: Visited array is global and reused. But that's handled by resetting in travelDFS/BFS. Another possibility: the queue in BFS is global, and initQueue sets Rear = MAXSIZE-1. Then enQueue does Rear = (Rear+1)%MAXSIZE → (999+1)%1000 = 0. That's correct. But deQueue returns 0 on empty, but the code checks isEmpty() so it shouldn't happen. However, in the test case: n=3, edges: 0-1,1-2,0-2. So adjacency lists: 
0: 1,2 → but insertEdge inserts in sorted order: for 0: first insert 1 → [1], then insert 2 → [1,2]
1: insert 0 → [0], then insert 2 → [0,2]
2: insert 1 → [1], then insert 0 → [0,1] → but wait: when inserting 0 into [1], since 0<1, it becomes head: [0,1]
So G[0].link: 1->2
G[1].link: 0->2
G[2].link: 0->1

Before deletion: DFS from 0: visit 0, then neighbors 1 and 2. Since 1<2, go to 1 first. From 1: neighbors 0 (visited), 2 (not visited) → visit 2. So DFS: 0 1 2. Correct.
BFS: 0, then enqueue 1,2. Dequeue 1: print 1, neighbors 0(visited),2(not visited) → enqueue 2. Dequeue 2: print 2. So BFS: 0 1 2. Correct.

After deletion of 1: mark Visited[1]=1.
DFS: start at i=0 (unvisited). Visit 0. Neighbors: 1 (visited), 2 (unvisited) → visit 2. From 2: neighbors 0 (visited), 1 (visited). So DFS: 0 2. Correct.
BFS: start at 0. Enqueue 0. Dequeue 0 → print 0. Neighbors: 1 (visited), 2 (unvisited) → enqueue 2. Dequeue 2 → print 2. Neighbors: 0 (visited), 1 (visited). So BFS: 0 2. Correct.

But the buggy output is blank? The problem says "Buggy Output:" is empty. So runtime error → crash.

Looking at the code: the cheat() function is recursive and calls itself indefinitely until stack overflow. Because rand() returns a value between 0 and RAND_MAX, and the chance of it being 1234 is very low, so cheat() recurses infinitely → stack overflow → runtime error.

Thus, the error is in the cheat() function causing infinite recursion.
}

// The cheat function causes infinite recursion leading to stack overflow (runtime error).
// It should be removed or fixed, but since it's part of the given code, we mark the call site.
// However, the problem says to mark the line where error occurs. The infinite recursion starts at cheat() call in main.
// But the actual problematic line is inside cheat(), specifically the recursive call without proper base case guarantee.
// Since the instruction says "if you think an error may occur on a particular line, add @@ symbol directly after that line",
// and the cheat() function is called in main, but the infinite recursion happens in cheat() itself.
// The line "cheat();" in main triggers it, but the root is the recursive call in cheat().
// However, the problem states: "add @@ symbol directly after that line" where error occurs.
// The runtime error (stack overflow) is caused by the unbounded recursion in cheat().
// The line that causes the recursion is the call to cheat() inside cheat().
// But note: the problem says "the program failed" with runtime error on the test case.
// So we mark the line in cheat() that recursively calls itself without guaranteed termination.

// However, looking at the source code provided for annotation, the cheat() function is:
// void cheat()
// {
//     tcc++;
//     int i=0;
//     i=rand();
//     if(i==1234)return;
//     cheat();   // <-- this line causes infinite recursion with high probability
// }

// So we should mark the line "cheat();" inside the cheat function.

// But the user's source code block ends with the travelBFS function, and the cheat function is defined earlier.
// We must annotate the exact line in the given source code.

// In the given source code, the cheat function is:
// void cheat()
// {
//     tcc++;
//     int i=0;
//     i=rand();
//     if(i==1234)return;
//     cheat();
// }

// So the last line of cheat() is "cheat();", which should be marked.

// However, the problem says: "do not change the original code structure, formatting, or content in any way"
// So we add @@ after the line "cheat();" inside the cheat function.

// But note: the provided source code in the query has the cheat function as:
// void cheat()
// {
//     tcc++;
//     int i=0;
//     i=rand();
//     if(i==1234)return;
//     cheat();
// }

// So we annotate that last line of the function.