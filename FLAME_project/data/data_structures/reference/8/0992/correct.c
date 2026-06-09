#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct edge
{
    int adjvex;
    // int weight;
    struct edge *next;
} ELink;
typedef struct ver
{
    int vertex;
    ELink *link;
} VLink;
VLink G[105];
int Visited[105] = {0}, n, del = -1; //标识顶点是否被访问过，N为顶点数

void DFS(int v)
{
    ELink *p;
    Visited[v] = 1; //标识某顶点被访问过
    printf("%d ", v);
    for (p = G[v].link; p != NULL; p = p->next)
        if (!Visited[p->adjvex])
            DFS(p->adjvex);
    return;
}
void travelDFS()
{
    int i;
    for (i = 0; i < n; i++)
        Visited[i] = 0;
    for (i = 0; i < n; i++)
        if (!Visited[i] && i != del)
            DFS(i);
    printf("\n");
    return;
}
int Count, Front, Rear, Q[1500];
int isEmpty()
{
    return Count == 0;
}
int isFull()
{
    return Count == 1500;
}
void initQueue()
{
    Front = 0;
    Rear = 1500 - 1;
    Count = 0;
}
void enQueue(int item)
{

    Rear = (Rear + 1) % 1500;
    Q[Rear] = item;
    Count++;
}
int deQueue()
{
    int e;
    e = Q[Front];
    Count--; /* 队非空，删除成功 */
    Front = (Front + 1) % 1500;
    return e;
}
void BFS(int v)
{
    initQueue();
    ELink *p;
    Visited[v] = 1; //标识某顶点已入队
    enQueue(v);
    while (!isEmpty())
    {
        v = deQueue();                              //取出队头元素
        printf("%d ", v);                           //访问当前顶点
        for (p = G[v].link; p != NULL; p = p->next) //访问该顶点的每个邻接顶点
            if (!Visited[p->adjvex])
            {
                Visited[p->adjvex] = 1; //标识某顶点入队
                enQueue(p->adjvex);
            }
    }
    return;
}
void travelBFS()
{
    int i;
    for (i = 0; i < n; i++)
        Visited[i] = 0;
    for (i = 0; i < n; i++)
        if (!Visited[i] && i != del)
            BFS(i);
    printf("\n");
    return;
}
ELink *insertEdge(ELink *head, int avex)
{
    ELink *e, *p, *q = NULL;
    e = (ELink *)malloc(sizeof(ELink));
    e->adjvex = avex;
    e->next = NULL;
    if (head == NULL)
    {
        head = e;
        return head;
    }
    for (p = head; p->next != NULL && p->adjvex < e->adjvex;)
    {
        q = p;
        p = p->next;
    }
    if (e->adjvex < p->adjvex)
    {
        if (p == head)
        { //找的节点是头结点，插到最前面
            head = e;
            e->next = p;
        }
        else
        { // 找到的是中间节点，插在中间节点q和p之间
            q->next = e;
            e->next = p;
        }
    }
    else
        p->next = e;
    return head;
}
void creategraph()
{
    int i, n2, v1, v2;
    scanf("%d%d", &n, &n2);
    for (i = 0; i < n; i++)
    {
        G[i].vertex = i;
    }
    for (i = 0; i < n2; i++)
    {
        scanf("%d%d", &v1, &v2);
        G[v1].link = insertEdge(G[v1].link, v2);
        G[v2].link = insertEdge(G[v2].link, v1);
    }
    return;
}
void deletever()
{

    scanf("%d", &del);
    for (int i = 0; i < n; i++)
    {
        ELink *p = NULL, *q = NULL;
        if (i != del)
        {
            for (p = G[i].link; p->next != NULL;)
            {
                if (p->adjvex == del)
                {
                    if (p == G[i].link)
                        G[i].link = p->next;
                    else
                        q->next = p->next;
                    free(p);
                    break;
                }
                q = p;
                p = p->next;
            }
            if (p->adjvex == del)
            {
                q->next = NULL;
                free(p);
            }
        }
    }
    return;
}
int main()
{
    // freopen("data.in", "r", stdin);
    creategraph();
    travelDFS();
    travelBFS();
    deletever();
    travelDFS();
    travelBFS();
    return 0;
}
