#include<stdio.h>
#include<stdlib.h>

#define MAX 256
typedef struct Edge
{
    int adjvex;
    int weight;
    struct Edge *next;
} Elink;

typedef struct Ver
{
    int vertex;
    Elink *link;
} Vlink;

Vlink G[MAX];

Elink *insertEdge(Elink *head, int avex)
{
    Elink *e, *p;
    e = (Elink *)malloc(sizeof(Elink));
    e->adjvex = avex; e->weight = 1; e->next = NULL;
    if(head->next == NULL){head->next = e; return head->next;}
    for(p = head; p->next != NULL&&p->next->adjvex < e->adjvex; p = p->next);
    {
        e->next = p->next;
        p->next = e;
    }
    
    return head->next;
}

void creatGraph(Vlink graph[], int n)
{
    int i, j, v1, v2;
    for(int i = 0; i < n; i++)
    {
        G[i].link = (Elink *)malloc(sizeof(Elink));
        G[i].link->next = NULL;
    }
    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &v1, &v2);
        graph[v1].link->next = insertEdge(graph[v1].link, v2);
        graph[v2].link->next = insertEdge(graph[v2].link, v1);
    }
    return ;
}

int visited[MAX];
void DFS(Vlink G[], int v)
{
    Elink *p;
    visited[v] = 1;
    printf("%d ", v);
    for(p = G[v].link->next; p != NULL; p = p->next)
    {
        if(!visited[p->adjvex])
        {
            DFS(G, p->adjvex);
        }
    }
    return ;
}

void travelDFS(Vlink G[], int n)//travel函数的主顺序均为从0到n-1遍历节点数组，只不过DFS和BFS在遍历每一个节点的链表时遍历先后顺序有所区别
{
    for(int i = 0; i < n; i++)
    {
        if(!visited[i]) DFS(G, i);
    }
    printf("\n");
    return ;
}

int Q[MAX], beg = 0, end = -1;

void BFS(Vlink G[], int v)
{
    Elink *p;
    visited[v] = 1;
    Q[++end] = v;
    while(!(beg > end))
    {
        v = Q[beg++];
        printf("%d ", v);
        for(p = G[v].link->next; p != NULL; p = p->next)
        {
            if(!visited[p->adjvex])
            {
                visited[p->adjvex] = 1;
                Q[++end] = p->adjvex;
            }
        }
    }
    return ;
}

void travelBFS(Vlink G[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(!visited[i]) BFS(G, i);
    }
    printf("\n");
    return ;
}

void printGraph(Vlink G[], int vn)
{
    Elink *p;
    for(int i = 0; i < vn; i++)
    {   
        printf("%d", i);
        p = G[i].link->next;
        while(p != NULL)
        {
            printf("->%d", p->adjvex);
            p = p->next;
        }
        printf("\n");
    }
    return ;
}

int main(int argc, char *argv[])
{
    Elink *p;
    int en, vn, del;
    scanf("%d %d", &vn, &en);
    creatGraph(G, en);
    // printGraph(G, vn);
    for(int i = 0; i < vn; i++) visited[i] = 0;
    travelDFS(G, vn);
    for(int i = 0; i < vn; i++) visited[i] = 0;
    travelBFS(G, vn);
    scanf("%d", &del);
    for(int i = 0; i < vn; i++) visited[i] = 0;
    visited[del] = 1;
    travelDFS(G, vn);
    for(int i = 0; i < vn; i++) visited[i] = 0;
    visited[del] = 1;
    travelBFS(G, vn);
    return 0;
}
