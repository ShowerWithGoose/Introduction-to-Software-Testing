#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<stdbool.h>
int graph[1005][1005];
int q[10005];
int head=1,tail=0;
int vis[1005];
int n,m,x,y,d;
void dfs(int cur){
    printf("%d ",cur);
    vis[cur]=1;
    for(int i=0;i<n;i++)
        if(!vis[i]&&graph[cur][i])
            dfs(i);
}
void bfs(int start){
    q[++tail]=start; vis[start]=1;
    while(tail-head+1>0){
        int cur=q[head++]; 
        //if(vis[cur]) continue;
        printf("%d ",cur);
       // vis[cur]=1;
        for(int i=0;i<n;i++)
            if(!vis[i]&&graph[cur][i]){
                q[++tail]=i;
                vis[i]=1;
            }
                
    }
}
int main(int argc,char *argv[]){
    scanf("%d%d",&n,&m);

    for(int i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        graph[x][y]=1;
        graph[y][x]=1;
    }
    scanf("%d",&d);
    dfs(0); printf("\n"); memset(vis,0,sizeof(vis));
    bfs(0); printf("\n"); memset(vis,0,sizeof(vis));

    for(int i=0;i<n;i++) {
        graph[d][i]=0;
        graph[i][d]=0;
    }

    dfs(0); printf("\n"); memset(vis,0,sizeof(vis));
    bfs(0); printf("\n"); memset(vis,0,sizeof(vis));
    system("pause");
    return 0;
}
