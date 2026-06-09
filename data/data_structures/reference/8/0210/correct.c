#include <stdio.h>
#include <stdlib.h>

typedef struct edge {
    int v;
    struct edge* next;
} edge;

typedef struct vertex {
    struct edge* next;
} vertex;

int visited[100] = {0};

edge* insert(edge* g, int v) {
    edge* e = (edge*)malloc(sizeof(edge));
    e->v = v;
    if (g == NULL || g->v > v) {
        e->next = g;
        g = e;
    } else {
        edge* p = g;
        while (p->next != NULL && p->next->v < v) {
            p = p->next;
        }
        e->next = p->next;
        p->next = e;
    }
    return g;
}

void DFS(vertex* g, int v) {
    printf("%d ", v);
    visited[v] = 1;
    edge* e = g[v].next;
    while (e != NULL) {
        if (visited[e->v] == 0) {
            DFS(g, e->v);
        }
        e = e->next;
    }
}

void BFS(vertex* g, int v) {
    int i;
    edge* e;
    for (i = 0; i < 100; i++) {
        visited[i] = 0;
    }
    printf("%d ", v);
    visited[v] = 1;
    edge* queue[100];
    int front = 0;
    int rear = 0;
    queue[rear++] = g[v].next;
    while (front < rear) {
        e = queue[front++];
        while (e != NULL) {
            if (visited[e->v] == 0) {
                printf("%d ", e->v);
                visited[e->v] = 1;
                queue[rear++] = g[e->v].next;
            }
            e = e->next;
        }
    }
}

edge* deleteEdge(edge* g, int w) {
    edge* e = g;
    if (e->v == w) {
        g = e->next;
        free(e);
        return g;
    }
    while (e->next != NULL) {
        if (e->next->v == w) {
            e->next = e->next->next;
            return g;
        }
        e = e->next;
    }
}

void delete (vertex* graph, int v) {
    edge* e = graph[v].next;
    while (e != NULL) {
        int w = e->v;
        graph[w].next = deleteEdge(graph[w].next, v);
        e = e->next;
    }
    graph[v].next = NULL;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int det;

    vertex graph[100];
    for (int i = 0; i < n; i++) {
        graph[i].next = NULL;
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].next = insert(graph[u].next, v);
        graph[v].next = insert(graph[v].next, u);
    }
    scanf("%d", &det);
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            DFS(graph, i);
        }
    }
    printf("\n");
    visited[0] = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            BFS(graph, i);
        }
    }
    printf("\n");

    delete (graph, det);
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0 && i != det) {
            DFS(graph, i);
        }
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (visited[i] == 0 && i != det) {
            BFS(graph, i);
        }
    }

    return 0;
}
