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
    visit[del]=1; // @@ [Marking the vertex to delete as visited prevents DFS from traversing it, but the adjacency matrix still contains edges to 'del', which may cause inconsistent behavior. The correct approach is to remove all edges connected to 'del' from the adjacency matrix before traversal.]
    dfs(0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    memset(s,0,sizeof(s));
    bfs(0); // @@ [The BFS implementation does not exclude the deleted vertex because the adjacency matrix still includes edges to 'del'. Additionally, the BFS queue logic is flawed: it checks 'visit[flag]' after dequeuing, which can lead to skipping unvisited nodes or processing visited ones incorrectly. Also, the deleted vertex is not properly removed from the graph structure.]
    return 0;
}