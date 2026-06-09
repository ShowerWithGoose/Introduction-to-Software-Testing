#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,m,dele;
int map[150][150];
int visited[150];
int queue[150],top,bottom;
void dfs(int u){
    for(int i = 0; i < n; i++){
        if(!visited[i]&&map[u][i]){
            visited[i]=1;
            printf("%d ",i);
            dfs(i);
        }
    }
}
void travel(){
    visited[0]=1;
    printf("0 ");
    dfs(0);
    putchar('\n');
    memset(visited,0,sizeof(visited));
    queue[0]=0;
    bottom++;
    visited[0]=1;
    while(top < bottom){
        int now = queue[top++];
        printf("%d ",now);
        for(int i = 0; i < n; i++){
            if(!visited[i]&&map[now][i]){
                queue[bottom++] = i;
                visited[i]=1;
            }
        }
    }
    
    putchar('\n');
}
int main(){
    scanf("%d%d",&n,&m);
    int u,v;

    for(int i = 0; i < m; i++){
        scanf("%d%d",&u,&v);
        map[u][v]=map[v][u]=1;
    }
    travel();
    memset(visited,0,sizeof(visited));
    memset(queue,0,sizeof(queue));
    top = bottom = 0;
    scanf("%d",&dele);
    for(int i = 0; i < n; i++){
        map[i][dele] = 0;
    }
    memset(map[dele],0,sizeof(map[dele]));
    travel();
    return 0;
}

