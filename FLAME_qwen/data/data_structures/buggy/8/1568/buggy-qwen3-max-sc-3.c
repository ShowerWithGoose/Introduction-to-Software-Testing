#define MaxV 110

#include<stdio.h>
#include<stdlib.h>

typedef struct _Elink {
    int adj;
    struct _Elink* next;
}Elink,*Elinkptr;

typedef struct _Vlink {
    Elinkptr link;
}Vlink, Vlinkptr; // @@ [Vlinkptr is defined as a non-pointer type, but it should be a pointer type like *Vlinkptr to match typical usage; however, this doesn't cause compilation error directly. The real issue is in insertEdge logic.]

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
            e->next = head->next; // @@ [This is incorrect: when inserting before head, e->next should be head, not head->next. This breaks the list and causes missing nodes or infinite loops.]
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
                    continue; // @@ [After updating head, 'continue' skips the rest but 'q' is not updated properly for next iteration; also, the loop condition uses both p and q which may lead to use-after-free or incorrect traversal. More critically, the inner loop does not break after deletion, leading to potential access of freed memory if multiple edges to 'v' existed (though input says no duplicates).]
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
        if (!visited[j]) DFS(graph, j); // @@ [Problem requires traversal to start from vertex 0 always, but this iterates from 0 to nv-1 and starts DFS on every unvisited node. Since graph is connected, it should only start at 0. This violates requirement #3.]
}

void DFS(Vlink graph[], int v) {
    if (graph[v].link != NULL) { // @@ [This condition is wrong: even if a vertex has no neighbors (degree 0), it should still be printed if visited. But per problem, graph is connected and n>=3, and deleted vertex isn't 0, so vertex 0 always has neighbors. However, after deletion, a vertex might become isolated but still must be traversed if reachable. But since graph remains connected, maybe okay. However, the bigger issue is that this skips printing isolated vertices, which shouldn't occur per problem constraints, but the logic is flawed in general. Also, the print happens before marking visited, which is okay, but the condition excludes vertices with no edges, which violates traversal definition.]
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
        if (!visited[j]) BFS(graph, j); // @@ [Same as DFS: should only start from vertex 0, not iterate over all vertices. Violates requirement #3.]
}

void BFS(Vlink graph[], int v) {
    if (graph[v].link != NULL) { // @@ [Same issue as DFS: skips printing vertex if it has no adjacent edges. Also, the BFS implementation prints the starting vertex here, but then enqueues it and processes neighbors. However, if the vertex has no neighbors, it's never printed due to this condition, which is wrong.]
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
    return front > rear ? 1 : 0; // @@ [This queue implementation is not circular correctly. When rear wraps around (e.g., rear=MaxV-1, then rear=0), front could be > rear even when queue is not empty. Should use modulo-based circular queue logic like (front == (rear+1)%MaxV) for full, but here isEmpty is used only in BFS. However, the bigger issue is that front and rear are global and not reset between BFS calls, causing second BFS to fail. Also, initial rear=-1, so first enqueue makes rear=0, front=0 — then isEmpty returns 0 (since 0 > -1 is false → returns 0), which is correct. But after first BFS, front and rear are left in a state that breaks the second BFS. Global queue state is not reinitialized.]
}

int deQueue(int Queue[]) {
    if (!isEmpty(Queue)) {
        int v = Queue[front];
        front = (front + 1) % MaxV; // @@ [front is incremented modulo MaxV, but isEmpty uses simple comparison (front > rear), which fails when front wraps around. For example, if front=MaxV-1, then front becomes 0, and if rear=5, then front(0) < rear(5), so isEmpty returns 0 (not empty), but actual elements may have been dequeued. This leads to incorrect queue state and possible out-of-bounds or missed elements.]
        return v;
    }
}