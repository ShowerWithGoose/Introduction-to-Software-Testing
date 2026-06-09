#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXNUM 100

int saveEdge[MAXNUM][MAXNUM];
int vis[MAXNUM];
int nodeNum, edgeNum;
void dfs(int nowVis);
void bfs(int nodeCnt);

int main()
{
    // freopen("input.txt", "r", stdin);
    scanf("%d%d", &nodeNum, &edgeNum);
    for (int i = 0; i < edgeNum; i++)
    {
        int node1, node2;
        scanf("%d%d", &node1, &node2);
        saveEdge[node1][node2] = saveEdge[node2][node1] = 1;
    }

    dfs(0);
    putchar('\n');
    memset(vis, 0, sizeof(vis));
    bfs(nodeNum);
    putchar('\n');
    memset(vis, 0, sizeof(vis));

    int delNode;
    scanf("%d", &delNode);
    for (int i = 0; i < nodeNum; i++)
    {
        saveEdge[i][delNode] = saveEdge[delNode][i] = 0;
    }
    // nodeNum--;
    dfs(0);
    putchar('\n');
    memset(vis, 0, sizeof(vis));
    bfs(nodeNum-1);

    return 0;
}

void dfs(int nowVis)
{
    printf("%d ", nowVis);
    vis[nowVis] = 1;
    for (int i = 0; i < nodeNum; i++)
    {
        if (saveEdge[nowVis][i] && !vis[i])
        {
            dfs(i);
        }
    }
}

// queue
typedef int ElemType;
typedef struct queue
{
    int front, rear;
    int count;
    int maxLen;
    ElemType * save;
} * Queue;

Queue createQueue(int maxNum);
void enQueue(Queue q, ElemType elem);
ElemType deQueue(Queue q);
ElemType peekQueue(Queue q);
int countQueue(Queue q);

Queue createQueue(int maxNum)
{
    Queue rt = malloc(sizeof(struct queue));
    rt->front = 0;
    rt->rear = maxNum-1;
    rt->maxLen = maxNum;
    rt->save = malloc(sizeof(ElemType)*maxNum);
    rt->count = 0;
    return rt;
}
void enQueue(Queue q, ElemType elem)
{

    q->count++;
    q->rear++;
    if (q->rear==q->maxLen)
        q->rear = 0;
    q->save[q->rear] = elem;

}
ElemType peekQueue(Queue q)
{
    return q->save[q->front];
}
ElemType deQueue(Queue q)
{

    ElemType rt = peekQueue(q);
    q->count--;
    q->front++;
    if (q->front==q->maxLen)
        q->front = 0;
    return rt;

}
int countQueue(Queue q)
{
    return q->count;
}
// queue

void bfs(int nodeCnt)
{
    Queue saveNode = createQueue(MAXNUM);
    enQueue(saveNode, 0);
    printf("0 ");
    vis[0] = 1;
    int visitCnt = 1;
    while (visitCnt < nodeCnt)
    {
        int nodeCnt = countQueue(saveNode);
        for (int i = 0; i < nodeCnt; i++)
        {
            int nowNode = deQueue(saveNode);
            for (int j = 0; j < nodeNum; j++)
            {
                if (saveEdge[nowNode][j] && !vis[j])
                {
                    enQueue(saveNode, j);
                    vis[j] = 1;
                    printf("%d ", j);
                    visitCnt++;
                }
            }
        } 
    }
}
