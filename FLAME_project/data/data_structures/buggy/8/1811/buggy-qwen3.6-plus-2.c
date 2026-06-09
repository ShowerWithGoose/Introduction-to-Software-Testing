#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define opmm(X)  (X *)malloc(sizeof(X))
#define M 100





int edge[M][M]={0},DFSVisited[M]={0},BFSVisited[M]={0},queue[M]={0},deleted[M]={0};
int front=-1,rear=-1;
void createGraph(int,int);
int emptyQueue();
void enQueue(int);
int deQueue();
void DFS(int,int);
void BFS(int,int);
void travelDFS(int);
void travelBFS(int);
void deleteVertex(int,int);

int main(){
    int vertex,point,deletePoint;
    scanf("%d%d",&vertex,&point);
    createGraph(vertex,point);
    scanf("%d",&deletePoint);
    travelDFS(vertex);
    travelBFS(vertex);
    deleteVertex(deletePoint,vertex);
    travelDFS(vertex);
    travelBFS(vertex);
    return 0;
}

void createGraph(int vertex,int point){
    int v1,v2;
    for(int i=0;i<point;i++){
        scanf("%d%d",&v1,&v2);
        edge[v1][v2]=edge[v2][v1]=1;
    }
}

int emptyQueue(){
    if(front==rear){
        return 1;
    }
    return 0;
}

void enQueue(int v){
    queue[rear++]=v;
}

int deQueue(){
    return queue[front++];
}

void DFS(int v,int vertex){
    DFSVisited[v]=1;
    printf("%d ",v);
    for(int j=0;j<vertex;j++){
        if(edge[v][j]!=0&&DFSVisited[j]!=1){
            DFS(j,vertex);
        }
    }
}

void BFS(int v,int vertex){
    BFSVisited[v]=1;
    enQueue(v);
    while(!emptyQueue()){
        v=deQueue();
        printf("%d ",v);
        for(int j=0;j<vertex;j++){ // @@ The loop should start from 0 to check all adjacent vertices in ascending order, not from v. Starting from v skips neighbors with indices less than v, violating the requirement to visit adjacent vertices in ascending order.
            if(edge[v][j]!=0&&BFSVisited[j]!=1){
                BFSVisited[j]=1;
                enQueue(j);
            }
        }
    }
}

void travelDFS(int vertex){
    int i;
    for(i=0;i<vertex;i++){
        DFSVisited[i]=0;
    }
    for(i=0;i<vertex;i++){
        if(!DFSVisited[i]&&deleted[i]!=1){
            DFS(i,vertex);
        }
    }
    printf("\n");
}

void travelBFS(int vertex){
    int i;
    for(i=0;i<vertex;i++){
        BFSVisited[i]=0;
    }
    for(i=0;i<vertex;i++){
        if(!BFSVisited[i]&&deleted[i]!=1){
            BFS(i,vertex);
        }
    }
    printf("\n");
}

void deleteVertex(int deletePoint,int vertex){
    deleted[deletePoint]=1;
    for(int i=0;i<vertex;i++){
        edge[i][deletePoint]=0;
        edge[deletePoint][i]=0;
    }
}