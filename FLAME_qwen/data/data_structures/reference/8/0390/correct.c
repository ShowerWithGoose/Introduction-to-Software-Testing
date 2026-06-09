#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100

int vex[MAXSIZE][MAXSIZE]={{0}};
int visited[MAXSIZE]={0};
int n_vertex,rear=-1,front=0;
int queue[MAXSIZE]={0};

void dfs(int n){
    int i;
    visited[n]=1;
    printf("%d ",n);
    for(int i=0;i<n_vertex;i++){
        if(vex[n][i]){
            if(!visited[i]){
                dfs(i);
                visited[i]=1;
            }
        }
    }
}

void bfs(int n){
    int i;
    visited[n]=1;
    queue[++rear]=n;
    while(rear>=front){
        i=queue[front];
        front++;
        printf("%d ",i);
        for(int j=0;j<n_vertex;j++){
            if(vex[i][j]){
                if(!visited[j]){
                    visited[j]=1;
                    queue[++rear]=j;
                }
            }
        }
    }
}

int main(){
    int i,m,a,b,del;
    scanf("%d%d",&n_vertex,&m);
    for(i=0;i<m;i++){
        scanf("%d%d",&a,&b);
        vex[a][b]=vex[b][a]=1;
    }
    scanf("%d",&del);
    dfs(0);
    printf("\n");
    memset(visited,0,MAXSIZE);
    bfs(0);
    printf("\n");
    memset(visited,0,MAXSIZE);
    for(i=0;i<n_vertex;i++){
        vex[del][i]=vex[i][del]=0;
    }
    dfs(0);
    printf("\n");
    memset(visited,0,MAXSIZE);
    bfs(0);
    printf("\n");
    return 0;
}

