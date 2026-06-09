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
        G[i].link = (struct head *)malloc(sizeof(struct head)); // @@ [Type mismatch: G[i].link is GRA*, but malloc returns struct head*. Also, logic error: the head node itself should likely just be a pointer to the first edge, or if using a dummy head, it shouldn't store data in a way that conflicts with edge nodes. However, the critical error here is treating the head structure as an edge node.]
        G[i].link->data = i; // @@ [Logical Error: The head node's 'data' field is being set to the vertex index. In the traversal functions (DFS/BFS), the code iterates starting from G[v].link. If G[v].link is a dummy head containing the vertex index, the traversal will print/process the head node itself as if it were a neighbor, or skip the actual first neighbor depending on implementation. Given the 'in' function inserts after checking p->next, and DFS starts with p=G[v].link, this structure is confused. Typically, adjacency list heads are just pointers to the first edge node, not nodes themselves containing vertex data.]
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
    q = (struct head *)malloc(sizeof(struct head)); // @@ [Type mismatch: q is GRA*, but malloc allocates struct head. Should be sizeof(GRA).]
    q->data = b;
    q->next = NULL;
    while (p->next != NULL && p->next->data < b) // @@ [Logical Error: This assumes G[a].link is a dummy head node. If creathead sets G[a].link to a node with data=a, this loop skips that node. However, if the intention is that G[a].link points directly to the first neighbor, this loop condition p->next implies p is a predecessor. If G[a].link is the first edge, we need to handle insertion at the head separately. Given creathead initializes G[i].link as a node with data=i, this code treats G[i].link as a dummy head. But DFS/BFS traverse starting from G[v].link directly.]
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
        free(t); // @@ [Critical Logic Error: This frees the existing next node instead of linking q before it. It should be q->next = t; free(t) is wrong because t is a valid node in the list that should remain, just shifted. Correct logic: q->next = p->next; p->next = q;]
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
    for (p = G[v].link; p != NULL; p = p->next) // @@ [Logical Error: If G[v].link is a dummy head node (as created in creathead), this loop will process the dummy node (printing its data, which is v) again or incorrectly. It should start from p = G[v].link->next if G[v].link is a dummy head. If G[v].link is the first actual edge, then creathead is wrong. Given the mix, this traversal is flawed.]
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
        p = G[v].link; // @@ [Logical Error: Same as DFS. If G[v].link is a dummy head, p points to the dummy head. The loop below will process the dummy head's data as a neighbor.]
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
    
    return 0; // @@ [Incomplete Implementation: The program reads input but performs no output. It lacks calls to DFS/BFS for the "before deletion" state, logic to delete the vertex and its edges, and calls to DFS/BFS for the "after deletion" state.]
}