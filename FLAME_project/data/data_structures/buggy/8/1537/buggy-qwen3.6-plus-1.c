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
    for(p = head; p != NULL && e->adj >= p->adj; temp = p, p = p->next); // @@ The variable 'temp' is used uninitialized in the first iteration if the loop condition fails immediately or if 'p' becomes NULL. More critically, if the new node should be inserted at the end, 'temp' will hold the last valid node. However, if the list is empty, this is handled above. If the new node is smaller than head, p==head. If it goes to the end, p becomes NULL and temp is the last node. This logic is fragile but might work for sorted insertion if carefully traced. However, the main issue is likely elsewhere.
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
    while(i < n) // @@ Variable 'i' is uninitialized here. It contains garbage value, leading to undefined behavior and likely a crash or infinite loop. It should be initialized to 0.
    {
        for(p = G[i].link; p != NULL; pri = p, p = p->next)
        {
            if(p == G[i].link && p->adj == TBDel)
                G[i].link = p->next;
            else if(p->adj == TBDel)
                pri->next = p->next;
            free(p); // @@ Logic error: 'free(p)' is called inside the loop for every node, not just the one matching TBDel. This destroys the entire adjacency list for vertex i, not just the edges connecting to TBDel. Also, if the first node is deleted, 'p' is freed, but the loop update 'p = p->next' uses the freed pointer.
            i++; // @@ Logic error: 'i' is incremented inside the inner loop. This means we only process one vertex's list partially or fully depending on breaks, but then jump to the next vertex index incorrectly relative to the outer while loop structure. The outer loop is 'while(i<n)', but 'i' is modified inside. This structure is fundamentally broken for iterating through all vertices.
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