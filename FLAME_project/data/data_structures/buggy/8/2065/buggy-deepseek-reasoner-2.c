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
    reset();BFS(0);printf("\n"); // @@ Error: Expected output order is DFS first, then BFS; this line produces BFS first.
    reset();DFS(0);printf("\n"); // @@ Error: Order swapped with previous line; should be DFS before BFS.
    scanf("%d",&m);
    for(int i=0;i<linenum;i++){ // @@ Error: Should loop over pointnum (0 to pointnum-1) to remove all edges of deleted vertex, not linenum (number of edges).
        line[i][m]=line[m][i]=0;
    }
    reset();BFS(0);printf("\n"); // @@ Error: Same order issue; should be DFS first, then BFS.
    reset();DFS(0);printf("\n"); // @@ Error: Order swapped.
    return 0;
}