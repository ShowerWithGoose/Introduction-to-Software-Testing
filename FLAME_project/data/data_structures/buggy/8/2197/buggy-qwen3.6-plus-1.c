#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXN 105

typedef struct edge{
    int adjvex;
    struct edge *next;
}Elink;

typedef struct ver{
    int vertex;
    Elink *link;
}Vlink;

int numV, numE;
int vis[MAXN];
Vlink graph[MAXN];

void insert(int from, int to){
    Elink *newLink1 = (Elink*)malloc(sizeof(Elink));
    newLink1->adjvex = to;
    newLink1->next = NULL;
    if(graph[from].link == NULL || to < graph[from].link->adjvex){
        newLink1->next = graph[from].link;
        graph[from].link = newLink1;
    }else{
        Elink *cur = graph[from].link;
        while(cur->next != NULL && cur->next->adjvex < to){
            cur = cur->next;
        }
        newLink1->next = cur->next;
        cur->next = newLink1;
    }

    Elink *newLink2 = (Elink*)malloc(sizeof(Elink));
    newLink2->adjvex = from;
    newLink2->next = NULL;
    if(graph[to].link == NULL || from < graph[to].link->adjvex){
        newLink2->next = graph[to].link;
        graph[to].link = newLink2;
    }else{
        Elink *cur = graph[to].link;
        while (cur->next != NULL && cur->next->adjvex < from){
            cur = cur->next;
        }
        newLink2->next = cur->next;
        cur->next = newLink2;
    }
}

void removeP(int p){
    Elink *tmp = graph[p].link;
    while(tmp != NULL){
        Elink *next = tmp->next;
        free(tmp);
        tmp = next;
    }
    graph[p].link = NULL;

    int q;
    Elink *tmp2, *tmp3;
    for(q = 0; q < numV; q++){
        tmp2 = graph[q].link;
        Elink *prev = NULL; // @@ The original code fails to correctly remove edges pointing to p from other vertices' adjacency lists because it only updates the head pointer and breaks, ignoring edges deeper in the list or failing to link the previous node.
        while(tmp2){
            if(tmp2->adjvex == p){
                tmp3 = tmp2->next;
                free(tmp2);
                if(prev == NULL) {
                    graph[q].link = tmp3;
                } else {
                    prev->next = tmp3;
                }
                break;
            }
            prev = tmp2;
            tmp2 = tmp2->next;
        }
    }
}

void traverseD(int ver){
    vis[ver] = 1;
    printf("%d ", ver);
    Elink *tmp = graph[ver].link;
    while(tmp){
        int adj = tmp->adjvex;
        if(!vis[adj])
            traverseD(adj);
        tmp = tmp->next;
    }
}

void traverseB(int ver){
    int queue[MAXN];
    int front = 0, rear = 0;
    vis[ver] = 1;
    queue[rear++] = ver;
    while(front < rear){
        int cur = queue[front++];
        printf("%d ", cur);
        Elink *tmp = graph[cur].link;
        while(tmp){
            int adj = tmp->adjvex;
            if(!vis[adj]){
                vis[adj] = 1;
                queue[rear++] = adj;
            }
            tmp = tmp->next;
        }
    }
}

int main(){
    scanf("%d%d", &numV, &numE);
    int edgeFrom, edgeTo, removeV;
    for(int i = 0; i < numV; i++){
        graph[i].link = NULL;
        graph[i].vertex = i;
    }
    for(int i = 0; i < numE; i++){
        scanf("%d%d", &edgeFrom, &edgeTo);
        insert(edgeFrom, edgeTo);
    }
    scanf("%d", &removeV);
    traverseD(0);
    printf("\n");
    memset(vis, 0, sizeof(vis));
    traverseB(0);
    printf("\n");
    removeP(removeV);
    memset(vis, 0, sizeof(vis));
    traverseD(0);
    printf("\n");
    memset(vis, 0, sizeof(vis));
    traverseB(0);
    return 0;
}