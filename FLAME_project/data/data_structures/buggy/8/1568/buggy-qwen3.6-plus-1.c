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
        if (e->adj < head->adj) { // @@ The logic for inserting at the head is incorrect. It sets e->next to head->next instead of head, effectively skipping the original head node and losing it from the list if not handled carefully, but more importantly, it doesn't attach the old head after e. It should be e->next = head; head = e;
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
    if (graph[v].link != NULL) { // @@ This condition prevents visiting isolated vertices (vertices with no edges). Although the problem states the graph is connected, after deletion, a vertex might become isolated if it only connected to the deleted vertex? No, problem says graph remains connected. However, standard DFS should visit a node regardless of whether it has neighbors, as long as it hasn't been visited. The main issue here is that if a vertex has no neighbors, it is still a valid vertex to visit in the traversal sequence if it's part of the component. But wait, if graph[v].link is NULL, it means no neighbors. In a connected graph with n>=3, only possible if n=1 which is not allowed. So this might not be the primary error for connectivity, but it's semantically wrong for general DFS. More critically, look at BFS.
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
    if (graph[v].link != NULL) { // @@ Similar to DFS, this check is problematic. But the bigger issue in BFS is below.
        printf("%d ", v);
        visited[v] = 1;
        enQueue(Queue, v);
        while (!isEmpty(Queue)) {
            int vex = deQueue(Queue);
            for (Elinkptr p = graph[vex].link; p != NULL; p = p->next) {
                if (!visited[p->adj]) {
                    printf("%d ", p->adj); // @@ Printing here causes vertices to be printed when they are discovered/enqueued, not when they are dequeued/processed. Standard BFS prints when dequeuing. This changes the order and potentially duplicates or misses depending on implementation details, but primarily it violates the standard "visit when dequeued" convention which ensures correct level-order processing output. Also, the starting vertex 'v' is printed before the loop, then dequeued. Its neighbors are printed immediately. Then those neighbors are dequeued, and THEIR neighbors are printed. This actually produces a valid BFS order in terms of levels, but let's look closer. If we print when enqueueing, we print 'v' first (manually), then enqueue 'v'. Dequeue 'v', print neighbors. Enqueue neighbors. Dequeue neighbor1, print its unvisited neighbors. This is technically a valid BFS traversal output order (discovery order). However, compare with DFS. DFS prints when entering. BFS usually prints when leaving queue. Let's re-read the requirement. "Output the vertex sequences". Usually, both DFS and BFS outputs correspond to the order in which nodes are *visited* (processed). In DFS, processing happens on entry. In BFS, processing happens on dequeue. If we print on enqueue for BFS, the order is different from printing on dequeue. For example, if 0 connects to 1 and 2. Print 0. Enqueue 0. Dequeue 0. Print 1, Enqueue 1. Print 2, Enqueue 2. Dequeue 1. Print... Output: 0 1 2. If we printed on dequeue: Print 0. Enqueue 0. Dequeue 0, Print 0 (wait, already printed?). Standard BFS: Mark visited, Enqueue. While Q not empty: Dequeue u, Print u. For each neighbor w of u: if not visited, mark visited, Enqueue w.
                    // The current code: Print v (start). Mark visited. Enqueue v.
                    // Loop: Dequeue vex. (vex is v first time).
                    // For neighbors: if not visited, Print neighbor, Mark visited, Enqueue neighbor.
                    // This means the start node is printed BEFORE the loop. The other nodes are printed WHEN THEY ARE ENQUEUED.
                    // Correct BFS should print when DEQUEUED.
                    // Let's trace correct BFS for 0-1, 0-2.
                    // Start 0. Visited[0]=1. Enqueue 0. Q: [0].
                    // Dequeue 0. Print 0. Neighbors 1, 2.
                    // Neighbor 1: Not visited. Visited[1]=1. Enqueue 1. Q: [1].
                    // Neighbor 2: Not visited. Visited[2]=1. Enqueue 2. Q: [1, 2].
                    // Dequeue 1. Print 1. Neighbors of 1...
                    // Dequeue 2. Print 2.
                    // Output: 0 1 2.
                    // Current Code Trace:
                    // Start 0. Print 0. Visited[0]=1. Enqueue 0. Q: [0].
                    // Dequeue 0. vex=0.
                    // Neighbor 1: Not visited. Print 1. Visited[1]=1. Enqueue 1. Q: [1].
                    // Neighbor 2: Not visited. Print 2. Visited[2]=1. Enqueue 2. Q: [1, 2].
                    // Dequeue 1. vex=1.
                    // ...
                    // Output: 0 1 2.
                    // It seems the output is the same for this simple case. Is there a case where it differs?
                    // Consider 0-1, 1-2, 0-2.
                    // Correct BFS (Print on Dequeue):
                    // Start 0. Enqueue 0.
                    // Dequeue 0. Print 0.
                    // Neighbors 1, 2.
                    // Visit 1. Enqueue 1.
                    // Visit 2. Enqueue 2.
                    // Dequeue 1. Print 1.
                    // Neighbors 0 (visited), 2 (visited).
                    // Dequeue 2. Print 2.
                    // Output: 0 1 2.
                    // Current Code (Print on Enqueue + Start Print):
                    // Start 0. Print 0. Enqueue 0.
                    // Dequeue 0.
                    // Neighbor 1. Print 1. Enqueue 1.
                    // Neighbor 2. Print 2. Enqueue 2.
                    // Dequeue 1.
                    // Neighbors 0 (visited), 2 (visited).
                    // Dequeue 2.
                    // Output: 0 1 2.
                    // It seems identical for connected graphs starting at 0.
                    // However, the BUG is likely in `insertEdge`.
                    // Let's re-examine `insertEdge`.
                    // if (e->adj < head->adj) {
                    //     e->next = head->next; // @@ ERROR: Should be e->next = head;
                    //     head->next = e;       // @@ ERROR: This makes head point to e, but e points to what head USED TO point to. The original head is now orphaned if head was the only element, or inserted second.
                    // }
                    // Example: Insert 1 into empty list. Head=NULL. Handled by first if.
                    // Insert 0 into list [1]. Head points to 1. e is 0.
                    // 0 < 1.
                    // e->next = head->next (which is NULL).
                    // head->next = e (1->next = 0).
                    // List becomes 1 -> 0.
                    // But it should be 0 -> 1.
                    // So the adjacency list is sorted incorrectly or broken.
                    // If I insert 2 into [1->0].
                    // Head is 1. e is 2.
                    // 2 < 1 is false.
                    // Loop: p=1. p->next is 0. 2 > 0 is true. p becomes 0.
                    // p->next is NULL.
                    // Append 2. List: 1 -> 0 -> 2.
                    // This is not sorted.
                    // The requirement is "visit them in ascending order".
                    // So the adjacency list MUST be sorted in ascending order.
                    // The `insertEdge` function fails to maintain ascending order.
                    
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
    return front > rear ? 1 : 0;
}

int deQueue(int Queue[]) {
    if (!isEmpty(Queue)) {
        int v = Queue[front];
        front = (front + 1) % MaxV;
        return v;
    }
}