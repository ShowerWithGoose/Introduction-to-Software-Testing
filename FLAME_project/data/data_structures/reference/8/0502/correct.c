#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX 205
#define MAX_QUEUE 500
typedef struct Edge
{
    int adjvex;
    int weight;
    struct Edge *next;
} Edge;

typedef struct Vertex
{
    Edge *link;
} Vertex;
Vertex graph[MAX_VERTEX];
int visited[MAX_VERTEX];
int vertex_num, edge_num;

int queue[MAX_QUEUE];
int front, rear = MAX_QUEUE - 1, count;

void create_graph(Vertex graph[]);
void travel_dfs(Vertex graph[], int n, int del);
void travel_bfs(Vertex graph[], int n, int del);

int main(int argc, const char *argv[])
{
    int del;
    scanf("%d %d", &vertex_num, &edge_num);
    create_graph(graph);
    travel_dfs(graph, vertex_num, 0);
    travel_bfs(graph, vertex_num, 0);
    scanf("%d", &del);
    travel_dfs(graph, vertex_num, del);
    travel_bfs(graph, vertex_num, del);
    return 0;
}

Edge *insert_edge(Edge *head, int adjvex)
{
    Edge *e, *p, *q = NULL;
    e = (Edge *)malloc(sizeof(Edge));
    e->adjvex = adjvex;
    e->weight = 1;
    e->next = NULL;
    if (head == NULL)
    {
        head = e;
        return head;
    }
    for (p = head; p != NULL && adjvex > p->adjvex; q = p, p = p->next)
        ;
    if (p == head)
    {
        e->next = p;
        return e;
    }
    else
    {
        q->next = e;
        e->next = p;
        return head;
    }
}

void create_graph(Vertex graph[])
{
    for (int i = 0; i < edge_num; i++)
    {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1].link = insert_edge(graph[v1].link, v2);
        graph[v2].link = insert_edge(graph[v2].link, v1);
    }
}

void dfs(Vertex graph[], int v)
{
    Edge *p;
    visited[v] = 1;
    printf("%d ", v);
    for (p = graph[v].link; p != NULL; p = p->next)
        if (!visited[p->adjvex])
            dfs(graph, p->adjvex);
}

void travel_dfs(Vertex graph[], int n, int del)
{
    int i;
    for (i = 0; i < n; i++)
        visited[i] = 0;
    if (del > 0)
        visited[del] = 1;
    for (i = 0; i < n; i++)
        if (!visited[i])
            dfs(graph, i);
    printf("\n");
}

int is_empty(void)
{
    return count == 0;
}

int is_full(void)
{
    return count == MAX_QUEUE;
}

void en_queue(int queue[], int item)
{
    if (is_full())
    {
        printf("Full queue!");
        exit(-1);
    }
    else
    {
        rear = (rear + 1) % MAX_QUEUE;
        queue[rear] = item;
        count++;
    }
}

int de_queue(int queue[])
{
    int de;
    if (is_empty())
    {
        printf("Empty queue!");
        exit(-1);
    }
    else
    {
        de = queue[front];
        count--;
        front = (front + 1) % MAX_QUEUE;
        return de;
    }
    return 0;
}

void bfs(Vertex graph[], int v)
{
    Edge *p;
    visited[v] = 1;
    en_queue(queue, v);
    while (!is_empty())
    {
        v = de_queue(queue);
        printf("%d ", v);
        for (p = graph[v].link; p != NULL; p = p->next)
            if (!visited[p->adjvex])
            {
                visited[p->adjvex] = 1;
                en_queue(queue, p->adjvex);
            }
    }
}

void travel_bfs(Vertex graph[], int n, int del)
{
    int i;
    for (i = 0; i < n; i++)
        visited[i] = 0;
    if (del > 0)
        visited[del] = 1;
    for (i = 0; i < n; i++)
        if (!visited[i])
            bfs(graph, i);
    printf("\n");
}
