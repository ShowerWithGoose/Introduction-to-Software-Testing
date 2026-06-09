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
        G[i].link = (struct head *)malloc(sizeof(struct head)); // @@ Incorrect type and size allocation; G[i].link is a pointer to GRA, so it should allocate sizeof(GRA) and cast to GRA*.
        G[i].link->data = i;
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
    q = (struct head *)malloc(sizeof(struct head)); // @@ Incorrect type and size allocation; should allocate sizeof(GRA) and cast to GRA*.
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
        free(t); // @@ Logical error; incorrectly frees the existing next node, which destroys the rest of the adjacency list instead of properly inserting the new node.
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
    for (p = G[v].link; p != NULL; p = p->next)
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
        p = G[v].link;
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
    emptyvisited(n); // @@ Missing required DFS and BFS traversal calls before and after deletion, and missing implementation for deleting the specified vertex.
    
    return 0; // @@ Program terminates without producing any output as required by the problem statement.
}