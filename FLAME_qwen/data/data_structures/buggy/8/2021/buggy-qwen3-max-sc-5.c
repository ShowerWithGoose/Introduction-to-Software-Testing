#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int visit[100]={0},ju[100][100];
int n,num;
void dfs(int v){
    printf("%d ",v);
    visit[v]=1;
    for(int i=0;i<n;i++){
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
            for(int i=0;i<n;i++)
                if(ju[flag][i]==1&&visit[i]==0)
                  s[rear++]=i;
        }
    }
}
int main(){
    int x,y,del;
    scanf("%d%d",&n,&num);
    for(int i=0;i<num;i++){
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
    visit[del]=1; // @@ [This marks the vertex as visited instead of actually deleting it from the graph. As a result, DFS will skip this vertex but edges to it still exist, potentially causing incorrect traversal behavior or missing connections that should be removed. The correct approach is to remove all edges connected to 'del' in the adjacency matrix.]
    dfs(0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    memset(s,0,sizeof(s));
    bfs(0); // @@ [Similar to DFS, BFS uses the same flawed method of marking 'del' as visited without removing its edges. This can lead to BFS incorrectly enqueuing neighbors through the deleted vertex or failing to traverse correctly because the graph structure wasn't actually modified.]
    return 0;
}