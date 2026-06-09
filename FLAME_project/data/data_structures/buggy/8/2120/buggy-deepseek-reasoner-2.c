#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*邻接矩阵无向图*/
#pragma region 邻接矩阵图
#pragma region 内部1
/*定义*/
typedef struct inner_Mgraph_Queue
{
    int *buf;
    int head;
    int tail;
} Inner_Mgraph_Queue;
// 创建
Inner_Mgraph_Queue *Inner_Mgraph_NewQueue(int size);
// 入队
void Inner_Mgraph_Enqueue(Inner_Mgraph_Queue *queue, int idx);
// 出队
int Inner_Mgraph_Dequeue(Inner_Mgraph_Queue *queue);
// 重置
void Inner_Mgraph_ResetQueue(Inner_Mgraph_Queue *queue);
// 长度
int Inner_Mgraph_Count(Inner_Mgraph_Queue *queue);

/*实现*/
Inner_Mgraph_Queue *Inner_Mgraph_NewQueue(int size)
{
    Inner_Mgraph_Queue *res = (Inner_Mgraph_Queue *)malloc(sizeof(Inner_Mgraph_Queue));
    res->buf = (int *)malloc(size * sizeof(int));
    res->head = res->tail = 0;
    return res;
}
void Inner_Mgraph_Enqueue(Inner_Mgraph_Queue *queue, int idx)
{
    queue->buf[queue->tail++] = idx;
}
int Inner_Mgraph_Dequeue(Inner_Mgraph_Queue *queue)
{
    return queue->buf[queue->head++];
}
void Inner_Mgraph_ResetQueue(Inner_Mgraph_Queue *queue)
{
    queue->head = queue->tail = 0;
}
int Inner_Mgraph_Count(Inner_Mgraph_Queue *queue)
{
    return queue->tail - queue->head;
}
#pragma endregion
#pragma region 结构定义
typedef struct mGraphData
{
    int value;
} MGraphData;
typedef struct mGraph
{
    MGraphData *vertex;
    Inner_Mgraph_Queue *queue;
    int **matrix;
    int count;
    int size;
} MGraph;
/*数据行为*/
// 默认值
MGraphData MGraphData_Default()
{
    MGraphData res = {0};
    return res;
}
#pragma endregion
#pragma region 操作
// 创建图
MGraph MGraph_New(int size);
// 删除顶点
void MGraph_DelVertex(MGraph *G, int idx);
// 释放图
void MGraph_Dispose(MGraph *G);
// 建立连接
void MGraph_Link(MGraph *G, int vertexA, int vertexB, int weight);
// 深度优先搜索(子算法)
void MGraph_DFS(MGraph *G, int start, int *flag, void (*visit)(MGraphData data));
// 广度优先搜索(子算法)
void MGraph_BFS(MGraph *G, int start, int *flag, void (*visit)(MGraphData data));
#pragma endregion
#pragma region 实现
MGraph MGraph_New(int size)
{
    MGraph res;
    res.size = res.count = size;
    res.vertex = (MGraphData *)malloc(size * sizeof(MGraphData));
    res.matrix = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++)
    {
        res.vertex[i] = MGraphData_Default();
        res.matrix[i] = (int *)malloc(size * sizeof(int));
        for (int j = 0; j < size; j++)
            res.matrix[i][j] = INT_MAX; // @@ INT_MAX undeclared (first use in this function); missing #include <limits.h>
    }
    res.queue = NULL;
    return res;
}
void MGraph_DelVertex(MGraph *G, int idx)
{
    int i, j;
    // 顶点
    for (i = idx; i < G->count - 1; i++)
        G->vertex[i] = G->vertex[i + 1];
    if (idx != 0)
    {
        // 右和下方向
        for (i = 0; i < idx; i++)
        {
            for (j = idx; j < G->count - 1; j++)
            {
                G->matrix[i][j] = G->matrix[i][j + 1];
                G->matrix[j][i] = G->matrix[j + 1][i];
            }
        }
    }
    // 右下方
    for (i = idx; i < G->count - 1; i++)
        for (j = idx; j < G->count - 1; j++)
            G->matrix[i][j] = G->matrix[i + 1][j + 1];
    // 边
    for (i = 0; i < G->count; i++)
        G->matrix[i][G->count - 1] = G->matrix[G->count - 1][i] = INT_MAX; // @@ INT_MAX undeclared (first use in this function); missing #include <limits.h>
    G->count--;
}
void MGraph_Link(MGraph *G, int vertexA, int vertexB, int weight)
{
    G->matrix[vertexA][vertexB] = G->matrix[vertexB][vertexA] = weight;
}
void MGraph_Dispose(MGraph *G)
{
    // 顶点
    free(G->vertex);
    // 邻接矩阵
    for (int i = 0; i < G->size; i++)
        free(G->matrix[i]);
    free(G->matrix);
    // 队列
    if (G->queue != NULL)
    {
        free(G->queue->buf);
        free(G->queue);
        G->queue = NULL;
    }
    G->matrix = NULL;
    G->vertex = NULL;
}
void MGraph_DFS(MGraph *G, int start, int *flag, void (*visit)(MGraphData data))
{
    if (flag[start])
        return;
    visit(G->vertex[start]);
    flag[start] = 1;
    for (int i = 0; i < G->count; i++)
        if (G->matrix[start][i] != INT_MAX) // @@ INT_MAX undeclared (first use in this function); missing #include <limits.h>
            MGraph_DFS(G, i, flag, visit);
}
void MGraph_BFS(MGraph *G, int start, int *flag, void (*visit)(MGraphData data))
{
    // 队列初始化
    if (G->queue == NULL)
        G->queue = Inner_Mgraph_NewQueue(G->size);
    else
        Inner_Mgraph_ResetQueue(G->queue);
    // 循环初始化
    Inner_Mgraph_Enqueue(G->queue, start);
    flag[start] = 1;
    // 循环
    int idx, i;
    while (Inner_Mgraph_Count(G->queue) > 0)
    {
        idx = Inner_Mgraph_Dequeue(G->queue);
        visit(G->vertex[idx]);
        for (i = 0; i < G->count; i++)
        {
            if (G->matrix[idx][i] != INT_MAX && !flag[i]) // @@ INT_MAX undeclared (first use in this function); missing #include <limits.h>
            {
                Inner_Mgraph_Enqueue(G->queue, i);
                flag[i] = 1;
            }
        }
    }
}
#pragma endregion
#pragma endregion

MGraph G;
int vCount, eCount, del, flag[100];
void OutVisit(MGraphData data)
{
    printf("%d ", data.value);
}

int main()
{
    int v1, v2, i;
    scanf("%d%d", &vCount, &eCount);
    G = MGraph_New(vCount);
    for (i = 0; i < vCount; i++)
        G.vertex[i].value = i;
    for (i = 0; i < eCount; i++)
    {
        scanf("%d%d", &v1, &v2);
        MGraph_Link(&G, v1, v2, 1);
    }
    scanf("%d", &del);

    MGraph_DFS(&G, 0, flag, OutVisit);
    printf("\n");
    memset(flag, 0, vCount * sizeof(int));

    MGraph_BFS(&G, 0, flag, OutVisit);
    printf("\n");
    memset(flag, 0, vCount * sizeof(int));

    MGraph_DelVertex(&G, del);

    MGraph_DFS(&G, 0, flag, OutVisit);
    printf("\n");
    memset(flag, 0, vCount * sizeof(int));
    
    MGraph_BFS(&G, 0, flag, OutVisit);

    MGraph_Dispose(&G);
}