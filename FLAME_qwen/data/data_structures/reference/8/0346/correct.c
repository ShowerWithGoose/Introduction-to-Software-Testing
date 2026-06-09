#include<stdio.h>
#include<stdlib.h>
#define maxvex 100
typedef struct edgenode{
    int adjvex;
    struct edgenode *next;
} Edgenode;
typedef struct vertexnode{
    int data;
    Edgenode *firstarc;
} Vextexnode, Adjlist[maxvex];
typedef struct{
    Adjlist adjlist;
    int numVertexs, numEdges;
} graph;
void creategraph(graph *node){
    Edgenode *e;
    scanf("%d%d", &node->numVertexs, &node->numEdges);
    int i;
    int v1, v2;
    for (i = 0; i < node->numVertexs;i++)
    {
        node->adjlist[i].data = i;
        node->adjlist[i].firstarc = NULL;
    }
    int temp1[maxvex], temp2[maxvex];
    for (i = 0; i < node->numEdges;i++)
    {
        scanf("%d%d", &temp1[i], &temp2[i]);
        int temp;
        if(temp1[i]>temp2[i]){
            temp = temp1[i];
            temp1[i] = temp2[i];
            temp2[i] = temp;
        }
    }
    int j;
    for (i = 0; i < node->numEdges;i++)
    {
        for (j = i; j < node->numEdges;j++){
            if(temp1[i]<temp1[j]){
                int temp = temp1[i];
                temp1[i] = temp1[j];
                temp1[j] = temp;
                temp = temp2[i];
                temp2[i] = temp2[j];
                temp2[j] = temp;
            }else if(temp1[i]==temp1[j]&&temp2[i]<temp2[j]){
                int temp = temp1[i];
                temp1[i] = temp1[j];
                temp1[j] = temp;
                temp = temp2[i];
                temp2[i] = temp2[j];
                temp2[j] = temp;
            }
        }
    }
    for (i = 0; i < node->numEdges;i++){
        v1 = temp1[i];
        v2 = temp2[i];
        e = (Edgenode *)malloc(sizeof(Edgenode));
        e->adjvex = v2;
        e->next = node->adjlist[v1].firstarc;
        node->adjlist[v1].firstarc = e;
        e = (Edgenode *)malloc(sizeof(Edgenode));
        e->adjvex = v1;
        e->next = node->adjlist[v2].firstarc;
        node->adjlist[v2].firstarc = e;
    }
}
int visited[maxvex];
void DFS(graph g,int i){
    Edgenode *p;
    printf("%d ", g.adjlist[i].data);
    visited[i] = 1;
    p = g.adjlist[i].firstarc;
    while(p!=NULL){
        if(!visited[p->adjvex])
            DFS(g, p->adjvex);
        p = p->next;
    }
}
void DFSTraverse(graph g){
    int v, u;
    for (v = 0; v < g.numVertexs;v++){
        visited[v] = 0;
    }
    for (u = 0; u < g.numVertexs;u++){
        if(!visited[u])
            DFS(g, u);
    }
}
void DFSTraverse_1(graph g,int m){
    int v, u;
    for (v = 0; v < g.numVertexs;v++){
        visited[v] = 0;
    }
    visited[m] = 1;
    for (u = 0; u < g.numVertexs;u++){
        if(!visited[u])
            DFS(g, u);
    }
}
void  BFSTraverse(graph g){
    int m = 0;
    int i,j;
    int q[maxvex];
    int front = -1, rear = -1;
    for (i = 0; i < g.numVertexs;i++){
        visited[i] = 0;
    }
    Edgenode *p;
    visited[m] = 1;
    q[++rear] = m;
    while(front!=rear){
        m = q[++front];
        printf("%d ", m);
        p = g.adjlist[m].firstarc;
        while(p){
            j = p->adjvex;
            if(!visited[j]){
                visited[j] = 1;
                q[++rear] = j;
            }
            p = p->next;
        }
    }
}
void  BFSTraverse_1(graph g,int key){
    int m = 0;
    int i,j;
    int q[maxvex];
    int front = -1, rear = -1;
    for (i = 0; i < g.numVertexs;i++){
        visited[i] = 0;
    }
    visited[key] = 1;
    Edgenode *p;
    visited[m] = 1;
    if(m!=key) q[++rear] = m;
    else {
        visited[m + 1] = 1;
        q[++rear] = m + 1;
    }
    while(front!=rear){
        m = q[++front];
        printf("%d ", m);
        p = g.adjlist[m].firstarc;
        while(p){
            j = p->adjvex;
            if(!visited[j]){
                visited[j] = 1;
                q[++rear] = j;
            }
            p = p->next;
        }
    }
}


int main(){
    graph G;
    creategraph(&G);
    DFSTraverse(G);
    printf("\n");
    BFSTraverse(G);
    printf("\n");
    int key;
    scanf("%d", &key);
    DFSTraverse_1(G, key);
    printf("\n");
    BFSTraverse_1(G, key);
}
