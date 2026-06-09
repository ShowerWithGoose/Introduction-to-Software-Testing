#define MaxV 110

#include<stdio.h>
#include<stdlib.h>

typedef struct _Elink {
    int adj;
    struct _Elink* next;
}Elink,*Elinkptr;

typedef struct _Vlink {
    Elinkptr link;
}Vlink, Vlinkptr; // @@ [Vlinkptr is defined as a non-pointer type, but used as a pointer type elsewhere (e.g., in function parameters like DFS(Vlink graph[], int v)), causing type inconsistency and potential compilation errors.]

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
            e->next = head->next; // @@ [This is incorrect: when inserting before head, e should point to head, not head->next. This breaks the adjacency list ordering and structure.]
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
                    continue; // @@ [After removing the head node, 'continue' skips updating 'q', but more critically, the loop condition uses 'q = p' before p moves, which may cause use-after-free or incorrect pointer updates. Also, 'continue' causes skipping of p = p->next, leading to infinite loop or crash.]
                }
                if (p->next == NULL) {
                    q->next = NULL;
                    continue; // @@ [Same issue: 'continue' skips p = p->next, causing potential infinite loop because p doesn't advance.]
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
        if (!visited[j]) DFS(graph, j); // @@ [The problem requires traversal to always start from vertex 0, but this loops over all vertices and starts DFS from every unvisited vertex, violating requirement #3.]
}

void DFS(Vlink graph[], int v) {
    if (graph[v].link != NULL) { // @@ [This condition excludes isolated vertices from being printed, but after deletion, vertex 0 might become isolated (though problem states graph remains connected), but more importantly, even if a vertex has no neighbors, it should still be printed when visited. The condition prevents printing vertex 0 if it has no edges after deletion, which violates traversal definition.]
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
        if (!visited[j]) BFS(graph, j); // @@ [Same as DFS: must start only from vertex 0, not all unvisited vertices. Violates requirement #3.]
}

void BFS(Vlink graph[], int v) {
    if (graph[v].link != NULL) { // @@ [Same issue as DFS: if vertex has no neighbors, it won't be printed, which is incorrect. Vertex should be printed upon visitation regardless of degree.]
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
    return front > rear ? 1 : 0; // @@ [This implementation of isEmpty is incorrect for a circular queue. It assumes linear array usage. After wrap-around (e.g., front=100, rear=5), front > rear is true but queue is not empty. Should use modulo-based logic like (front == (rear+1)%MaxV) or track count. This can cause BFS to terminate early or behave incorrectly.]
}

int deQueue(int Queue[]) {
    if (!isEmpty(Queue)) {
        int v = Queue[front];
        front = (front + 1) % MaxV; // @@ [While front update uses modulo, isEmpty does not account for circularity, leading to inconsistent queue state interpretation.]
        return v;
    }
}