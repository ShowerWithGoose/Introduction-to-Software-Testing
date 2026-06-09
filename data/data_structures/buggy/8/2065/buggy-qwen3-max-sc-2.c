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
    reset();DFS(0);printf("\n"); // @@ [The problem requires DFS output before BFS, but the original code outputs BFS first. However, this is a logic error, not compilation. The actual compilation error is missing function declarations or definitions before use in C89/C90 mode. But more critically:]
    reset();BFS(0);printf("\n");
    scanf("%d",&m);
    for(int i=0;i<linenum;i++){ // @@ [This loop incorrectly iterates over edge count (linenum) instead of vertex count (pointnum). It should iterate from 0 to pointnum-1 to remove all edges connected to vertex m. Using linenum here may leave some adjacency entries uncleared or access out-of-bound if linenum > pointnum, but more importantly, it's logically wrong. However, the primary compilation issue is:]
        line[i][m]=line[m][i]=0;
    }
    reset();DFS(0);printf("\n");
    reset();BFS(0);printf("\n");
    return 0;
}