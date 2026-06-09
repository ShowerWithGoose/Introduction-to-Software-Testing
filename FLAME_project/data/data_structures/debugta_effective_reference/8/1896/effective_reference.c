#include "math.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include <strings.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 99 /* 存储空间初始分配量 */
#define MAXEDGE 200
#define MAXVEX 70

typedef int Status;  /* Status是函数的类型,其值是函数结果状态代码,如OK等 */
typedef int Boolean; /* Boolean是布尔类型,其值是TRUE或FALSE */

typedef char VertexType; /* 顶点类型应由用户定义 */
typedef int EdgeType;    /* 边上的权值类型应由用户定义 */

/* 邻接矩阵结构 */
typedef struct
{
    VertexType vexs[MAXVEX];      /* 顶点表 */
    EdgeType arc[MAXVEX][MAXVEX]; /* 邻接矩阵,可看作边表 */
    int numVertexes, numEdges;    /* 图中当前的顶点数和边数 */
} MGraph;

/* 邻接表结构****************** */
typedef struct EdgeNode /* 边表结点 */
{
    int adjvex;            /* 邻接点域,存储该顶点对应的下标 */
    int weight;            /* 用于存储权值,对于非网图可以不需要 */
    struct EdgeNode *next; /* 链域,指向下一个邻接点 */
} EdgeNode;

typedef struct VertexNode /* 顶点表结点 */
{
    int in;    /* 顶点入度 */
    char data; /* 顶点域,存储顶点信息 */
    int deleted;
    EdgeNode *firstedge; /* 边表头指针 */
} VertexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numVertexes, numEdges; /* 图中当前顶点数和边数 */
} graphAdjList, *GraphAdjList;
/* **************************** */

/* 用到的队列结构与函数********************************** */
/* 循环队列的顺序存储结构 */
typedef struct
{
    int data[MAXSIZE];
    int front; /* 头指针 */
    int rear;  /* 尾指针,若队列不空,指向队列尾元素的下一个位置 */
} Queue;

