#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int visited[100];

typedef struct edge
{
    int adjvex;
    struct edge *next;
}Elink;

typedef struct ver
{
    Elink *link;
}Vlink;
Vlink G[100];

int VQ[100];
int front, rear;

void setVQ()
{
    front = rear = -1;
}

int isempty()
{
    return front == rear;
}

void insertGraph(Vlink *Graph, int v1, int v2)
{
    Elink *temp = (Elink *)malloc(sizeof(Elink));
    temp->adjvex = v2;
    Elink *pM = Graph[v1].link;
    if (pM == NULL)
    {
        temp->next = NULL;
        Graph[v1].link = temp;
        return ;
    }
    else
    {
        if (Graph[v1].link->adjvex > v2)
        {
            temp->next = Graph[v1].link;
            Graph[v1].link = temp;
            return ;
        }
        else
        {
            while (pM->next)
            {
                if (pM->next->adjvex > v2)
                {
                    temp->next = pM->next;
                    pM->next = temp;
                    return ;
                }
                pM = pM->next;
            }
            pM->next = temp;
            temp->next = NULL;
        }
    }

}

void DFS(Vlink *Graph, int v)
{
    visited[v] = 1;
    printf("%d ", v);
    Elink *pM = Graph[v].link;
    while (pM)
    {
        if (!visited[pM->adjvex])
            DFS(Graph, pM->adjvex);
        pM = pM->next;
    }
}

void traDFS(Vlink *Graph, int len)
{
    memset(visited, 0, len*sizeof(int));
    for (int i = 0;i < len;i ++)
        if (!visited[i]) DFS(Graph, i);
}

void BFS(Vlink *Graph, int v)
{
    visited[v] = 1;
    VQ[++rear] = v;
    Elink *pM;
    int frontv;
    while (!isempty())
    {
        frontv = VQ[++front];
        printf("%d ", frontv);
        pM = G[frontv].link;
        while (pM)
        {

            if (!visited[pM->adjvex])
            {
                visited[pM->adjvex] = 1;
                VQ[++rear] = pM->adjvex;
            }
            pM = pM->next;
        }
    }
}

void traBFS(Vlink *Graph, int len)
{
    memset(visited, 0, len*sizeof(int));
    setVQ();
    for (int i = 0;i < len;i ++)
        if (!visited[i]) BFS(Graph, i);
}

void deleteG(int adjvex)
{
    Elink *pM = G[adjvex].link;
    if (!pM) return ;
    else
    {
        while (pM)
        {
            int v = pM->adjvex;
            Elink *pM2 = G[v].link;
            if (G[v].link->adjvex == adjvex)
            {
                G[v].link = pM2->next;
                free(pM2);
            }
            else
            {
                Elink *pM2behind = pM2->next;
                while (pM2behind->adjvex != adjvex)
                {
                    pM2 = pM2->next;
                    pM2behind = pM2behind->next;
                }
                pM2->next = pM2behind->next;
                free(pM2behind);
            }

            G[adjvex].link = pM->next;
            free(pM);
            pM = G[adjvex].link;
        }
    }
}

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);
    int v1, v2, dev;

    for (int i = 0;i < E;i ++)
    {
        scanf("%d %d", &v1, &v2);
        insertGraph(G, v1, v2);
        insertGraph(G, v2, v1);
    }
    scanf("%d", &dev);

    traDFS(G, V);
    printf("\n");
    traBFS(G, V);
    printf("\n");

    deleteG(dev);

    memset(visited, 0, V*(sizeof(int)));
    for (int i = 0;i < V;i ++)
    {
        if (i == dev) continue;
        if (!visited[i])
            DFS(G, i);
    }
    printf("\n");
    memset(visited, 0, V*(sizeof(int)));
    for (int i = 0;i < V;i ++)
    {
        if (i == dev) continue;
        if (!visited[i])
            BFS(G, i);
    }


    return 0;
}



