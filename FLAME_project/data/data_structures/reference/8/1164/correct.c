#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
typedef long long ll;
#define MaxN 1005

int G[MaxN][MaxN];
int n,m,del;

bool vis[MaxN+5];
void dfs(int no){
    printf("%d ",no);
    vis[no]=true;
    for(int i=0;i<n;i++){
        if(G[no][i]==0) continue;
        if(vis[i]) continue;
        dfs(i);
    }
}
int que[MaxN*10],front=0,back=0;
void bfs(int no){
    printf("%d ",no);
    que[back++]=no;
    vis[no]=true;
    while(front<back){
        no=que[front++];
        for(int i=0;i<n;i++){
            if(G[no][i]==0) continue;
            if(vis[i]) continue;
            printf("%d ",i);
            que[back++]=i;
            vis[i]=true;
        }
    }
}

int main(int argc, char const *argv[]){
    scanf("%d%d",&n,&m);
    for(int i=1,tx,ty;i<=m;i++){
        scanf("%d%d",&tx,&ty);
        G[tx][ty]=1;
        G[ty][tx]=1;
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         printf("%d ",G[i][j]);
    //     }
    //     printf("\n");
    // }
    scanf("%d",&del);
    
    memset(vis,0,sizeof(vis));
    dfs(0);printf("\n");
    memset(vis,0,sizeof(vis));
    bfs(0);printf("\n");
    memset(vis,0,sizeof(vis));
    vis[del]=1;
    dfs(0);printf("\n");
    memset(vis,0,sizeof(vis));
    vis[del]=1;
    bfs(0);printf("\n");
    return 0;
}
