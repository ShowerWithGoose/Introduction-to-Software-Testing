#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct chainlist {
    int val;
    struct chainlist *link;
} * nodePtr, node;
int visited[128];
void insert(nodePtr prevNode, int newitem)
{
    nodePtr newNode = (nodePtr)malloc(sizeof(node));
    newNode->val = newitem;
    newNode->link = prevNode->link;
    prevNode->link = newNode;
    return;
}
void DFSsingleVertex(nodePtr *g, int vertex)
{
    nodePtr p;
    if (!visited[vertex]) {
        visited[vertex] = 1;
        printf("%d ", g[vertex]->val);
    }
    for (p = g[vertex]; p != NULL; p = p->link) {
        if (!visited[p->val]) DFSsingleVertex(g, p->val);
    }
}
void BFSsingleVertex(nodePtr *g, int vertex)
{
    nodePtr p;
    int queue[512], front = 0, rear = 0;
    if (!visited[vertex]) {
        visited[vertex] = 1;
        queue[rear++] = vertex;
        while (front < rear) {
            printf("%d ", queue[front]);
            for (p = g[queue[front]]; p != NULL; p = p->link) {
                if (!visited[p->val]) {
                    visited[p->val] = 1;
                    queue[rear++] = p->val;
                }
            }
            front++;
        }
    }
}
int main()
{
    nodePtr graph[128], ptr;
    int v, e, tmpv1, tmpv2, rm;
    scanf("%d%d", &v, &e);
    for (int i = 0; i < v; ++i) {
        graph[i] = (nodePtr)malloc(sizeof(node));
        graph[i]->val = i;
        graph[i]->link = NULL;
    }
    for (int i = 0; i < e; ++i) {
        scanf("%d%d", &tmpv1, &tmpv2);
        ptr = graph[tmpv1];
        while (ptr->link != NULL && ptr->link->val < tmpv2)
            ptr = ptr->link;
        insert(ptr, tmpv2);
        ptr = graph[tmpv2];
        while (ptr->link != NULL && ptr->link->val < tmpv1)
            ptr = ptr->link;
        insert(ptr, tmpv1);
    }
    scanf("%d", &rm);
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < v; i++)
        DFSsingleVertex(graph, i);
    printf("\n");
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < v; i++)
        BFSsingleVertex(graph, i);
    printf("\n");
    memset(visited, 0, sizeof(visited));
    visited[rm] = 1;
    for (int i = 0; i < v; i++)
        DFSsingleVertex(graph, i);
    printf("\n");
    memset(visited, 0, sizeof(visited));
    visited[rm] = 1;
    for (int i = 0; i < v; i++)
        BFSsingleVertex(graph, i);
    return 0;
}

