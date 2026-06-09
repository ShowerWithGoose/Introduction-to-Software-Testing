#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int g[101][101];
int visited[101];
int v,e;
int queue[101],rear=-1,front;
void DFS(int n){
    visited[n]=1;
    printf("%d ",n);
    for(int i=0;i<v;i++){ // @@ The loop condition should iterate through all vertices (0 to v-1) to check adjacency, not edges (0 to e-1). Using 'e' here is incorrect because the adjacency matrix index represents vertex IDs, not edge indices.
        if(g[n][i]==1&&visited[i]==0)
        DFS(i);
    }
}
void BFS(int n){
    visited[n]=1;
    queue[++rear]=n;
    while(front<=rear){
        int curr = queue[front]; // @@ The variable 'front' is an index, not the vertex ID. We need to retrieve the vertex ID from the queue array to check its neighbors.
        printf("%d ",curr);
        for(int i=0;i<v;i++){
            if(g[curr][i]==1&&visited[i]==0){ // @@ Use 'curr' (the actual vertex dequeued) instead of 'front' (the index) to access the adjacency matrix.
                visited[i]=1;
                queue[++rear]=i;
            }
        }
        front++;
    }
}
int main()
{
    
    scanf("%d%d",&v,&e);
    for(int i=0;i<e;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a][b]=g[b][a]=1;
    }
    int sh;scanf("%d",&sh);
    DFS(0);printf("\n");
    for(int i=0;i<v;i++) visited[i]=0;
    front=0; rear=-1; // @@ Initialize front and rear before calling BFS to ensure the queue is empty.
    BFS(0);printf("\n");
    for(int i=0;i<v;i++) visited[i]=0;
    front=0;rear=-1;
    
    for(int i=0;i<v;i++)
    g[sh][i]=g[i][sh]=0;
    DFS(0);printf("\n");
    for(int i=0;i<v;i++) visited[i]=0;
    front=0; rear=-1; // @@ Initialize front and rear before calling BFS again.
    BFS(0);     
     return 0;
}