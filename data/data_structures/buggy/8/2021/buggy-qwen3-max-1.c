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
    visit[del]=1; // @@ [Marking the vertex to delete as visited prevents DFS from visiting it, but the adjacency matrix still contains edges to 'del', which may cause inconsistent behavior. More critically, BFS does not mark 'del' as visited before traversal, leading to asymmetry between DFS and BFS handling of deletion. The correct approach is to remove all edges connected to 'del' in the adjacency matrix, not just mark it visited.]
    dfs(0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    memset(s,0,sizeof(s));
    bfs(0); // @@ [BFS does not exclude the deleted vertex because its edges are still present in 'ju' and it is not marked as visited before BFS starts. This causes BFS to potentially traverse through or to the deleted vertex, violating the requirement to delete it from the graph.]
    return 0;
}