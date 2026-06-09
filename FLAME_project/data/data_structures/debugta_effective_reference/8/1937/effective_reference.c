#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct chainlist {
    int val;
    struct chainlist *link;
} * nodePtr, node;
int visit[128];
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
    if (!visit[vertex]) {
        visit[vertex] = 1;
        printf("%d ", g[vertex]->val);
    }
    for (p = g[vertex]; p != NULL; p = p->link) {
        if (!visit[p->val]) DFSsingleVertex(g, p->val);
    }
}
void BFSsingleVertex(nodePtr *g, int vertex)
{
    nodePtr p;
    int queue[512], front = 0, rear = 0;
    if (!visit[vertex]) {
        visit[vertex] = 1;
        queue[rear++] = vertex;
        while (front < rear) {
            printf("%d ", queue[front]);
            for (p = g[queue[front]]; p != NULL; p = p->link) {
                if (!visit[p->val]) {
                    visit[p->val] = 1;
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
    int n, m, k1, k2, de;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
        graph[i] = (nodePtr)malloc(sizeof(node));
        graph[i]->val = i;
        graph[i]->link = NULL;
    }
    for (int i = 0; i < m; ++i) {
        scanf("%d%d", &k1, &k2);
        ptr = graph[k1];
        while (ptr->link != NULL && ptr->link->val < k2)
            ptr = ptr->link;
        insert(ptr, k2);
        ptr = graph[k2];
        while (ptr->link != NULL && ptr->link->val < k1)
            ptr = ptr->link;
        insert(ptr, k1);
    }
    scanf("%d", &de);
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < n; i++)
        DFSsingleVertex(graph, i);
    printf("\n");
    memset(visit, 0, sizeof(visit));
    for (int i = 0; i < n; i++)
        BFSsingleVertex(graph, i);
    printf("\n");
    memset(visit, 0, sizeof(visit));
    visit[de] = 1;
    for (int i = 0; i < n; i++)
        DFSsingleVertex(graph, i);
    printf("\n");
    memset(visit, 0, sizeof(visit));
    visit[de] = 1;
    for (int i = 0; i < n; i++)
        BFSsingleVertex(graph, i);
    return 0;
}

