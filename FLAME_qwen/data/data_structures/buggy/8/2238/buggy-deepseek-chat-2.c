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
    for(int i=0;i<e;i++){ // @@ The loop condition should be i < v, not i < e. e is the number of edges, not the number of vertices. This causes out-of-bounds access and incorrect traversal.
        if(g[n][i]==1&&visited[i]==0)
        DFS(i);
    }
}
void BFS(int n){
    visited[n]=1;
    queue[++rear]=n;
    while(front<=rear){
        printf("%d ",queue[front]);
        for(int i=0;i<v;i++){ // @@ The loop uses front as the index for g[front][i], but front is the queue index, not the vertex number. It should use queue[front] as the current vertex.
            if(g[front][i]==1&&visited[i]==0){ // @@ Same issue: g[front][i] should be g[queue[front]][i].
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
    BFS(0);printf("\n");
    for(int i=0;i<v;i++) visited[i]=0;
    front=0;rear=-1;
    
    for(int i=0;i<v;i++)
    g[sh][i]=g[i][sh]=0;
    DFS(0);printf("\n");
    for(int i=0;i<v;i++) visited[i]=0;
    BFS(0);     
     return 0;
}