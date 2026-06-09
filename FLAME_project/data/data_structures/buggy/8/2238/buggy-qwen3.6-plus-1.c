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
    for(int i=0;i<v;i++){ // @@ The loop condition should iterate through all vertices (0 to v-1) to check adjacency, not just up to e (number of edges). Using 'e' here is incorrect because vertex indices go up to v-1, and e can be less than v or unrelated to the range of vertex indices.
        if(g[n][i]==1&&visited[i]==0)
        DFS(i);
    }
}
void BFS(int n){
    visited[n]=1;
    queue[++rear]=n;
    while(front<=rear){
        printf("%d ",queue[front]);
        for(int i=0;i<v;i++){
            if(g[queue[front]][i]==1&&visited[i]==0){ // @@ The adjacency check should use the current dequeued vertex 'queue[front]' as the source, not the global variable 'front' which is an index. Although 'front' holds the index, using it directly as a row index in g[front][i] is logically confusing and potentially error-prone if 'front' was not synchronized with the queue content properly, but specifically here, g[front][i] uses the integer value of front (the index) as the vertex ID, which is incorrect. It should be g[queue[front]][i].
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