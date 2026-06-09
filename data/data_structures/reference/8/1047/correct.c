#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int adjvex;
    struct node *next;
} Enode;

typedef struct
{
    Enode *link;
} Vnode;

int *visited;
Vnode G[100];

Enode *insertEdge(int, int);
void dfs(Vnode[], int);
void bfs(Vnode[], int);

int main()
{
    int vn, en, v1, v2, n;
    scanf("%d%d", &vn, &en);
    visited = (int *)malloc(sizeof(int) * vn);
    for (int i = 0; i < en; i++)
    {
        scanf("%d%d", &v1, &v2);
        G[v1].link = insertEdge(v1, v2);
        G[v2].link = insertEdge(v2, v1);
    }
    scanf("%d", &n);
    for (int i = 0; i < vn; i++)
        visited[i] = 0;
    dfs(G, 0);
    puts("");
    for (int i = 0; i < vn; i++)
        visited[i] = 0;
    bfs(G, 0);
    for (int i = 0; i < vn; i++)
        visited[i] = 0;
    visited[n] = 1;
    dfs(G, 0);
    puts("");
    for (int i = 0; i < vn; i++)
        visited[i] = 0;
    visited[n] = 1;
    bfs(G, 0);

    return 0;
}
Enode *insertEdge(int v1, int v2)
{
    Enode *e = (Enode *)malloc(sizeof(Enode)), *head = G[v1].link, *p, *q;
    e->adjvex = v2;
    e->next = NULL;
    if (!head)
        return e;
    for (p = head, q = NULL; p; q = p, p = p->next)
        if (v2 < p->adjvex)
        {
            if (!q)
            {
                e->next = p;
                return e;
            }
            q->next = e;
            e->next = p;
            break;
        }
    if (!p)
        q->next = e;
    return head;
}
void dfs(Vnode G[], int v)
{
    printf("%d ", v);
    visited[v] = 1;
    for (Enode *p = G[v].link; p; p = p->next)
        if (!visited[p->adjvex])
            dfs(G, p->adjvex);
}
void bfs(Vnode G[], int v)
{
    int front = -1, rear = -1, queue[100], vex;
    queue[++rear] = v;
    visited[v] = 1;
    while (front != rear)
    {
        vex = queue[++front];
        printf("%d ", vex);
        for (Enode *p = G[vex].link; p; p = p->next)
            if (!visited[p->adjvex])
            {
                visited[p->adjvex] = 1;
                queue[++rear] = p->adjvex;
            }
    }
    puts("");
}


