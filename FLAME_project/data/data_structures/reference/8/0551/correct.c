#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
int d, b, i, j, k, tmp1, tmp2, de;
int vi[105];
typedef struct edge
{
    int ad;
    int we;
    struct edge *next;
} ELink;
typedef struct ver
{
    int vertex;
    ELink *link;
} VLink;
VLink graph[105];
ELink *insertEdge(ELink *head, int avex)
{
    ELink *e, *p, *pre = NULL;
    e = (ELink *)malloc(sizeof(ELink));
    e->ad = avex;
    e->we = 1;
    e->next = NULL;
    if (head == NULL)
    {
        head = e;
        return head;
    }
    p = head;
    while (p != NULL && p->ad < avex)
    {
        pre = p;
        p = p->next;
    }
    if (pre == NULL)
    {
        e->next = head;
        return e;
    }
    e->next = pre->next;
    pre->next = e;
    return head;
}
void printfgraph(int dian, VLink graph[])
{
    for (i = 0; i < dian; i++)
    {
        ELink *p = graph[i].link;
        printf("%d->", graph[i].vertex);
        while (p != NULL)
        {
            printf("%d->", p->ad);
            p = p->next;
        }
        putchar('\n');
    }
}
void del(int x, int n)
{
    int i;
    ELink *p = NULL, *pre = NULL;
    graph[x].link = NULL;
    for (i = 0; i < n; i++)
    {
        p = graph[i].link;
        while (p != NULL && p->ad != x)
        {
            pre = p;
            p = p->next;
        }
        if (p == NULL)
        {
            continue;
        }
        if (p == graph[i].link)
        {
            graph[i].link = p->next;
            p->next = NULL;
            continue;
        }
        pre->next = p->next;
        p->next = NULL;
    }
}
void DFS(VLink G[], int v)
{
    ELink *p;
    vi[v] = 1; 
    printf("%d ", graph[v].vertex);
    for (p = G[v].link; p != NULL; p = p->next)
        if (!vi[p->ad])
            DFS(G, p->ad);
}
void travelDFS(VLink G[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        vi[i] = 0;
    for (i = 0; i < 1; i++)
	if (!vi[i])
            DFS(G, i);
    putchar('\n');
}
void BFS(VLink G[], int v)
{
    int Q[105], begin = 0, end = 0;
    ELink *p;
    vi[v] = 1;
    Q[end++] = v;
    while (begin != end)
    {
	 v = Q[begin++];
        printf("%d ", graph[v].vertex);
        for (p = G[v].link; p != NULL; p = p->next) 
            if (!vi[p->ad])
            {
                vi[p->ad] = 1;
                Q[end++] = p->ad;
            }
    }
}
void travelBFS(VLink G[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        vi[i] = 0;
    for (i = 0; i < 1; i++)
        if (!vi[i])
            BFS(G, i);
    putchar('\n');
}
int main()
{
    scanf("%d%d", &d, &b);
    for (i = 0; i < b; i++)
    {
        scanf("%d%d", &tmp1, &tmp2);
        graph[tmp1].vertex = tmp1;
        graph[tmp2].vertex = tmp2;
        graph[tmp1].link = insertEdge(graph[tmp1].link, tmp2);
        graph[tmp2].link = insertEdge(graph[tmp2].link, tmp1);
    }
    scanf("%d", &de);
    travelDFS(graph, d);
    travelBFS(graph, d);
    del(de, d);
    travelDFS(graph, d);
    travelBFS(graph, d);
    return 0;
}

