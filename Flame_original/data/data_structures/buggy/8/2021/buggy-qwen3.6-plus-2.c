#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int visit[100]={0},ju[100][100];
int n,num;
void dfs(int v){
    printf("%d ",v);
    visit[v]=1;
    for(int i=0;i<n;i++){ // @@ C89 standard does not allow variable declaration inside for-loop initialization, causing compilation error on strict compilers.
        if(ju[v][i]==1&&visit[i]==0){
            dfs(i);
        }
    }
}
int s[100];
void bfs(int v){
    int head=0;
    int rear=1;
    int flag;
    s[head]=v;
    while(head<=rear){
        flag=s[head];
        head++;
        if(visit[flag]){
            continue;
        }
        else{
            printf("%d ",flag);
            visit[flag]=1;
            for(int i=0;i<n;i++) // @@ C89 standard does not allow variable declaration inside for-loop initialization, causing compilation error.
                if(ju[flag][i]==1&&visit[i]==0)
                  s[rear++]=i;
        }
    }
}
int main(){
    int x,y,del;
    scanf("%d%d",&n,&num);
    for(int i=0;i<num;i++){ // @@ C89 standard does not allow variable declaration inside for-loop initialization, causing compilation error.
        scanf("%d%d",&x,&y);
        ju[x][y]=1;
        ju[y][x]=1;
    }
    scanf("%d",&del);
    dfs(0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    bfs(0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    visit[del]=1;
    dfs(0);
    printf("\n");
    memset(visit,0,sizeof(visit)); // @@ Logical error: visit array is reset but visit[del] is not marked as visited, so BFS will still traverse the deleted vertex. Should set visit[del]=1; after this line.
    memset(s,0,sizeof(s));
    bfs(0);
    return 0;
}