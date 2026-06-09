#define MaxV 110

#include<stdio.h>
#include<stdlib.h>

typedef struct _Elink {
    int adj;
    struct _Elink* next;
}Elink,*Elinkptr;

typedef struct _Vlink {
    Elinkptr link;
}Vlink, Vlinkptr;

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
            e->next = head->next; // @@ Error: Should be e->next = head; not head->next. This incorrectly links e to the second node instead of the head.
            head->next = e; // @@ Error: This line is also wrong; it should be head = e; to make e the new head.
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
                    continue; // @@ Error: After updating the head, the loop continues without updating p and q properly, causing potential infinite loop or incorrect traversal.
                }
                if (p->next == NULL) {
                    q->next = NULL;
                    continue; // @@ Error: Same issue as above; continue without proper pointer updates leads to incorrect behavior.
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
        if (!visited[j]) DFS(graph, j);
}

void DFS(Vlink graph[], int v) {
    if (graph[v].link != NULL) { // @@ Error: This condition skips printing vertex v if it has no outgoing edges, but the vertex should still be visited and printed even if isolated (though graph is connected, after deletion a vertex might have no edges).
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
        if (!visited[j]) BFS(graph, j);
}

void BFS(Vlink graph[], int v) {
    if (graph[v].link != NULL) { // @@ Error: Same issue as DFS; vertex v should be visited and printed even if it has no edges after deletion.
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
    return front > rear ? 1 : 0; // @@ Error: This condition is incorrect for a circular queue; it should check front == (rear+1)%MaxV or use a different method to track emptiness.
}

int deQueue(int Queue[]) {
    if (!isEmpty(Queue)) {
        int v = Queue[front];
        front = (front + 1) % MaxV;
        return v;
    }
}