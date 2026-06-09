#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
int visit[105]={};
int queue[105]={};
int G[105][105]={};

void DFS(int,int);
void BFS(int,int);

int main(){
    int ver,edge,i,j,k,delete;
    scanf("%d%d",&ver,&edge);
    for(i=0;i<edge;i++){//创建邻接矩阵
        scanf("%d%d",&j,&k);
        G[j][k]=1;
        G[k][j]=1;
    }
    scanf("%d",&delete);

    DFS(ver,0);
    printf("\n");
    memset(visit,0,sizeof(visit));

    BFS(ver,0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    memset(queue,0,sizeof(queue));

    visit[delete]=1;
    DFS(ver,0);
    printf("\n");
    memset(visit,0,sizeof(visit));

    visit[delete]=1;
    BFS(ver,0);
    printf("\n");

    return 0;
}

void DFS(int edge,int begin){
    int i;
    printf("%d ",begin);
    visit[begin]=1;
    for(i=0;i<edge;i++){
        if(G[begin][i]==1&&visit[i]==0){
            DFS(edge,i);
        }
    }
}
void BFS(int edge,int begin){
    int i,front=0,rear=-1,temp,cnt=0;
    queue[++rear]=begin;
    cnt++;
    while (cnt!=0)
    {
        temp=queue[front++];//出队
        cnt--;
        if(visit[temp]==0){
            printf("%d ",temp);
            visit[temp]=1;
            for(i=0;i<edge;i++){
                if(G[temp][i]==1&&visit[i]==0){
                    queue[++rear]=i;//入队
                    cnt++;
                }
            }
        }
    }
    
}
