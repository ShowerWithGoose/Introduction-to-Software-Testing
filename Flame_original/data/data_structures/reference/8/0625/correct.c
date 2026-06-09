#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxV 100

typedef struct edge
{
    int adjvex; //±ß½çµã
    struct edge *next;
} ELink;
typedef struct ver
{
    ELink *link;
} VLink;

VLink G[MaxV];
char Visited[MaxV];
char Queue[MaxV];
int front = 0;
int rear = 0;

ELink *Insert(ELink *head, int avex);
void t_DFS(int n, int Dvex);
void DFS(int v);
void Delete(int Dvex, int Vnum);
void del(int Dvex, int avex);
void t_BFS(int n, int Dvex);
void BFS(int v);

int main()
{
    int Vnum, Enum;
    scanf("%d%d", &Vnum, &Enum);
    for (int i = 0; i < Enum; i++)
    {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        G[v1].link = Insert(G[v1].link, v2);
        G[v2].link = Insert(G[v2].link, v1);
    }
    t_DFS(Vnum, -1);
    printf("\n");
    t_BFS(Vnum, -1);
    printf("\n");
    int Dvex;
    scanf("%d", &Dvex);
    Delete(Dvex, Vnum);
    t_DFS(Vnum, Dvex);
    printf("\n");
    t_BFS(Vnum, Dvex);
    printf("\n");
    return 0;
}

ELink *Insert(ELink *head, int avex)
{
    ELink *e, *p, *tmp;
    e = (ELink *)malloc(sizeof(ELink));
    e->adjvex = avex;
    e->next = NULL;
    if (head == NULL)
    {
        head = e;
        return head;
    }
    else if (head->adjvex > avex)
    {
        tmp = head;
        head = e;
        e->next = tmp;
        return head;
    }
    for (p = head; p->next != NULL && p->next->adjvex < avex; p = p->next)
        ;
    tmp = p->next;
    p->next = e;
    e->next = tmp;
    return head;
}

void Delete(int Dvex, int Vnum)
{
    ELink *p;
    for (p = G[Dvex].link; p != NULL; p = p->next)
    {
        del(Dvex, p->adjvex);
    }
}

void del(int Dvex, int avex)
{
    ELink *p, *t;
    p = t = G[avex].link;
    if (G[avex].link->adjvex == Dvex)
    {
        G[avex].link = G[avex].link->next;
    }
    else
        for (p = G[avex].link; p->adjvex != Dvex; p = p->next)
        {
            t = p;
        }
    t->next = p->next;
}

void t_DFS(int n, int Dvex)
{
    int i = 0;
    for (i = 0; i < n; i++)
        Visited[i] = 0;
    if (Dvex >= 0)
        Visited[Dvex] = 1;
    for (i = 0; i < n; i++)
        if (!Visited[i])
            DFS(i);
}

void DFS(int v)
{
    ELink *p;
    Visited[v] = 1;
    printf("%d ", v);
    for (p = G[v].link; p != NULL; p = p->next)
    {
        if (!Visited[p->adjvex])
            DFS(p->adjvex);
    }
}

void t_BFS(int n, int Dvex)
{
    int i;
    for (i = 0; i < n; i++)
        Visited[i] = 0;
    if (Dvex >= 0)
        Visited[Dvex] = 1;
    for (i = 0; i < n; i++)
        if (!Visited[i])
            BFS(i);
}

void BFS(int v)
{
    ELink *p;
    Visited[v] = 1;
    Queue[rear++] = v;
    while (front != rear)
    {
        v = Queue[front++];
        printf("%d ", v);
        for (p = G[v].link; p != NULL; p = p->next)
        {
            if (!Visited[p->adjvex])
            {
                Visited[p->adjvex] = 1;
                Queue[rear++] = p->adjvex;
            }
        }
    }
}


