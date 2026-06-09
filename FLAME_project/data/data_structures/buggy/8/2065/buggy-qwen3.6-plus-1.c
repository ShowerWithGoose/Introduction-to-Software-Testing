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
    for(int i=0;i<linenum;i++){ // @@ This loop incorrectly iterates up to linenum using index i to access vertices, which does not correctly remove all edges connected to vertex m. It should iterate through all possible vertices (0 to pointnum-1) to set line[i][m] and line[m][i] to 0.
        line[i][m]=line[m][i]=0;
    }
    reset();BFS(0);printf("\n"); // @@ The problem requires outputting DFS first, then BFS after deletion. This line outputs BFS first.
    reset();DFS(0);printf("\n"); // @@ The problem requires outputting DFS first, then BFS after deletion. This line outputs DFS second.
    return 0;
}