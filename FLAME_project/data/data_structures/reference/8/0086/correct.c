#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MaxV 256
typedef struct  edge {
    int  adjvex;
    struct edge *next;
}Elink;
Elink* G[MaxV];
int n,m;/*顶点个数*/
int visited[MaxV];/*标记已经被访问过的顶点*/
Elink* insert(Elink* top, int date)/*插入邻接表*/
{
    Elink* p = top,*e;
    e = (Elink*)malloc(sizeof(Elink));
    e->adjvex = date, e->next = NULL;
    while (p->next != NULL)
    {
        if (p->next->adjvex > date)
            break;
        else if (p->next->adjvex == date)
        {p = p->next;
         break;}
        else
            p = p->next;
    }
    e->next = p->next, p->next = e;
    return top;
}
void establish()/*建立邻接表*/
{
    int i;
    int date1, date2;
    for (i = 0; i < n; i++)
        G[i] = (Elink*)malloc(sizeof(Elink)),G[i]->adjvex=i,G[i]->next=NULL;
    for (i = 0; i < m; i++)
    {
        scanf("%d %d", &date1, &date2);
        G[date1] = insert(G[date1], date2);
        G[date2] = insert(G[date2], date1);
    }
}
void DFS(int v)
{
    Elink* p;
    visited[v] = 1;
    printf("%d ", v);
    for (p = G[v]->next; p != NULL; p = p->next)
        if (!visited[p->adjvex])
            DFS(p->adjvex);
}
void travelDFS()
{
    int i;
    for (i = 0; i < n; i++)visited[i] = 0;
    for (i = 0; i < n; i++)
        if (!visited[i]&&G[i]->adjvex>=0)DFS(i);
    printf("\n");
}
void BFS(int v)
{
    Elink* p;
    printf("%d ", v);
    visited[v] = 1;
    int rear, front,que[1000];
    que[0] = v;
    for (rear = 1, front = 0; front < rear;)
    {
        p = G[que[front]]->next;
        front++;
        for (; p != NULL; p = p->next)
            if (!visited[p->adjvex])
            {
                printf("%d ", p->adjvex);
                visited[p->adjvex] = 1;
                que[rear++] = p->adjvex;
            }
    }
}
void travelBFS()
{
    int i;
    for (i = 0; i < n; i++)visited[i] = 0;
    for (i = 0; i < n; i++)
        if (!visited[i]&& G[i]->adjvex >= 0)BFS(i);
    printf("\n");
}
void delete(int e)/*删除某一个顶点*/
{
    Elink* p = G[e]->next,*op;
    for (; p != NULL; p = p->next)
    {
        Elink* q=G[p->adjvex];
        for (; q->next != NULL; q = q->next)
            if (q->next->adjvex == e)
            {
                op = q->next;
                q->next = q->next->next;
                free(op);
                break;
            }
    }
    G[e]->adjvex = -1;
}
void allfree()/*释放空间*/
{
    int i;
    Elink* p, * q;
    for (i = 0; i < n; i++)
    {
        p = G[i];
        while (p != NULL)
        {
            q = p;
            p = p->next;
            free(q);
        }
    }
}

int main()
{
    int e;
    scanf("%d %d", &n, &m);
    establish();
    scanf("%d", &e);
    travelDFS();
    travelBFS();
    delete(e);
    travelDFS();
    travelBFS();
    allfree();
    return 0;
}
