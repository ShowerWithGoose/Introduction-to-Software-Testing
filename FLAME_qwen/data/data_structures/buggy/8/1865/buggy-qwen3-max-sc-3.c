// 这道题的关键在于插入新的边的顺序性，在这里轮子默认插入到最前面，可以根据需要先对边进行排序，再插入
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
图相关的定义
*/
#define MaxVertexNum 1000000          // 定义图所能容纳的最大顶点数
int VertexNum;                        // 全局变量，用来定义图的顶点总数，便于其他函数调用
int EdgeNum;                          // 全局变量，用来定义图的边总数，便于其他函数调用
int visited[MaxVertexNum];            // DFS的标记数组
typedef int Vertex;                   // 用来定义顶点位置下标的类型
typedef int WeightType;               // 用来定义边的权重的类型;
typedef struct EdgeNode *Edge;        // 用来定义边结点的指针类型
typedef struct VertexNode *GraphList; // 用来定义图的指针类型
struct VertexNode
{
    int vertex;     // 顶点编号
    Edge FirstEdge; // 指向第一条依附该顶点的边的指针
};
struct EdgeNode
{
    int adjver;        // 储存顶点编的下标位置
    WeightType weight; // 储存边权值
    Edge next;
};
struct VerEdge
{
    int start;
    int end;
} *VerData;
/*
队列的实现，包括定义和相关的函数
*/
typedef int ElementType;
typedef struct arr_Queue *Queue;
struct arr_Queue
{
    int size;          // 队列中已有数据的个数
    int Front;         // 队列的开头
    int Rear;          // 队列的结尾
    int Capacity;      // 队列最大容量
    ElementType *data; // 数组存储数据
};
int IsFull(Queue Q);
int IsEmpty(Queue Q);
void MakeEmpty(Queue Q);
Queue CreateQueue(int MaxSize);
void EnQueue(Queue Q, ElementType X);
ElementType DeQueue(Queue Q);
void DisposeQueue(Queue Q);
void DFS(GraphList Graph, Vertex v);

/*
图相关的函数
*/
GraphList CreateGraph();
void InsertEgde(GraphList Graph, Vertex start, Vertex end, WeightType weight);
void Visit(GraphList Graph, Vertex v);
void BFS(GraphList Graph, Vertex v, Queue Q);
int cmp(const void *a, const void *b)
{
    struct VerEdge *A = (struct VerEdge *)a;
    struct VerEdge *B = (struct VerEdge *)b;
    if (A->start == B->start)
    {
        return B->end - A->end;
    }
    else
    {
        return A->start - B->start;
    }
}
void DeleteVertex(GraphList Graph, Vertex v);

