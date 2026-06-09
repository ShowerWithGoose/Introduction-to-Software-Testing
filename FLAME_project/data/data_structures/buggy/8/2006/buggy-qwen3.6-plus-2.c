#include <stdio.h>
#include <string.h>//原来构图得到的链表还要排序。。
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define MaxV 256
#define MAXSIZE 256
#define N 1000
typedef int ElemType;
typedef struct edge
{
    int adjvex;
    struct edge *next;
} Elink;
typedef struct ver
{
    Elink *link;
} Vlink;
Vlink G[MaxV]={0};
int Visited[N] = {0}; // 标识顶点是否被访问过
                      //  N为顶点个数
ElemType Q[MAXSIZE];
int Front, Rear, Count;

void setedge(Vlink G[], int a, int b);
void travelBFS(Vlink G[], int n);
void BFS(Vlink G[], int v);
void enQueue(ElemType queue[], ElemType item);
void travelDFS(Vlink G[], int n);
void DFS(Vlink G[], int v);
ElemType deQueue(ElemType queue[]);
int isEmpty();
int isFull();
void delete(Vlink G[], int c);
void visit(Vlink G[], int c);
Elink *insertEdge(Elink *head, int avex);
int main()
{
    int m, n;
    int a, b, c;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);//无向图设置两条边
        G[a].link = insertEdge(G[a].link, b);
        G[b].link = insertEdge(G[b].link, a);
    }
    travelDFS(G, n);
    printf("\n");
    travelBFS(G, n);
    printf("\n");

    scanf("%d", &c);
    delete (G, c);
    travelDFS(G, n);
    printf("\n");
    travelBFS(G, n);
    printf("\n");

    return 0;
}

Elink *insertEdge(Elink *head, int avex)
{
    Elink *e, *p, *q = NULL;
    e = (Elink *)malloc(sizeof(Elink)); /* 创建一个数据项为avex的新结点 */
    e->adjvex = avex;
    e->next = NULL;
    if (head == NULL) /* head是一个空表 */
        return e;
    for (p = head; p != NULL && avex > p->adjvex; q = p, p = p->next) /* 找到插入位置 */
        ;
    if (p == head)
    { /* 在头结点前插入 */
        e->next = p;
        return e;
    }
    else
    { /* 在结点p前插入一个结点 */
        q->next = e;
        e->next = p;
        return head;
    }
}

void setedge(Vlink G[],int a,int b)//设置边函数,a为顶点一，b为顶点二
{
    Elink *p, *q; // 无向图，要设置两个点相互联通
    q = (Elink *)malloc(sizeof(Elink));
    q = G[a].link;
    p = (Elink *)malloc(sizeof(Elink));
    p->adjvex = b;
    p->next = NULL;
    if(G[a].link!=NULL)//若该点已有边连接
    {
        for (; q->next != NULL&&q->next->adjvex<b ;q=q->next);//找到尾结点
        if(q->next!=NULL)
        {
            Elink *r=q->next;
            q->next = p;
            p->next = r;
        }
        else
        q->next = p;
    }
    else
    {
        G[a].link = p;
    }
}
void travelBFS(Vlink G[], int n) // 广度优先遍历算法
{
    int i;
    for (i = 0; i < n; i++)
        {
            Visited[i] = 0;
        }
        memset(Q, 0, sizeof(Q));//重置Q队列
        BFS(G, 0);
}

void BFS(Vlink G[], int v)
{
    Elink *p;
    visit(G,v); // @@ The visit should happen when dequeuing, not when starting/enqueuing, to match standard BFS output order and avoid printing deleted/unreachable nodes incorrectly if logic changes. However, the main issue here is that `visit` is called on `v` (start node) immediately. In standard BFS, we mark visited and enqueue. Then we dequeue and visit. If we visit here, the start node is printed. Then inside loop, we dequeue `v` (which is start node again if it was enqueued) or next. Wait, `enQueue(Q, v)` happens after `visit`. So Start Node is printed. Then Enqueued. Loop starts. Dequeue Start Node. Then iterate neighbors. Neighbors are visited and enqueued. This results in Start Node being printed once. This part is actually logically okay for traversal order IF the queue logic is correct. BUT, look at `travelBFS`. It calls `BFS(G, 0)`. Inside `BFS`, `visit(G, 0)` prints 0. `Visited[0]=1`. `enQueue(Q, 0)`. Loop: `v = deQueue(Q)` -> 0. `p = G[0].link`. Iterate neighbors. If neighbor not visited, `visit(neighbor)`, mark visited, enqueue. This is actually a valid BFS implementation variant (print on enqueue vs print on dequeue). The problem is likely in `delete` or how isolated nodes are handled. 
    Visited[v] = 1; // 标识某顶点被访问过
    enQueue(Q, v);    // 入口的第一个顶点入队
    while (!isEmpty(Q))
    {                                   //  循环，直到队空为止
        v = deQueue(Q);                   // 取出队头元素
        p = G[v].link;                   // 获取该顶点第一个邻接顶点
        for (; p != NULL; p = p->next) // 访问该顶点下的每个邻接顶点
            if (!Visited[p->adjvex])
            {
                visit(G, p->adjvex);    // 访问当前顶点
                Visited[p->adjvex] = 1; // 标识某顶点被访问过
                enQueue(Q, p->adjvex);    // 邻接顶点依次分别入队
            }
    }
}

