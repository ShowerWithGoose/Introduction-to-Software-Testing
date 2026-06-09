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
    delete (G, c); // @@ [Using 'delete' as a function name causes a compilation error in C++ mode or with certain compilers because 'delete' is a reserved keyword in C++. Even though this is C code, some compilers may still flag it as an error or warning.]
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
    visit(G,v);
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
void delete(Vlink G[], int c)//删除某节点信息 // @@ [Using 'delete' as a function name causes a compilation error in C++ mode or with certain compilers because 'delete' is a reserved keyword in C++. Even though this is C code, some compilers may still flag it as an error or warning.]
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
            G[c].link = NULL;
        }
    }
}
void visit(Vlink G[],int c)
{
        printf("%d ", c);
}