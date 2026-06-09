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
        if (e->adj < head->adj) { // @@ The logic for inserting at the head is incorrect. It sets e->next to head->next instead of head, effectively skipping the original head node and losing it from the list. It should be e->next = head;
            e->next = head->next;
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
                    continue;
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
        if (!visited[j]) DFS(graph, j);
}

void DFS(Vlink graph[], int v) {
    if (graph[v].link != NULL) { // @@ This condition incorrectly prevents visiting isolated vertices (vertices with no edges). Although the problem states the graph is connected, after deletion, a vertex might become isolated if it only connected to the deleted vertex, or more importantly, the standard DFS should visit the node regardless of edges if it's part of the component. However, the bigger issue is that `visited` is set inside. If a node has no links, it is never visited/marked, potentially causing issues in traversal logic if not handled by the loop in travelDFS. But specifically here, if a node is isolated, it should still be printed if reached. The check `graph[v].link != NULL` means isolated nodes are never printed or marked visited.
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
    if (graph[v].link != NULL) { // @@ Similar to DFS, this prevents processing isolated vertices. An isolated vertex should be visited and printed.
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
    return front > rear ? 1 : 0; // @@ This circular queue empty check is incorrect for a general circular queue implementation where front and rear wrap around. However, since front starts at 0 and rear at -1, and we only increment, it works for simple cases until wrap-around. A standard check is front == (rear + 1) % MaxV for full, and front == rear for empty (if using a different convention). With current init (front=0, rear=-1), empty is indeed front > rear initially. But after wrap around, this fails. Given MaxV 110 and small inputs, it might pass, but logically fragile. More critically, if the queue wraps, `front > rear` is not a valid empty condition. Standard circular queue: empty if front == rear (if using one slot waste) or similar. Here, with rear starting at -1, empty is `front == rear + 1`? No. Let's look at `deQueue`. It doesn't check empty. `isEmpty` is used in `while`. If `front` wraps past `rear`, `front > rear` becomes true, stopping the loop prematurely even if elements exist.
}

int deQueue(int Queue[]) {
    if (!isEmpty(Queue)) {
        int v = Queue[front];
        front = (front + 1) % MaxV;
        return v;
    }
}