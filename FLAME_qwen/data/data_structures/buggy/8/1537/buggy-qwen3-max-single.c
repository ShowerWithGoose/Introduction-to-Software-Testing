#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Max 256

typedef struct edge{
    int adj;
    int wei;
    struct edge *next;
}ELink;
typedef struct ver{
    ELink *link;
}VLink;
VLink G[Max];

ELink *insertEdge(ELink *head, int avex)
{
    ELink *e, *p, *temp;
    e = (ELink *)malloc(sizeof(ELink));
    e->adj = avex; e->wei = 1; e->next = NULL;
    if(head == NULL)
    {
        head = e;
        return head;
    }
    for(p = head; p != NULL && e->adj >= p->adj; temp = p, p = p->next);
    if(p == head)
    {
        e->next = p;
        return e;
    }
    else
    {
        e->next = temp->next;
        temp->next = e;
    }
    
    return head;
}

int visited[Max] = {0};
void DFS(VLink G[], int v)
{
    ELink *p;
    visited[v] = 1;
    printf("%d ", v);
    for(p = G[v].link; p != NULL; p = p->next)
        if(!visited[p->adj])
            DFS(G, p->adj);
}
void travelDFS(VLink G[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        visited[i] = 0;
    for(i = 0; i < n; i++)
        if(!visited[i])
            DFS(G, i);
}


int Q[Max] = {0}, rear = 0, count = 0, front = 0;
int isEmpty()
{
    return count == 0;
}
void enQueue(int Q[], int item)
{
    Q[rear] = item;
    rear = (rear + 1) % Max;
    
    count++;
}
int deQueue(int Q[])
{
    int e;
    e = Q[front];
    count--;
    front = (front + 1) % Max;
    return e;
}
void BFS(VLink G[], int v)
{
    ELink *p;
    visited[v] = 1;
    enQueue(Q, v);
    while(!isEmpty())
    {
        v = deQueue(Q);
        printf("%d ", v);
        for(p = G[v].link; p != NULL; p = p->next)
            if(!visited[p->adj])
            {
                visited[p->adj] = 1;
                //printf("%d ", v);
                enQueue(Q, p->adj);
            }
    }
}
void travelBFS(VLink G[], int n)
{
    int i;
    for(i = 0; i < n; i++)
        visited[i] = 0;
    for(i = 0; i < n; i++)
        if(!visited[i])
            BFS(G, i);
}

void deleteVec(VLink G[], int TBDel, int n)
{
    int i;
    ELink *p, *pri;
    while(i < n) // @@ [Variable 'i' is uninitialized, leading to undefined behavior in the loop condition]
    {
        for(p = G[i].link; p != NULL; pri = p, p = p->next) // @@ [If G[i].link is NULL, the loop body never runs and 'i' is never incremented, causing infinite loop]
        {
            if(p == G[i].link && p->adj == TBDel)
                G[i].link = p->next;
            else if(p->adj == TBDel)
                pri->next = p->next;
            free(p); // @@ [Freeing 'p' inside the loop invalidates the pointer used in 'p = p->next', causing use-after-free]
            i++; // @@ [Incrementing 'i' inside inner loop causes skipping of vertices and potential out-of-bounds access]
        }
    }
}
void travelDFSdel(VLink G[], int n, int TBDel)
{
    int i;
    for(i = 0; i < n; i++)
        visited[i] = 0;
    visited[TBDel] = 1;
    for(i = 0; i < n; i++)
        if(!visited[i])
            DFS(G, i);
}
void travelBFSdel(VLink G[], int n, int TBDel)
{
    int i;
    for(i = 0; i < n; i++)
        visited[i] = 0;
    visited[TBDel] = 1;
    for(i = 0; i < n; i++)
        if(!visited[i])
            BFS(G, i);
}


int main()
{
    int pt, eg, i = 0, p1, p2, del;
    scanf("%d%d", &pt, &eg);
    while(i < eg)
    {
        scanf("%d%d", &p1, &p2);
        G[p1].link = insertEdge(G[p1].link, p2);
        G[p2].link = insertEdge(G[p2].link, p1);
        i++;
    }
    scanf("%d", &del);
    travelDFS(G, pt);
    printf("\n");
    travelBFS(G, pt);
    printf("\n");
    deleteVec(G, del, pt);
    travelDFSdel(G, pt, del);
    printf("\n");
    travelBFSdel(G, pt, del);
    
    
    return 0;
}