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
    visit[del]=1; // @@ [This marks the vertex as visited instead of actually deleting it from the graph. As a result, DFS and BFS after "deletion" still consider edges to/from 'del', but skip the vertex itself. However, adjacent vertices may still try to traverse through 'del' or be affected by its presence in the adjacency matrix, leading to incorrect traversal sequences. The correct approach is to remove all edges connected to 'del' in the adjacency matrix, like setting ju[del][i] = ju[i][del] = 0 for all i.]
    dfs(0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    memset(s,0,sizeof(s));
    bfs(0); // @@ [Because the vertex 'del' was not actually removed from the graph (only marked as visited before DFS), during BFS the queue may still enqueue neighbors that connect through 'del', or more critically, since 'del' is not blocked in the adjacency matrix, if any neighbor checks connectivity to 'del', it might behave unexpectedly. But more importantly, in this BFS implementation, the initial state doesn't mark 'del' as visited, so if the graph structure still includes edges to 'del', BFS might attempt to visit it unless prevented. However, the real issue is that the graph wasn't modified—edges to 'del' remain, so traversals are logically incorrect even if 'del' is skipped via visit[] marking. The deletion must be structural (remove edges), not just logical (mark visited).]
    return 0;
}