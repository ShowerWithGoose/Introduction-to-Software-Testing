#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <malloc.h>
typedef struct Edge
{
    int no;
    struct Edge *next;
} * Elink, Lnode;
struct Ver
{
    int no;
    Elink link;
} ver[200];
int Visited[200], Q[200], rear = 199, head = 0, count = 0, dv = -1;
void enQueue(int Q[], int v)
{
    rear = (rear + 1) % 200;
    Q[rear] = v;
    count++;
}
int deQueue(int Q[])
{
    int temp;
    temp = Q[head];
    head = (head + 1) % 200;
    count--;
    return temp;
}
int emptyQ(int Q[])
{
    if (count == 0)
        return 1;
    return 0;
}
void creatEdge(int ver1, int ver2)
{
    Elink p, q = NULL, r;
    if (ver[ver1].link == NULL)
    {
        p = (Elink)malloc(sizeof(Lnode));
        p->no = ver2;
        p->next = NULL;
        ver[ver1].link = p;
    }
    else
    {
        r = ver[ver1].link;
        while (r != NULL && r->no < ver2)
        {
            q = r;
            r = r->next;
        }
        p = (Elink)malloc(sizeof(Lnode));
        p->no = ver2;
        p->next = r;
        if (q != NULL)
            q->next = p;
        else
            ver[ver1].link = p;
    }
}
void insertEdge(struct Ver ver[], int v1, int v2)
{
    creatEdge(v1, v2);
    creatEdge(v2, v1);
}
void deleteVer(struct Ver ver[], int dv, int vN)
{
    int i;
    Elink p = NULL, q = NULL, r;
    for (i = 0; i < vN; i++)
    {
        if (i == dv)
        {
            ver[dv].link = NULL;
            continue;
        }
        p = ver[i].link;
        q = NULL;
        while (p != NULL)
        {
            if (p->no == dv)
            {
                r = p;
                p = p->next;
                free(r);
                if (q != NULL)
                    q->next = p;
                else
                    ver[i].link = p;
                break;
            }
            q = p;
            p = p->next;
        }
    }
}
void VISIT(struct Ver ver[], int v)
{
    if (v != dv)
        printf("%d ", ver[v].no);
}
void DFS(struct Ver G[], int v)
{
    Elink p;
    Visited[v] = 1; //标识某顶点被访问过
    VISIT(G, v);    //访问某顶点
    for (p = G[v].link; p != NULL; p = p->next)
        if (!Visited[p->no])
            DFS(G, p->no);
}
void travelDFS(struct Ver G[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        Visited[i] = 0;
    for (i = 0; i < n; i++)
        if (!Visited[i])
            DFS(G, i);
}
void BFS(struct Ver G[], int v)
{
    Elink p;
    Visited[v] = 1; //标识某顶点已入队
    enQueue(Q, v);
    while (!emptyQ(Q))
    {
        v = deQueue(Q);                             //取出队头元素
        VISIT(G, v);                                //访问当前顶点
        for (p = G[v].link; p != NULL; p = p->next) //访问该顶点的每个邻接顶点
            if (!Visited[p->no])
            {
                Visited[p->no] = 1; //标识某顶点入队
                enQueue(Q, p->no);
            }
    }
}
void travelBFS(struct Ver G[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        Visited[i] = 0;
    for (i = 0; i < n; i++)
        if (!Visited[i])
            BFS(G, i);
}
int main()
{
    int vN, eN, i, v1, v2;
    Elink item, p;
    scanf("%d%d", &vN, &eN);
    for (i = 0; i < vN; i++)
    {
        ver[i].no = i;
        ver[i].link = NULL;
    }
    for (i = 0; i < eN; i++)
    {
        scanf("%d%d", &v1, &v2);
        insertEdge(ver, v1, v2);
    }
    travelDFS(ver, vN);
    printf("\n");
    travelBFS(ver, vN);
    printf("\n");
    scanf("%d", &dv);
    deleteVer(ver, dv, vN);
    travelDFS(ver, vN);
    printf("\n");
    travelBFS(ver, vN);
    printf("\n");
    return 0;
}

