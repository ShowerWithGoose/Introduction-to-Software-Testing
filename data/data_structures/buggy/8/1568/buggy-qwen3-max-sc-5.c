#define MaxV 110

#include<stdio.h>
#include<stdlib.h>

typedef struct _Elink {
    int adj;
    struct _Elink* next;
}Elink,*Elinkptr;

typedef struct _Vlink {
    Elinkptr link;
}Vlink, Vlinkptr; // @@ [Vlinkptr is defined as a non-pointer type, but it should be a pointer type like 'Vlink*' to match typical usage. However, this doesn't cause a compilation error directly.]

Vlink graph[MaxV];
int nv, ne;
int visited[MaxV] = { 0 };
int Queue[MaxV];
int front = 0, rear = -1;

void createGraph();
void deleteVex(int v);
void travelDFS();
void DFS(Vlink graph[], int v);
void travelBFS();
void BFS(Vlink graph[], int v);
Elinkptr insertEdge(Elinkptr head, int avex);
void enQueue(int Queue[], int v);
int isEmpty(int Queue[]);
int deQueue(int Queue[]);

int main() {
    createGraph();
    travelDFS();
    printf("\n");
    travelBFS();
    printf("\n");
    int v;
    scanf("%d", &v);
    deleteVex(v);
    travelDFS();
    printf("\n");
    travelBFS();
    printf("\n");
    return 0;
}

void createGraph() {
    scanf("%d%d", &nv, &ne);
    for (int i = 0; i < ne; i++) {
        int v1, v2;
        scanf("%d%d", &v1, &v2);
        graph[v1].link = insertEdge(graph[v1].link, v2);
        graph[v2].link = insertEdge(graph[v2].link, v1);
    }
}

Elinkptr insertEdge(Elinkptr head, int avex) {
    Elinkptr e = (Elinkptr)malloc(sizeof(Elink));
    e->adj = avex;
    e->next = NULL;
    if (head == NULL) {
        head = e;
        return head;
    }
    else {
        Elinkptr p;
        if (e->adj < head->adj) {
            e->next = head->next; // @@ [This is incorrect: when inserting before the head, e should point to head, not head->next. It should be 'e->next = head;' and then return e.]
            head->next = e;
        }
        else {
            for (p = head; p->next != NULL && e->adj > p->next->adj; p = p->next)
                ;
            if (p->next == NULL) {
                e->next = NULL;
                p->next = e;
            }
            else {
                e->next = p->next;
                p->next = e;
            }
        }
        return head;
    }
}

void deleteVex(int v) {
    graph[v].link = NULL;
    for (int i = 0; i < nv; i++) {
        for (Elinkptr p = graph[i].link, q = graph[i].link; p != NULL; q = p, p = p->next) {
            if (p->adj == v) {
                if (p == graph[i].link) {
                    graph[i].link = p->next;
                    continue; // @@ [After updating head, loop should break or adjust q/p correctly; continuing may skip checking new head if multiple occurrences exist (though shouldn't in simple graph). More critically, 'continue' skips the rest but p is advanced by loop, which may cause issues. Also, q is not updated properly in head case.]
                }
                if (p->next == NULL) {
                    q->next = NULL;
                    continue;
                }
                q->next = p->next;
            }
        }
    }
}

void travelDFS() {
    for (int i = 0; i < nv; i++) 
         visited[i] = 0;
    for (int j = 0; j < nv; j++) 
        if (!visited[j]) DFS(graph, j); // @@ [Problem requires traversal to start from vertex 0 always, but this loops over all vertices and starts DFS from every unvisited vertex. This violates requirement #3.]
}

void DFS(Vlink graph[], int v) {
    if (graph[v].link != NULL) { // @@ [This condition is wrong: even if a vertex has no neighbors (degree 0), it should still be printed if visited. But per problem, graph is connected and n>=3, so maybe not triggered. However, after deletion, a vertex might become isolated but still needs to be traversed if reachable. Also, starting from 0, if 0 becomes isolated after deletion, this would skip printing it.]
        printf("%d ", v);
        visited[v] = 1;
        for (Elinkptr p = graph[v].link; p != NULL; p = p->next)
            if (!visited[p->adj]) DFS(graph, p->adj);
    }
}

void travelBFS() {
    for (int i = 0; i < nv; i++)
        visited[i] = 0;
    for (int j = 0; j < nv; j++)
        if (!visited[j]) BFS(graph, j); // @@ [Same issue as travelDFS: must start only from vertex 0, not all unvisited vertices.]
}

void BFS(Vlink graph[], int v) {
    if (graph[v].link != NULL) { // @@ [Same issue as DFS: if vertex v has no neighbors, it won't be printed, which is incorrect. Vertex should be printed upon visit regardless of degree.]
        printf("%d ", v);
        visited[v] = 1;
        enQueue(Queue, v);
        while (!isEmpty(Queue)) {
            int vex = deQueue(Queue);
            for (Elinkptr p = graph[vex].link; p != NULL; p = p->next) {
                if (!visited[p->adj]) {
                    printf("%d ", p->adj);
                    visited[p->adj] = 1;
                    enQueue(Queue, p->adj);
                }
            }
        }
    }
}

void enQueue(int Queue[], int v) {
    rear = (rear + 1) % MaxV;
    Queue[rear] = v;
}

int isEmpty(int Queue[]) {
    return front > rear ? 1 : 0; // @@ [This implementation of isEmpty is incorrect for a circular queue. It assumes linear array, but enQueue uses modulo. After wrap-around, front could be > rear but queue not empty. Should use standard circular queue empty condition: front == (rear+1)%MaxV or track count. However, since BFS only runs once and queue size <= nv <=100 < MaxV=110, wrap-around may not occur, so might work accidentally. But logically flawed.]
}

int deQueue(int Queue[]) {
    if (!isEmpty(Queue)) {
        int v = Queue[front];
        front = (front + 1) % MaxV; // @@ [front is incremented with modulo, but isEmpty doesn't account for circularity, leading to potential inconsistency.]
        return v;
    }
}