#include <stdio.h>
#include <stdlib.h>
#define MaxV 101

typedef struct edge{
    int adjvex;
    struct edge *next;
}elink;
typedef struct ver{
    int vertex;
    elink *link;
}vlink;
vlink G[MaxV];
int visitedD[MaxV]={0};
int visitedB[MaxV]={0};
int delete, n, e;

void createGraph(int n, int e);
elink *insertEdge(vlink *head, int avex);
void DFS(int v);
void BFS(int v);
//void deleteVer(int v);

int main()
{
    scanf("%d%d", &n, &e);
    createGraph(n, e);
    DFS(0); printf("\n");
    BFS(0); printf("\n");
/*删除某点，只要把该点当做遍历过的即可！！！【真tnnd妙啊】*/
    scanf("%d", &delete);
    for(int i=0; i<n; ++i) visitedD[i]=visitedB[i]=0;
    visitedD[delete]=visitedB[delete]=1;
    DFS(0); printf("\n");
    BFS(0);/*
    elink *p;
    for(int i=0; i<n; ++i)
    {
        printf("[%d]->", G[i].vertex);
        p=G[i].link;
        while(p)
        {
            printf("%d ", p->adjvex);
            p=p->next;
        }
        printf("\n");
    }*/
    return 0;
}

void createGraph(int n, int e)
{
    int v1, v2;
    for(int i=0; i<MaxV; ++i)
    {
        G[i].vertex=i;
        G[i].link=NULL;
    }
    for(int i=0; i<e; ++i)
    {
        scanf("%d%d", &v1, &v2);
        G[v1].link=insertEdge(&G[v1], v2);
        G[v2].link=insertEdge(&G[v2], v1);
    }
    printf("\n");
}

elink *insertEdge(vlink *head, int avex)
{
    elink *e=(elink *)malloc(sizeof(elink)), *p;
    /*e接在p的后面*/
    e->adjvex=avex; e->next=NULL;
    if(head->link==NULL || (head->link && avex<head->link->adjvex))
    {
        e->next=head->link;
        head->link=e;
        return e;
    }
    for(p=head->link; p->next && (p->next->adjvex < avex); p=p->next); //顺序插入
    e->next=p->next;
    p->next=e;
    return head->link;
}

void DFS(int v)
{
    elink *p;
    visitedD[v]=1;
    printf("%d ", v);
    for(p=G[v].link; p; p=p->next)
    {
        if(!visitedD[p->adjvex])
            DFS(p->adjvex);
    }
}

void BFS(int v)
{
    int queue[2*n];
    int frot=-1, rear=0;
    elink *p;
    printf("%d ", v);
    visitedB[v]=1;
    queue[rear++]=v;
    while(rear-frot!=1)
    {
        ++frot;
        for(p=G[queue[frot]].link; p; p=p->next)
        {
            if(!visitedB[p->adjvex])
            {
                printf("%d ", p->adjvex);
                visitedB[p->adjvex]=1;
                queue[rear++]=p->adjvex;
            }
        }
    }
}
