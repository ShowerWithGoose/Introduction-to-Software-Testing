#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXVER 100
#define MAXSIZE 100
typedef int ELEMTYPE, *PELEMTYPE;
typedef struct queue {
    ELEMTYPE data[MAXSIZE];
    int count;
    int front;
    int rear;
} QUEUE, *PQUEUE;
typedef struct edge {
    int adjvex;
    struct edge *next;
} ELINK;
typedef struct ver {
    int vertex;
    ELINK *link;
} VLINK;
typedef struct vec {
    int vi;
    int vj;
} VEC;
void initqueue(const PQUEUE queue);
bool isempty(const PQUEUE queue);
bool isfull(const PQUEUE queue);
void enQueue(const PQUEUE queue, const ELEMTYPE elem);
ELEMTYPE deQueue(const PQUEUE queue);
void createGraph(VLINK G[], int vN, int eN);
void addSDVertex(VLINK G[], VEC v);
void DFS(VLINK G[], int v, int visited[]);
void travelDFS(VLINK G[], int visited[], int n);
void BFS(VLINK G[], int v, int visited[]);
void travelBFS(VLINK G[], int visited[], int n);
void delVer(VLINK G[], int *vN, int toDel);
void swap(int *a, int *b);
int comp(const void *p1, const void *p2);
int firstAdj(VLINK G[], int v);
int nextAdj(VLINK G[], int v, int w);
int main(int argc, char *argv[]) {
    VLINK G[MAXVER];
    int visited[MAXVER];
    int vN = 0;
    int eN = 0;
    int toDel = -1;
    scanf("%d %d", &vN, &eN);
    createGraph(G, vN, eN);
    scanf("%d", &toDel);
    travelDFS(G, visited, vN);
    travelBFS(G, visited, vN);
    delVer(G, &vN, toDel);
    travelDFS(G, visited, vN);
    travelBFS(G, visited, vN);
    return 0;
}
bool isempty(const PQUEUE queue) { return queue->count == 0; }
bool isfull(const PQUEUE queue) { return queue->count == MAXSIZE; }
void initqueue(const PQUEUE queue) {
    queue->count = 0;
    queue->front = 0;
    queue->rear = MAXSIZE - 1;
}
void enQueue(const PQUEUE queue, const ELEMTYPE elem) {
    if (!isfull(queue)) {
        queue->rear = (queue->rear + 1) % MAXSIZE;
        queue->data[queue->rear] = elem;
        queue->count++;
    }
}
ELEMTYPE deQueue(const PQUEUE queue) {
    ELEMTYPE ret;
    if (!isempty(queue)) {
        ret = queue->data[queue->front];
        queue->count--;
        queue->front = (queue->front + 1) % MAXSIZE;
    }
    return ret;
}
void createGraph(VLINK G[], int vN, int eN) {
    int k;
    VEC readings[MAXVER];
    for (k = 0; k < 2 * eN; k += 2) {
        scanf("%d %d", &readings[k].vi, &readings[k].vj);
        readings[k + 1].vi = readings[k].vj;
        readings[k + 1].vj = readings[k].vi;
    }
    qsort(readings, 2 * eN, sizeof(VEC), comp);
    for (k = 0; k < vN; k++) {
        G[k].vertex = k;
        G[k].link = NULL;
    }
    for (k = 0; k < 2 * eN; k++)
        addSDVertex(G, readings[k]);
}
void addSDVertex(VLINK G[], VEC v) {
    int k;
    ELINK *p, *q;
    p = (ELINK *)malloc(sizeof(ELINK));
    p->adjvex = v.vj;
    p->next = NULL;
    if (!G[v.vi].link)
        G[v.vi].link = p;
    else {
        q = G[v.vi].link;
        while (q->next)
            q = q->next;
        q->next = p;
    }
}
void DFS(VLINK G[], int v, int visited[]) {
    int w;
    printf("%d ", G[v].vertex);
    visited[v] = 1;
    w = firstAdj(G, v);
    while (w != -1) {
        if (visited[w] == 0) {
            DFS(G, w, visited);
        }
        w = nextAdj(G, v, w);
    }
}
void travelDFS(VLINK G[], int visited[], int n) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    for (int i = 0; i < n; i++)
        if (!visited[i])
            DFS(G, i, visited);
    printf("\n");
}
void BFS(VLINK G[], int v, int visited[]) {
    int w;
    QUEUE Q[MAXSIZE];
    initqueue(Q);
    printf("%d ", G[v].vertex);
    visited[v] = 1;
    enQueue(Q, v);
    while (!isempty(Q)) {
        v = deQueue(Q);
        w = firstAdj(G, v);
        while (w != -1) {
            if (visited[w] == 0) {
                printf("%d ", G[w].vertex);
                enQueue(Q, w);
                visited[w] = 1;
            }
            w = nextAdj(G, v, w);
        }
    }
}
void travelBFS(VLINK G[], int visited[], int n) {
    for (int i = 0; i < n; i++)
        visited[i] = 0;
    for (int i = 0; i < n; i++)
        if (!visited[i])
            BFS(G, i, visited);
    printf("\n");
}
void delVer(VLINK G[], int *vN, int toDel) {
    int k = -1;
    ELINK *p, *q, *r;
    for (int i = 0; i < *vN; i++) {
        if (G[i].vertex == toDel) {
            k = i;
            break;
        }
    }
    if (k != -1) {
        p = G[k].link;
        for (int i = k + 1; i < *vN; i++) {
            G[i - 1].vertex = G[i].vertex;
            G[i - 1].link = G[i].link;
        }
        (*vN)--;
        while (p != NULL) {
            r = p;
            p = p->next;
            free(r);
        }
        for (int i = 0; i < *vN; i++) {
            p = G[i].link;
            while (p != NULL) {
                if (p->adjvex == k) {
                    if (G[i].link == p)
                        G[i].link = p->next;
                    else
                        q->next = p->next;
                    r = p;
                    p = p->next;
                    free(r);
                } else {
                    if (p->adjvex > k)
                        p->adjvex--;
                    q = p;
                    p = p->next;
                }
            }
        }
    }
}
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int comp(const void *p1, const void *p2) {
    const VEC *ps1 = (const VEC *)p1;
    const VEC *ps2 = (const VEC *)p2;
    if (ps1->vi > ps2->vi)
        return 1;
    else if (ps1->vi == ps2->vi) {
        if (ps1->vj > ps2->vj)
            return 1;
        else if (ps1->vj == ps2->vj)
            return 0;
        else
            return -1;
    } else {
        return -1;
    }
}
int firstAdj(VLINK G[], int v) {
    if (G[v].link == NULL)
        return -1;
    else {
        return G[v].link->adjvex;
    }
}
int nextAdj(VLINK G[], int v, int w) {
    ELINK *p = G[v].link;
    while (p->adjvex != w) {
        p = p->next;
    }
    if (p->next == NULL) {
        return -1;
    } else {
        return p->next->adjvex;
    }
}