void printGraph(GraphList Graph);
int main()
{

    scanf("%d", &VertexNum);

    scanf("%d", &EdgeNum);
    EdgeNum = 2 * EdgeNum;
    // printf("%d %d\n", VertexNum, EdgeNum);
    VerData = (struct VerEdge *)malloc(sizeof(struct VerEdge) * EdgeNum);
    for (int i = 0; i < EdgeNum / 2; i++)
    {
        scanf("%d %d", &VerData[i].start, &VerData[i].end);
        // printf("%d %d\n", VerData[i].start, VerData[i].end);
        VerData[i + EdgeNum / 2].start = VerData[i].end;
        VerData[i + EdgeNum / 2].end = VerData[i].start;
    }
    qsort(VerData, EdgeNum, sizeof(struct VerEdge), cmp);
    GraphList Graph = CreateGraph();
    Queue Q = CreateQueue(VertexNum);
    DFS(Graph, 0);
    printf("\n");
    for (int i = 0; i < VertexNum; i++)
    {
        visited[i] = 0;
    }
    BFS(Graph, 0, Q);
    printf("\n");
    DisposeQueue(Q);
    Q = CreateQueue(VertexNum);
    // printGraph(Graph);
    int del;
    while (scanf("%d", &del) != EOF)
    {
        int ver;
        for (int i = 0; i < VertexNum; i++)
        {
            if (Graph[i].vertex == del)
            {
                ver = i;
                break;
            }
        }
        DeleteVertex(Graph, ver);
        for (int i = 0; i < VertexNum; i++)
        {
            visited[i] = 0;
        }
        DFS(Graph, 0);
        printf("\n");
        for (int i = 0; i < VertexNum; i++)
        {
            visited[i] = 0;
        }
        BFS(Graph, 0, Q);
        printf("\n");
    }
    return 0;
}
void DeleteVertex(GraphList Graph, Vertex v)
{
    // 删除顶点，一一向前移动
    Edge q = Graph[v].FirstEdge;
    while (q != NULL)
    {
        Edge tmp = q;
        q = q->next;
        EdgeNum--;
        free(tmp);
    }
    if (v == VertexNum - 1)
    {
        Graph[v].vertex = 0;
        Graph[v].FirstEdge = NULL;
    }
    else
    {
        for (int i = v + 1; i < VertexNum; i++)
        {
            Graph[i - 1].vertex = Graph[i].vertex;
            Graph[i - 1].FirstEdge = Graph[i].FirstEdge;
            // 向前移动
        }
    }
    VertexNum--;
    // 删除所有邻接表中与该顶点相关的边
    // printGraph(Graph);
    for (int i = 0; i < VertexNum; i++)
    {

        Edge p = Graph[i].FirstEdge;
        // 一定要考虑没有边的情况，否则会出现指针错误
        if (Graph[i].FirstEdge != NULL)
        {
            if (Graph[i].FirstEdge->adjver == v)
            {
                Graph[i].FirstEdge = p->next;
                EdgeNum--;
                Edge tmp = p;

                free(tmp);
            }
            else
            {
                if (Graph[i].FirstEdge->adjver > v)
                {
                    Graph[i].FirstEdge->adjver--;
                }
            }
            p = Graph[i].FirstEdge;
            if (p->adjver > v)
            {
                p->adjver--;
            }
            if (Graph[i].FirstEdge != NULL)
            {
                while (p->next != NULL)
                {
                    if (p->next->adjver == v)
                    {
                        Edge tmp = p->next;
                        p->next = tmp->next;
                        EdgeNum--;
                        free(tmp);
                    }
                    else
                    {
                        if (p->next->adjver > v)
                        {
                            p->next->adjver--;
                            // 改变邻接表中与该顶点相关的边的顶点下标
                        }
                        p = p->next;
                    }
                }

                // 改变邻接表中与该顶点相关的边的顶点下标
            }
        }
        // printf("第%d次遍历删除相关边\n", i);
        // printGraph(Graph);
    }
}
void Visit(GraphList Graph, Vertex v)
{
    printf("%d ", Graph[v].vertex);
}
// 广度优先搜索
void BFS(GraphList Graph, Vertex v, Queue Q)
{
    Visit(Graph, v);
    visited[v] = 1;
    EnQueue(Q, v);
    while (!IsEmpty(Q))
    {
        Vertex u = DeQueue(Q);
        Edge w = Graph[u].FirstEdge;
        while (w != NULL)
        {
            if (visited[w->adjver] == 0)
            {
                Visit(Graph, w->adjver);
                visited[w->adjver] = 1;
                EnQueue(Q, w->adjver);
            }
            w = w->next;
        }
    }
}
void DFS(GraphList Graph, Vertex v)
{
    Edge w;
    visited[v] = 1;
    Visit(Graph, v);
    for (w = Graph[v].FirstEdge; w != NULL; w = w->next)
    {
        if (visited[w->adjver] == 0)
        {
            DFS(Graph, w->adjver);
        }
    }
}
GraphList CreateGraph()
{
    if (VertexNum > MaxVertexNum)
    {
        printf("顶点数超过最大值");
    }
    GraphList Graph = (GraphList)malloc(sizeof(struct VertexNode) * VertexNum);
    int m = 0;
    for (int i = 0; i < VertexNum; i++)
    {
        Graph[i].vertex = m;
        m++;
        Graph[i].FirstEdge = NULL;
    }
    int temp = EdgeNum;
    for (int i = 0; i < temp; i++)
    {
        InsertEgde(Graph, VerData[i].start, VerData[i].end, 0);
    }
    EdgeNum = temp;
    return Graph;
}
// 插入边，start是起点的位置下标，end是终点的位置下标，weight是边的权重
void InsertEgde(GraphList Graph, Vertex start, Vertex end, WeightType weight)
{
    // 这里默认了是有向图，无向图还需要再加一条边
    Edge newEdge = (Edge)malloc(sizeof(struct EdgeNode));
    newEdge->adjver = end;
    newEdge->weight = weight;
    //  这里默认插入到邻接表的最前面，可以根据需要设置其它合适的插入排序
    newEdge->next = Graph[start].FirstEdge;
    Graph[start].FirstEdge = newEdge;
    EdgeNum++;
}
// 测试队列是否排满
int IsFull(Queue Q)
{
    return Q->size == Q->Capacity;
}
// 测试队列是否为空
int IsEmpty(Queue Q)
{
    return Q->size == 0;
}
// 清空队列
void MakeEmpty(Queue Q)
{
    Q->size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}
// 创造一个队列
Queue CreateQueue(int MaxElements)
{
    Queue Q = (Queue)malloc(sizeof(struct arr_Queue));
    if (Q == NULL)
    {
        printf("The Function CreateQueue Out of space!");
        exit(1);
    }
    Q->data = (ElementType *)malloc(MaxElements * sizeof(ElementType));
    if (Q->data == NULL)
    {
        printf("The Function CreateQueue Out of space!");
        exit(1);
    }
    Q->Capacity = MaxElements;
    MakeEmpty(Q);
    return Q;
}
// 在结尾处入队加入数据
void EnQueue(Queue Q, ElementType X)
{
    if (IsFull(Q))
    {
        printf("The Queue is Full!");
        exit(1);
    }
    else
    {
        Q->size++;
        // 取模处理，形成循环队列
        Q->Rear = (Q->Rear + 1) % Q->Capacity;
        Q->data[Q->Rear] = X;
    }
}
// 在开头处出队删除数据，返回删除数据的值
ElementType DeQueue(Queue Q)
{
    if (IsEmpty(Q))
    {
        printf("The Queue is Empty!");
        exit(1);
    }
    else
    {
        Q->size--;
        ElementType Frontdata = Q->data[Q->Front];
        // 取模处理，形成循环队列
        Q->Front = (Q->Front + 1) % Q->Capacity;
        return Frontdata;
    }
}
// 释放队列的内存
void DisposeQueue(Queue Q)
{
    free(Q->data);
    free(Q);
}
void printGraph(GraphList Graph)
{
    for (int i = 0; i < VertexNum; i++)
    {
        printf("序号为%d的点:   ", Graph[i].vertex);
        Edge p = Graph[i].FirstEdge;
        printf("该点相邻的点的序号为：");
        while (p != NULL)
        {
            printf("%d->%d 权值:0 ", Graph[i].vertex, Graph[p->adjver].vertex);
            p = p->next;
        }
        printf("\n");
    }
    printf("该图的顶点数为：%d\n", VertexNum);
    printf("该图的边数为：%d\n", EdgeNum);
}