#include<stdio.h>
#include<string.h>
#include<stdlib.h>    
typedef struct edge {
    int adjvex;
    struct edge* next;
}ELink;
typedef struct ver {
    int vertex;
    ELink* link;
}VLink;
typedef struct node {
    int vertex;
    struct node* next;
}Qnode, * QUEUE;
int visited[101] = { 0 };
void ADJLIST(VLink G[], int n, int e)
{
    int k, vi, vj;
    ELink* p, * q;
    for (k = 0; k < n; k++)
    {
        G[k].vertex = k;
        G[k].link = NULL;
    }
    for (k = 0; k < e; k++)
    {
        scanf("%d %d", &vi, &vj);
        p = (ELink*)malloc(sizeof(ELink));
        p->adjvex = vj;
        p->next = NULL;
        if (G[vi].link == NULL)
        {
            G[vi].link = p;
        }
        else
        {
            q = G[vi].link;
            if (p->adjvex < q->adjvex)
            {
                p->next = q;
                G[vi].link = p;
            }
            else
            {
                while (q->next != NULL)
                {
                    if (p->adjvex > q->adjvex && p->adjvex < q->next->adjvex)
                    {
                        p->next = q->next;
                        q->next = p;
                        break;
                    }
                    else
                    {
                        q = q->next;
                    }

                }
                if (q->next == NULL)
                {
                    q->next = p;
                }
                if (q->adjvex > q->next->adjvex) // @@ This swap is unnecessary and may break sorted order; also assumes q->next exists (it does after insertion but this logic is flawed)
                {
                    int x = q->adjvex;
                    q->adjvex = q->next->adjvex;
                    q->next->adjvex = x;
                }
            }

        }
        p = (ELink*)malloc(sizeof(ELink));
        p->adjvex = vi;
        p->next = NULL;
        if (G[vj].link == NULL)
        {
            G[vj].link = p;
        }
        else
        {
            q = G[vi].link; // @@ Error: should be G[vj].link, not G[vi].link. This causes adjacency list for vj to be built incorrectly.
            if (p->adjvex < q->adjvex)
            {
                p->next = q;
                G[vi].link = p; // @@ Also should be G[vj].link
            }
            else
            {
                while (q->next != NULL)
                {
                    if (p->adjvex > q->adjvex && p->adjvex < q->next->adjvex)
                    {
                        p->next = q->next;
                        q->next = p;
                        break;
                    }
                    else
                    {
                        q = q->next;
                    }

                }
                if (q->next == NULL)
                {
                    q->next = p;
                }
                if (q->adjvex > q->next->adjvex) // @@ Same unnecessary swap issue
                {
                    int x = q->adjvex;
                    q->adjvex = q->next->adjvex;
                    q->next->adjvex = x;
                }
            }
        }
    }
}
void DELVER(VLink G[], int n, int item)
{
    int i, k = -1;
    ELink* p, * q = NULL, * r;
    for (i = 0; i < n; i++)
    {
        if (G[i].vertex == item)
        {
            k = i;
            break;
        }
    }
    if (k != -1)
    {
        p = G[k].link;
        for (i = k + 1; i < n; i++) // @@ Shifting vertices may cause index mismatches; further operations using original k are incorrect.
        {
            G[i - 1].vertex = G[i].vertex;
            G[i - 1].link = G[i].link;
        }
        n--; // @@ n is local; caller's n unchanged; later call to TRAVEL uses n-1, but graph state is corrupted.
        while (p != NULL)
        {
            r = p;
            p = p->next;
            free(r);
        }
        for (i = 0; i < n; i++) // @@ This loop uses the original k (which after shifting may not be the deleted index). Also adjacency lists are not updated for shifted vertices.
        {
            p = G[i].link;
            while (p != NULL)
            {
                if (p->adjvex == k)
                {
                    if (G[i].link == p)
                    {
                        G[i].link = p->next;
                    }
                    else
                    {
                        q->next = p->next;
                    }
                    r = p;
                    p = p->next;
                    free(r);
                }
                else
                {
                    if (p->adjvex > k)
                    {
                        p->adjvex--;
                    }
                    q = p;
                    p = p->next;
                }
            }
        }
    }
}
void VISIT(VLink G[], int v)
{
    printf("%d ", G[v].vertex);
}
void DFS(VLink G[], int v)
{
    int w;
    VISIT(G, v);
    visited[v] = 1;
    if (G[v].link != NULL)
    {
        w = G[v].link->adjvex;
    }
    else
    {
        w = -1;
    }
    while (w != -1)
    {
        if (visited[w] == 0)
        {
            DFS(G, w);
        }
        ELink* s = G[v].link;
        while (1) // @@ This while loop re-traverses the adjacency list from start each time to find the next neighbor, but it may cause infinite loop or incorrect order if adjacency list changes.
        {
            if (s->adjvex == w)
            {
                if (s->next != NULL)
                {
                    w = s->next->adjvex;
                }
                else
                {
                    w = -1;
                }
                break;
            }
            s = s->next;
        }

    }
}
void TRAVEL_DFS(VLink G[], int visited[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            DFS(G, i);
        }
    }
}
void ADDQ(QUEUE Q, int v)
{
    QUEUE p = (QUEUE)malloc(sizeof(Qnode)), q = Q;
    p->vertex = v;
    p->next = NULL;
    while (q->next != NULL)
    {
        q = q->next;
    }
    q->next = p;
}
int DELQ(QUEUE Q)
{
    int x = Q->next->vertex;
    Q->next = Q->next->next;
    return x;
}
void BFS(VLink G[], int v, QUEUE Q)
{
    int w;
    VISIT(G, v);
    visited[v] = 1;
    ADDQ(Q, v);
    while (Q->next != NULL)
    {
        v = DELQ(Q);
        if (G[v].link != NULL)
        {
            w = G[v].link->adjvex;
        }
        else
        {
            w = -1;
        }
        while (w != -1)
        {
            if (visited[w] == 0)
            {
                VISIT(G, w);
                ADDQ(Q, w);
                visited[w] = 1;
            }
            ELink* s = G[v].link;
            while (1) // @@ Similar issue as in DFS: re-traversing list may lead to incorrect neighbor ordering.
            {
                if (s->adjvex == w)
                {
                    if (s->next != NULL)
                    {
                        w = s->next->adjvex;
                    }
                    else
                    {
                        w = -1;
                    }
                    break;
                }
                s = s->next;
            }
        }

    }
}
void TRAVEL_BFS(VLink G[], int visited[], int n, QUEUE Q)
{
    int i;
    for (i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            BFS(G, i, Q);
        }
    }
}
int main()
{
    QUEUE Q = (QUEUE)malloc(sizeof(Qnode));
    int n, e, item;
    VLink G[101];
    Q->next = NULL;
    scanf("%d %d", &n, &e);
    ADJLIST(G, n, e);
    TRAVEL_DFS(G, visited, n);
    printf("\n");
    TRAVEL_BFS(G, visited, n, Q);
    printf("\n");
    scanf("%d", &item);
    DELVER(G, n, item);
    TRAVEL_DFS(G, visited, n - 1); // @@ After DELVER, graph structure is corrupted; passing n-1 is incorrect because DELVER did not properly reduce vertex count.
    printf("\n");
    TRAVEL_BFS(G, visited, n - 1, Q); // @@ Same issue.
    printf("\n");
    return 0;
}