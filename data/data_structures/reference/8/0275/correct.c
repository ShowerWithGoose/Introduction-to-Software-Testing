#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define NHASH  3001
#define MULT  37
typedef struct Graph{
    int numNodes;
    int numEdges;
    int arc[100][100];
}Graph;

Graph *initGraph(int numNodes,int numEdges){
    Graph *p=malloc(sizeof(Graph));
    p->numEdges=numEdges;
    p->numNodes=numNodes;
    memset(p->arc, 0, sizeof(int)*100*100);
    return p;
}

void DFS(Graph *g,int *visited,int index){
    if(!g)return;
    printf("%d ",index);
    visited[index]=1;
    for(int i=0;i<g->numNodes;i++){
        if(visited[i]==0 && g->arc[index][i]==1){
            DFS(g, visited, i);
        }
    }
    
}

int head=0,tail=0,size=0;

void enQueue(int *arr,int val){
    arr[tail]=val;
    tail=tail+1==100?0:tail+1;
    size++;
    return;
}


int deQueue(int *arr){
    size--;
    int p=arr[head];
    head=head+1==100?0:head+1;
    return p;
}

void BFS(Graph *g,int *visited,int index){
    int Q[100]={0};
    enQueue(Q,index);
    while(size>0){
        int p=deQueue(Q);
        visited[p]=1;
        printf("%d ",p);
        for(int i=0;i<g->numNodes;i++){
            if(visited[i]==0 && g->arc[p][i]==1){
                enQueue(Q,i);
                visited[i]=1;
            }
        }
    }
    return;
}

void del(Graph *g,int p){
    for(int i=0;i<g->numNodes;i++){
        g->arc[p][i]=0;
        g->arc[i][p]=0;
    }
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    Graph *graph=initGraph(n, m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        graph->arc[a][b]=1;
        graph->arc[b][a]=1;
    }
    int delpoint;
    scanf("%d",&delpoint);
    int *visited=calloc(graph->numNodes, sizeof(int));
    DFS(graph,visited,0);
    memset(visited, 0, sizeof(int)*graph->numNodes);
    putchar('\n');
    BFS(graph,visited,0);
    memset(visited, 0, sizeof(int)*graph->numNodes);
    putchar('\n');
    del(graph,delpoint);
    
    DFS(graph,visited,0);
    putchar('\n');
    memset(visited, 0, sizeof(int)*graph->numNodes);
    BFS(graph,visited,0);
    return 0;
}

