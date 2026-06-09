#include <stdio.h>
#include <stdlib.h>

typedef struct graph
{
    int data;
    struct graph *next;
} GRA;

typedef struct head
{
    GRA *link;
} HEAD;
HEAD G[100];

void creathead(int n)
{
    for (int i = 0; i < n; i++)
    {
        G[i].link = (struct head *)malloc(sizeof(struct head)); // @@ [Type mismatch: G[i].link is GRA*, but malloc returns struct head*. Also, logic error: The head node itself should likely just be a pointer to the first edge, or if using a dummy head, it needs correct initialization. Here it allocates a 'head' struct but assigns to GRA*. This causes memory corruption/undefined behavior.]
        G[i].link->data = i; // @@ [Logic error: If G[i].link is meant to be the start of the adjacency list, setting its data to i (the vertex itself) is unusual for standard adjacency lists unless it's a dummy node. However, combined with the traversal logic below, this creates confusion. More critically, see the traversal code.]
        G[i].link->next = NULL;
    }
}

int visited[100] = {0};
int Q[100] = {0};

void creatQ(int Q[])
{
    for (int i = 0; i < 100; i++)
    {
        Q[i] = -1;
    }
}

void enQ(int Q[], int x)
{
    int i = 0;
    while (Q[i] != -1)
    {
        i++;
    }
    Q[i] = x;
}

int deQ(int Q[])
{
    int temp, i = 0, first = Q[0];
    while (Q[i] != -1)
    {
        Q[i] = Q[i + 1];
        i++;
    }
    return first;
}

void in(int a, int b)
{
    GRA *p = G[a].link, *q, *t;
    q = (struct head *)malloc(sizeof(struct head)); // @@ [Type mismatch: q is GRA*, but malloc allocates struct head. This is inconsistent with the typedefs and will cause issues if sizes differ or for clarity.]
    q->data = b;
    q->next = NULL;
    while (p->next != NULL && p->next->data < b)
    {
        p = p->next;
    }
    if (p->next == NULL)
    {
        p->next = q;
    }
    else
    {
        t = p->next;
        p->next = q;
        p->next->next = t;
        free(t); // @@ [Logic error: This deletes the existing node that was after p. This is not an insertion; it's a replacement that leaks the old node's successor chain if not handled carefully, but specifically here it frees 't' which was the original next node. This effectively removes edges from the graph instead of inserting new ones in sorted order. It should insert q before t, not free t.]
    }
}

int emptyQ(int Q[])
{
    if (Q[0] != -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void DFS(HEAD G[], int v)
{
    GRA *p;
    visited[v] = 1;
    printf("%d ", v);
    for (p = G[v].link; p != NULL; p = p->next) // @@ [Logic error: The loop starts at G[v].link. In creathead, G[v].link was initialized with data=v. So the first node visited in the adjacency list is the vertex itself. If visited[v] is already 1, the check !visited[p->data] will skip it. However, standard adjacency lists usually don't include the self-node as the head of the list unless it's a dummy. If it's a dummy, we should start at p->next. If it's not a dummy, the initialization in creathead is wrong. Given the BFS/DFS logic, it seems to treat G[v].link as the first neighbor. But creathead set G[v].link->data = v. So the first "neighbor" is v itself. This will be skipped by visited check. But wait, if the list is 0->1->2, and head is 0, then p starts at 0. visited[0] is 1. Skip. Next is 1. OK. But what if the graph is disconnected or structure is different? The main issue is usually that adjacency lists shouldn't have the source vertex as the first element unless it's a sentinel. Let's look at 'in'. 'in' inserts into G[a].link->next... wait. 'p = G[a].link'. Then it checks p->next. So it inserts after the head. So the head remains the dummy node with data=i. This means DFS/BFS must skip the head node or handle it. The current DFS loop `for (p = G[v].link; ...)` processes the head node. Since visited[v] is set to 1 before the loop, and head->data is v, it will be skipped. This might work accidentally for DFS start, but let's check BFS.]
    {
        if (!visited[p->data])
            DFS(G, p->data);
    }
}

void BFS(HEAD G[], int v)
{
    GRA *p;
    visited[v] = 1;
    printf("%d ", v);
    enQ(Q, v);
    while (emptyQ(Q))
    {
        v = deQ(Q);
        p = G[v].link; // @@ [Logic error: Similar to DFS, p starts at the head node (dummy) which has data=v. The loop below will check visited[p->data]. Since visited[v] is 1, it skips the dummy. Then it moves to real neighbors. This seems to rely on the dummy node behavior. However, there is a bigger problem: The program never calls DFS or BFS in main!]
        for (; p != NULL; p = p->next)
        {
            if (!visited[p->data])
            {
                printf("%d ", p->data);
                visited[p->data] = 1;
                enQ(Q, p->data);
            }
        }
    }
}

void emptyvisited(int n)
{
    for (int i = 0; i < n; i++)
        visited[i] = 0;
}

int main()
{
    int n, m;
    int delete;
    scanf("%d %d", &n, &m);
    creathead(n);
    creatQ(Q);
    for (int i = 0; i < m; i++)
    {
        int temp1, temp2;
        scanf("%d %d", &temp1, &temp2);
        in(temp1, temp2);
        in(temp2, temp1);
    }
    scanf("%d", &delete);
    emptyvisited(n);
    
    return 0; // @@ [Logic error: The program reads input but performs no output. It does not call DFS or BFS before deletion, nor does it handle the deletion of the vertex, nor does it call DFS/BFS after deletion. The entire logic for traversal and deletion is missing from main.]
}