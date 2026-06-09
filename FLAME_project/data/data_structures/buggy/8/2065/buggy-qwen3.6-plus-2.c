#include<stdio.h>
#include<stdlib.h>
int pointnum,linenum;
int line[110][110]={0};
int visited[110]={0};
void reset() {  
    for (int i = 0; i < pointnum; i++) {  
        visited[i] = 0;  
    }  
}
void DFS(int v) {  
    visited[v]=1; 
    printf("%d ",v);
    for (int i = 0; i < pointnum;i++) {  
        if (line[v][i]&&!visited[i]) {  
            DFS(i);  
        }  
    }  
}  
void BFS(int n){
    int quene[110]={0};
    int front=0,rear=0;
    quene[rear++]=n;
    visited[n]=1;
    while(front<rear){
        int current=quene[front++];
        printf("%d ",current);
        for (int i = 0; i < pointnum; i++) {  
            if (line[current][i] && !visited[i]) {  
                visited[i] = 1;  
                quene[rear++]=i;
             }
        } 
    }
}
int main(){
    scanf("%d%d",&pointnum,&linenum);
    int n,m;
    for(int i=0;i<linenum;i++){
        scanf("%d%d",&n,&m);
        line[n][m]=line[m][n]=1;
    }
    reset();BFS(0);printf("\n"); // @@ The problem requires outputting DFS first, then BFS. This line outputs BFS first.
    reset();DFS(0);printf("\n"); // @@ The problem requires outputting DFS first, then BFS. This line outputs DFS second.
    scanf("%d",&m);
    for(int i=0;i<linenum;i++){ // @@ This loop incorrectly iterates up to linenum (number of edges) instead of pointnum (number of vertices) to clear connections to vertex m. It should be i < pointnum. Also, simply clearing edges based on input order or index is incorrect; one must clear all connections to vertex m in the adjacency matrix.
        line[i][m]=line[m][i]=0;
    }
    reset();BFS(0);printf("\n"); // @@ Similar to above, this outputs BFS before DFS for the second part, violating the required order (DFS then BFS).
    reset();DFS(0);printf("\n"); // @@ Similar to above, this outputs DFS after BFS for the second part, violating the required order.
    return 0;
}