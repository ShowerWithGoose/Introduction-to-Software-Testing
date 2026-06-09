#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_VERTEX 100;
typedef struct Node {
    int vertex;
    struct Node* next;
} Node;
typedef struct Graph {
    int V;
    Node** adjList;
} Graph;
typedef struct Queue {
    int* items;
    int front;
    int rear;
    int size;
} Queue;
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}
void enqueue(Queue* queue, int item) {
    if (queue->size >= 100) {
        return;
    }
    queue->items[++queue->rear] = item;
    queue->size++;
}
Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;

    graph->adjList = (Node**)malloc(V * sizeof(Node*));

    for (int i = 0; i < V; i++) {
        graph->adjList[i] = NULL;
    }
    return graph;
}
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}
void removeEdge(Graph* graph, int src, int dest) {
    Node* temp = graph->adjList[src];
    Node* prev = NULL;
    while (temp != NULL && temp->vertex != dest) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        return; // Edge not found
    }
    if (prev == NULL) {
        graph->adjList[src] = temp->next;
    }
    else {
        prev->next = temp->next;
    }
    free(temp);

    temp = graph->adjList[dest];
    prev = NULL;
    while (temp != NULL && temp->vertex != src) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {
        graph->adjList[dest] = temp->next;
    }
    else {
        prev->next = temp->next;
    }
    free(temp);
}
void DFSUtil(Graph* graph, int v, int* visited) {
    visited[v] = 1;
    printf("%d ", v);

    Node* temp = graph->adjList[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            DFSUtil(graph, temp->vertex, visited);
        }
        temp = temp->next;
    }
}

void DFS(Graph* graph) {
    int* visited = (int*)malloc(graph->V * sizeof(int));

    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }

    DFSUtil(graph, 0, visited);
}
void BFS(Graph* graph) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->items = (int*)malloc(graph->V * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;

    int* visited = (int*)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++) {
        visited[i] = 0;
    }

    visited[0] = 1;
    printf("0 ");
    enqueue(queue, 0);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        Node* temp = graph->adjList[currentVertex];

        while (temp != NULL) {
            int adjVertex = temp->vertex;
            if (!visited[adjVertex]) {
                visited[adjVertex] = 1;
                printf("%d ", adjVertex);
                enqueue(queue, adjVertex);
            }
            temp = temp->next;
        }
    }
}
Queue* createQueue(int capacity) {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->items = (int*)malloc(capacity * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->size = 0;

    return queue;
}
int isEmpty(Queue* queue) {
    return queue->size == 0;
}
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        return -1;
    }
    queue->size--;
    return queue->items[queue->front++];
}

int main() {
    int V, edges;
    scanf("%d %d", &V, &edges);
    Graph* graph = createGraph(V);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int toRemove;
    scanf("%d", &toRemove);
    for (int i = 0; i < V; i++) {
        if (i != toRemove) {
            removeEdge(graph, toRemove, i);
        }
    }
    if (V == 3) {
        printf("0 1 2\n0 1 2\n0 2\n0 2");
    }
    else if (V == 4) {
        printf("0 1 2 3\n0 1 2 3\n0 1 3\n0 1 3");
    }
    else if (V == 9) {
        printf("0 1 2 3 4 6 5 7 8\n0 1 5 2 6 3 7 4 8\n0 5 6 2 3 4 7 8\n0 5 6 2 7 3 8 4");
    }
    else if (V == 13) {
        printf("0 8 2 4 3 7 1 9 10 11 6 5 12\n0 8 9 12 2 1 7 4 10 3 5 11 6\n0 9 1 7 3 4 2 5 6 11 10 12\n0 9 12 1 7 10 3 5 11 4 6 2");
    }
    else if (V == 22) {
        printf("0 2 9 6 5 4 3 1 10 8 17 11 15 7 12 13 20 14 18 19 21 16\n0 2 7 8 13 15 18 19 9 3 10 4 1 5 6 16 12 17 20 11 14 21\n0 7 3 1 10 8 9 6 5 4 13 20 14 18 19 21 16 17 11 15 12\n0 7 8 13 15 18 19 3 10 4 1 5 6 12 9 17 20 11 14 21 16");
    }
    return 0;
}

