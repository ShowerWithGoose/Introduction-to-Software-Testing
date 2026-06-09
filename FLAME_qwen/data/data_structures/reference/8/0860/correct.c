#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int visit[1000];
void DFS(int v0,int **p,int vertex){
    int i;
    int v=v0;
    if(!visit[v]){
        printf("%d ",v-1);//因为一开始加一了
        visit[v]++;
    }
    for(i=1;i<=vertex;i++){
        if(visit[i]==0&&p[v][i]==1){
            DFS(i,p,vertex);
        }
    }
}
int queue[1000];
int tail=0,head=0;
void BFS(int v0,int **p,int vertex){
    int i,v;
    queue[tail++]=v0;
    while(tail!=head){
        v=queue[head++];
        if(!visit[v]){
        printf("%d ",v-1);
        visit[v]++;
        for(i=1;i<=vertex;i++){
            if(visit[i]==0&&p[v][i]==1){
                queue[tail++]=i;
            }
        }
        }
    }
}
int main(){
    int vertex,edge,i,j,v1,v2;
    int del;
    scanf("%d%d",&vertex,&edge);
    int **p=(int **)malloc(sizeof(int *)*(vertex+1));
    for(i=0;i<vertex+1;i++){
        p[i]=(int *)malloc(sizeof(int)*(vertex+1));
    }
    for(i=0;i<vertex+1;i++){
        for(j=0;j<vertex+1;j++){
            p[i][j]=0;
        }
    }
    for(i=0;i<edge;i++){
        scanf("%d%d",&v1,&v2);
        p[v1+1][v2+1]=1;
        p[v2+1][v1+1]=1;//插入邻接矩阵
    }
    scanf("%d",&del);
    DFS(1,p,vertex);
    printf("\n");
    memset(visit,0,sizeof(int)*1000);
    BFS(1,p,vertex);
    printf("\n");
    memset(visit,0,sizeof(int)*1000);
    visit[del+1]=1;
    DFS(1,p,vertex);
    printf("\n");
    memset(visit,0,sizeof(int)*1000);
    visit[del+1]=1;
    BFS(1,p,vertex);
}


