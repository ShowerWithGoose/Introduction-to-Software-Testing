#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int vertexnum;
struct Arcnode {
    int adjvex;
    struct Arcnode* nextarc;
    int weigh;
};
struct headnode {
    struct Arcnode* first;

};
struct vertex {
    struct headnode Adjlist[1000];
    int vexnum;
    int arcnum;
};
struct vertex graph;
void insertSorted(struct Arcnode** head, int adjVertex) {
    struct Arcnode* newNode = (struct Arcnode*)malloc(sizeof(struct Arcnode));
    newNode->adjvex = adjVertex;
    newNode->nextarc = NULL;
    if (*head == NULL || (*head)->adjvex > newNode->adjvex) {
        newNode->nextarc = *head;
        *head = newNode;
    }
    else {
        struct Arcnode* current = *head;
        while (current->nextarc != NULL && current->nextarc->adjvex < newNode->adjvex) {
            current = current->nextarc;
        }
        newNode->nextarc = current->nextarc;
        current->nextarc = newNode;
    }
}

void creat(struct vertex* G) {
    int n, m;
    scanf("%d%d", &n, &m);
    G->vexnum = n, G->arcnum = m;
    for (int i = 0; i < n; i++) {
        G->Adjlist[i].first = NULL;
    }
    for (int i = 0; i < m; i++) {
        int k1, k2;
        scanf("%d%d", &k1, &k2);
        insertSorted(&G->Adjlist[k1].first, k2);
        insertSorted(&G->Adjlist[k2].first, k1);
    }
}
int visit[200];
int path[200];
void DFS(struct vertex* G, int i)
{
struct     Arcnode* p;
    visit[i] = 1;
    printf("%d ", i);
    p = G->Adjlist[i].first;
    while (p != NULL)
    {
        if (visit[p->adjvex] == 0)
            DFS(G, p->adjvex);
        p = p->nextarc;
    }
}
void DFSTraverse(struct vertex* G)
{
    int i;
    for (i = 0; i < G->vexnum; i++)
        visit[i] = 0;
            DFS(G, 0);
}
int quene[200], front = 0, rear = 0;
void BFS(struct vertex* G, int x) {
    for (int i = 0; i < G->vexnum; i++) // @@ The BFS function resets the global visit array, which clears the 'deleted' status set in main before calling BFS. This causes the deleted vertex to be visited again. The visit array should be managed in main or passed as a parameter, not reset inside BFS if external state (like deleted nodes) is tracked in it.
        visit[i] = 0;
    quene[rear] = x;
    rear = (rear + 1) % 200;
    visit[x] = 1;
    while (front != rear) {
        printf("%d ", quene[front]);
        struct Arcnode* q = G->Adjlist[quene[front]].first;
        front++;
        while (q != NULL) {
            if (visit[q->adjvex] != 1) {
                quene[rear] = q->adjvex;
                rear = (rear + 1) % 200;
                visit[q->adjvex] = 1;
            }
            q = q->nextarc;

        }

    }
}
void Delete(struct vertex* G, int removeVertex) {
        for (int i = 0; i < G->vexnum; i++) {
            struct Arcnode** ptr = &(G->Adjlist[i].first);
            struct Arcnode* pre = NULL;
            while (*ptr != NULL) {
                struct Arcnode* entry = *ptr;
                if (entry->adjvex == removeVertex) {
                    *ptr = entry->nextarc;
                    if (pre != NULL)
                        pre->nextarc = *ptr;
                    else *ptr = NULL;
                    free(entry);
                }
                else {    pre = *ptr;
                    ptr = &((*ptr)->nextarc);
                
                }
            }
        }
             G->Adjlist[removeVertex].first=NULL;
            
    }
int main() {
    creat(&graph);
    DFSTraverse(&graph);
    printf("\n");
    BFS(&graph,0);
    printf("\n");
    int de;
    scanf("%d", &de);
    Delete(&graph, de);memset(visit, 0, 200);
    DFSTraverse(&graph);
    printf("\n");
    memset(quene, 0, 200);
    front = 0, rear = 0;memset(visit, 0, 200);
    BFS(&graph, 0);
    printf("\n");
}