void enQueue(ElemType queue[], ElemType item)
{
    if (isFull()) /* 队满，插入失败 */
        printf("Full queue!");
    else
    {
        Rear = (Rear + 1) % MAXSIZE; // 计算循环队列尾部的合适的进队位置
        queue[Rear] = item;
        Count++;
        /* 队未满，插入成功 */
    }
}
void travelDFS(Vlink G[], int n) // 深度优先遍历算法
{
    int i;
    for (i = 0; i < n; i++)
        Visited[i] = 0;
    DFS(G, 0);
}

void DFS(Vlink G[], int v)
{
    Elink *p;
    Visited[v] = 1; // 标识某顶点被访问过
    visit(G,v); // 访问某顶点
    for (p = G[v].link; p != NULL; p = p->next)
        if (!Visited[p->adjvex])
            DFS(G, p->adjvex);
}
ElemType deQueue(ElemType queue[])
{
    ElemType e;
    if (isEmpty())
        printf("Empty queue!"); /* 队空，删除失败 */
    else
    {
        e = queue[Front];
        Count--;                       /* 队非空，删除成功 */
        Front = (Front + 1) % MAXSIZE; // 计算循环队列头部的合适的出队位置
        return e;
    }
}
int isEmpty()
{
    return Count == 0;
}
int isFull()
{
    return Count == MAXSIZE;
}
void delete(Vlink G[], int c)//删除某节点信息
{
    Elink *p, *q, *r,*e;//p用于遍历被删除顶点的链表，q用于遍历与被删除顶点形成边的顶点列表
    int x;
    for (p = G[c].link; p != NULL;p=p->next)
    {
        x = p->adjvex;
        q = G[x].link;
        if (q->adjvex==c)
        {
            e = q->next;
            free(q),
                G[x].link = e;
        }
        else
        {
            for (e = q->next; e->adjvex != c; q = e, e = q->next)
                ;
            r = e->next;
            free(e);
            q->next = r;
            G[c].link = NULL; // @@ This line incorrectly sets the link of the vertex being deleted (G[c]) to NULL inside the loop that processes its neighbors. While G[c] is being deleted, this assignment is redundant at best, but more importantly, it doesn't clean up G[c]'s own list properly if the loop continues, or it might interfere if logic relied on it. However, the critical error is that `G[c]`'s own adjacency list is not freed or nullified outside this specific neighbor-cleanup loop effectively for the vertex itself. But wait, `G[c].link = NULL` is executed every time a neighbor is processed in the `else` block. This is logically messy but might not cause WA directly if `G[c]` is ignored later. 
            // The real issue with WA in these problems is usually that the deleted vertex is still considered in traversal if not marked, OR the adjacency lists are not updated correctly.
            // In `travelDFS` and `travelBFS`, we start from 0. If `c` is not 0, we just traverse.
            // If `delete` removes edges TO `c`, then `c` becomes isolated (or partially connected if undirected edges aren't fully removed).
            // The code removes edges FROM neighbors TO `c`. It does NOT remove edges FROM `c` TO neighbors.
            // When `DFS` or `BFS` runs later, if it somehow reaches `c` (it shouldn't if edges to it are gone), it would traverse.
            // But since we start at 0, and edges to `c` are removed from other nodes, `c` is unreachable.
            // However, `G[c].link` still points to its original neighbors. If the traversal logic doesn't check if a node is "deleted", it might not matter if it's unreachable.
            // BUT, look at `visit`. It just prints.
            // Is there a case where `c` is visited? Only if reachable.
            // If `c` is 1, and we delete 1. Edges 0-1 and 2-1 are removed from 0's and 2's lists.
            // DFS from 0: 0 -> 2 (if 0-2 exists). 1 is not in 0's list anymore. 1 is not in 2's list anymore. So 1 is not visited. Correct.
            // Why WA?
            // Let's look at `insertEdge`. It sorts.
            // Let's look at `delete`.
            // If `q->adjvex == c`, it removes head.
            // Else, it finds `c` in list and removes it.
            // This seems correct for removing references to `c`.
            
            // Let's re-read the BFS/DFS output format. "0 1 2 ". Note the trailing space.
            // The `visit` function prints "%d ".
            // Expected output: "0 1 2". No trailing space? Or maybe newline handling?
            // The problem says "separated by spaces". Usually trailing spaces are accepted or ignored in online judges unless strictly checked.
            // However, looking at the provided "Buggy Output" vs "Expected Output":
            // Buggy: "0 1 2 \n0 1 2 \n0 2 \n0 2 \n"
            // Expected: "0 1 2\n0 1 2\n0 2\n0 2\n"
            // The difference is the trailing space before the newline.
            // The `visit` function always prints a space after the number.
            // To fix this, we need to avoid printing the trailing space.
        }
    }
}
void visit(Vlink G[],int c)
{
        printf("%d ", c); // @@ This prints a trailing space after the last vertex in the sequence, which causes a Wrong Answer if the judge expects no trailing whitespace. The traversal functions do not handle the spacing between elements vs after the last element differently.
}