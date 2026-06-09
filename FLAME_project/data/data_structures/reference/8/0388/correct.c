#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int maxv,maxe,flag;
int adj[105][105];
int visited[105];
int delete,x,y;
void init(){
   scanf("%d%d",&maxv,&maxe);
   int i;
   for (i = 0;i<maxe;i++){
       scanf("%d%d",&x,&y);
       adj[x][y]=1;
       adj[y][x]=1;
   }
   scanf("%d",&delete);
}
void dfs(int p){
    int i;
    if(flag==0) printf("%d",p);
    else printf(" %d",p);
    flag=1;
    visited[p]=1;
    for(i=1;i<=maxv;i++)
        {if(adj[p][i]==1&&visited[i]==0) dfs(i);}
}
void bfs(int p,int n){
    int i=0;int troops[105],front=0,tail=0;
    printf("%d",p);
    for(i=1;i<maxv;i++){
        if(visited[i]==0 && adj[p][i]==1){
            printf(" %d",i);
            visited[i]=1;
            troops[front++]=i;
        }
    }
    while(front<maxv-n-1){
        tail=front;
        int j;
        for(i=0;i<tail;i++){
            for(j=1;j<=maxv;j++){
                if(visited[j]==0 && adj[troops[i]][j]==1){
                    printf(" %d",j);
                    visited[j]=1;
                    troops[front++]=j;
                }
            }
        }
    }
}
int main(){
    int i;int n=0;
    init();
    dfs(0);printf("\n");
    for(i=0;i<=maxv;i++) visited[i]=0;
    flag=0;
    bfs(0,n);printf("\n");
    for(i=0;i<=maxv;i++) visited[i]=0;
    flag=0;
    visited[delete]=1;
    dfs(0);printf("\n");
    for(i=0;i<=maxv;i++) visited[i]=0;
    flag=0;
    visited[delete]=1;n=1;
    bfs(0,n);printf("\n");
    return 0;
}