/* 初始化一个空队列Q */
Status InitQueue(Queue *Q)
{
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

/* 若队列Q为空队列,则返回TRUE,否则返回FALSE */
Status QueueEmpty(Queue Q)
{
    if (Q.front == Q.rear) /* 队列空的标志 */
        return TRUE;
    else
        return FALSE;
}

/* 若队列未满,则插入元素e为Q新的队尾元素 */
Status EnQueue(Queue *Q, int e)
{
    if ((Q->rear + 1) % MAXSIZE == Q->front) /* 队列满的判断 */
        return ERROR;
    Q->data[Q->rear] = e;              /* 将元素e赋值给队尾 */
    Q->rear = (Q->rear + 1) % MAXSIZE; /* rear指针向后移一位置, */
                                       /* 若到最后则转到数组头部 */
    return OK;
}

/* 若队列不空,则删除Q中队头元素,用e返回其值 */
Status DeQueue(Queue *Q, int *e)
{
    if (Q->front == Q->rear) /* 队列空的判断 */
        return ERROR;
    *e = Q->data[Q->front];              /* 将队头元素赋值给e */
    Q->front = (Q->front + 1) % MAXSIZE; /* front指针向后移一位置, */
                                         /* 若到最后则转到数组头部 */
    return OK;
}
/* ****************************************************** */
void addEdge(graphAdjList *G, int i, int j)
{
    EdgeNode *e, *p;
    e = (EdgeNode *)malloc(sizeof(EdgeNode)); /* 向内存申请空间,生成边表结点 */
    e->adjvex = j;                            /* 邻接序号为j */
    p = G->adjList[i].firstedge;
    if (!p)
    {
        // printf("firstedge %d,%d\n", i, j);
        G->adjList[i].firstedge = e;
        e->next = NULL;
    }
    else if (p->adjvex > e->adjvex)
    {
        // printf("addedfirstedge %d,%d\n", i, j);
        e->next = p;                 /* 将e的指针指向当前顶点上指向的结点 */
        G->adjList[i].firstedge = e; /* 将当前顶点的指针指向e */
    }
    else
    {
        // printf("addededge %d,%d\n", i, j);

        while (p->next)
        {
            if (p->next->adjvex > e->adjvex)
            {
                break;
            }
            else
                p = p->next;
        }

        e->next = p->next; /* 将e的指针指向当前顶点上指向的结点 */
        p->next = e;       /* 将当前顶点的指针指向e */
    }
}
/* 建立图的邻接表结构 */
void CreateALGraph(graphAdjList *G)
{
    int i, j, k;
    // printf("输入顶点数和边数:\n");
    scanf("%d%d", &(G->numVertexes), &(G->numEdges)); /* 输入顶点数和边数 */
    // for (i = 0; i < G->numVertexes; i++)           /* 读入顶点信息,建立顶点表 */
    // {
    //     getchar();
    //     scanf("%c", &G->adjList[i].data);
    //     printf("%d\n", i);              /* 输入顶点信息 */
    //     G->adjList[i].firstedge = NULL; /* 将边表置为空表 */
    // }

    for (k = 0; k < G->numEdges; k++) /* 建立边表 */
    {
        // printf("输入边(vi,vj)上的顶点序号:\n");
        scanf("%d%d", &i, &j); /* 输入边(vi,vj)上的顶点序号 */
        addEdge(G, i, j);
        addEdge(G, j, i);
    }
}
void showALGraph(graphAdjList *G)
{
    int i;
    for (i = 0; i < G->numVertexes; i++)
    {
        printf("VERTEX #%d:\n", i);
        EdgeNode *p = G->adjList[i].firstedge;
        while (p)
        {
            printf("  point to %d\n", p->adjvex);
            p = p->next;
        }
    }
}
Boolean visited[MAXSIZE]; /* 访问标志的数组 */

/* 邻接表的深度优先递归算法 */
void DFS(GraphAdjList GL, int i)
{
    if (GL->adjList[i].deleted == 1)
        return;
    EdgeNode *p;
    visited[i] = TRUE;
    printf("%d ", i); /* 打印顶点,也可以其它操作 */
    p = GL->adjList[i].firstedge;
    while (p)
    {
        if (!visited[p->adjvex])
            DFS(GL, p->adjvex); /* 对为访问的邻接顶点递归调用 */
        p = p->next;
    }
}

/* 邻接表的深度遍历操作 */
void DFSTraverse(GraphAdjList GL)
{
    int i;
    for (i = 0; i < GL->numVertexes; i++)
        visited[i] = FALSE; /* 初始所有顶点状态都是未访问过状态 */
    for (i = 0; i < GL->numVertexes; i++)
        if (!visited[i]) /* 对未访问过的顶点调用DFS,若是连通图,只会执行一次 */
        {
            DFS(GL, i);
        }
}

/* 邻接表的广度遍历算法 */
void BFSTraverse(GraphAdjList GL)
{
    int i;
    EdgeNode *p;
    Queue Q;
    for (i = 0; i < GL->numVertexes; i++)
        visited[i] = FALSE;
    InitQueue(&Q);
    for (i = 0; i < GL->numVertexes; i++)
    {
        if (!visited[i])
        {
            visited[i] = TRUE;
            if (GL->adjList[i].deleted == 0)
            {
                printf("%d ", i); /* 打印顶点,也可以其它操作 */
                EnQueue(&Q, i);
                while (!QueueEmpty(Q))
                {
                    DeQueue(&Q, &i);
                    p = GL->adjList[i].firstedge; /* 找到当前顶点的边表链表头指针 */
                    while (p)
                    {
                        if (GL->adjList[p->adjvex].deleted == 0)
                        {
                            if (!visited[p->adjvex]) /* 若此顶点未被访问 */
                            {
                                visited[p->adjvex] = TRUE;
                                printf("%d ", p->adjvex);
                                EnQueue(&Q, p->adjvex); /* 将此顶点入队列 */
                            }
                        }
                        p = p->next; /* 指针指向下一个邻接点 */
                    }
                }
            }
        }
    }
}

int main(void)
{
    graphAdjList GL;
    memset(&GL, 0, sizeof(GL));
    CreateALGraph(&GL);
    DFSTraverse(&GL);
    printf("\n");
    BFSTraverse(&GL);
    printf("\n");
    // showALGraph(&GL);
    int del;
    scanf("%d", &del);
    GL.adjList[del].deleted = 1;

    DFSTraverse(&GL);
    printf("\n");
    BFSTraverse(&GL);
    return 0;
}

