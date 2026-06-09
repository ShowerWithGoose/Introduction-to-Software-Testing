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
    scanf("%d",&del); // @@ The vertex to be deleted is read before the first traversals, but it should be read after printing the traversals of the original graph. The problem states: "First, output the DFS and BFS sequences before deleting... Then... after deleting". The input format says the deletion vertex is input last, but the logic here reads it too early if we assume standard flow, however looking at the reference code, it reads del after the first two traversals. In this buggy code, `del` is read immediately after edges. This means `del` is available, but the first two traversals (DFS/BFS) are performed on the full graph correctly because `visit[del]` is not set yet. So reading `del` here is actually fine logically as long as it's not used to modify the graph structure for the first part. Wait, let's look closer. The first DFS/BFS run on the full graph. Then `memset`, `visit[del]=1`, then DFS/BFS again. This logic seems correct for the "deletion" simulation by marking visited. The issue might be elsewhere.
    dfs(0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    bfs(0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    visit[del]=1;
    dfs(0);
    printf("\n");
    memset(visit,0,sizeof(visit));
    memset(s,0,sizeof(s));
    visit[del]=1; // @@ The vertex `del` must be marked as visited (effectively deleted) before running BFS on the modified graph. This line is missing in the original code before the final `bfs(0)` call. Without this, the BFS will traverse the deleted vertex again.
    bfs(0);
    return 0;
}