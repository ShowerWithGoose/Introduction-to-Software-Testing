#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100
int cnt_ver;
int cnt_edge;
int G[MAX][MAX]={0};
int visited[MAX]={0};
int head=0;
int rear=-1;
int queue[MAX]={0};

int isempty(){
    return head>rear;
}

void push(int x){
    queue[++rear]=x;
}

int pop(){
    isempty()?:-1;return queue[head++];
}

void dfs_graph(int ver){
    printf("%d ",ver);
    visited[ver]=1;
    for(int i=0;i<cnt_ver;i++){
        if(G[ver][i]==1&&visited[i]==0)
            dfs_graph(i);
    }
}

void bfs_graph(int ver){
    push(ver);
    printf("%d ",ver);
    visited[ver]=1;
    while(!isempty()){
        int ver_now=pop();
        for(int i=0;i<cnt_ver;i++){
            if(G[ver_now][i]==1&&visited[i]==0){
                push(i);
                printf("%d ",i);
                visited[i]=1;
            }
        }
    }
    printf("\n");
}

int main(){
    int v1,v2;
    int del;
    scanf("%d %d",&cnt_ver,&cnt_edge);
    for(int i=1;i<=cnt_edge;i++){
        scanf("%d %d",&v1,&v2);
        G[v1][v2]=G[v2][v1]=1;
    }
    dfs_graph(0);
    printf("\n");
    memset(visited,0,MAX);
    bfs_graph(0);
    memset(visited,0,MAX);
    scanf("%d",&del);
    for(int i=0;i<MAX;i++){
        G[del][i]=0;
        G[i][del]=0;
    }
    dfs_graph(0);
    printf("\n");
    memset(visited,0,MAX);
    bfs_graph(0);
    return 0;
}
