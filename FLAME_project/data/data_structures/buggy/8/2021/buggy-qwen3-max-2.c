#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int visit[100]={0},ju[100][100];
int n,num;
void dfs(int v){
    printf("%d ",v); // @@ [This prints a trailing space after the last vertex, which may cause presentation error; more critically, it does not respect the requirement to start from 0 and traverse neighbors in ascending order if adjacency matrix is not scanned correctly—but main issue is in BFS logic and deletion handling]
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
            printf("%d ",flag); // @@ [Prints trailing space; also, the BFS queue logic is flawed: it adds unvisited neighbors to the queue without marking them, leading to duplicates. More importantly, after vertex deletion, this BFS does not skip the deleted vertex properly because 'visit[del]=1' is set before calling BFS, but during BFS, when enqueueing neighbors, it doesn't check if neighbor is the deleted vertex—however, since visit[del] is already 1, it won't be processed, BUT the real bug is that in the second BFS call, the deleted vertex is not excluded from being enqueued from other nodes, though it will be skipped when dequeued. However, the critical error is below:]
            visit[flag]=1;
            for(int i=0;i<n;i++)
                if(ju[flag][i]==1&&visit[i]==0)
                  s[rear++]=i; // @@ [This enqueues adjacent vertices without checking if they are the deleted vertex. Although visit[del] is pre-set to 1, so it won't be printed, but the bigger issue is that the BFS implementation uses an array as a queue but does not prevent re-adding already enqueued (but not yet visited) nodes, causing potential duplication or out-of-bound access. However, the actual observed error is that after deletion, BFS outputs "0 1 2" instead of "0 2", meaning vertex 1 (the deleted one) is still being traversed. But wait: in main, before second BFS, we do 'visit[del]=1', so when BFS tries to process node 1, it skips it. However, how does 1 appear in output? It shouldn't. So why is output "0 1 2"? That suggests the deleted vertex is NOT being skipped. Looking closer: in the second BFS call, we set visit[del]=1 BEFORE calling bfs(0). Inside bfs, when processing node 0, it checks neighbors: 1 and 2. For neighbor 1: visit[1] is already 1 (because del=1), so it won't enqueue it. So only 2 should be enqueued. Then output should be "0 2". But buggy output shows "0 1 2", which implies that visit[del]=1 was reset or not applied. Wait: look at main()]
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
    memset(visit,0,sizeof(visit)); // @@ [This resets visit array, undoing the effect of any prior state, but then...]
    visit[del]=1; // @@ [This correctly marks deleted vertex as visited BEFORE DFS, so DFS skips it. This works for DFS.]
    dfs(0);
    printf("\n");
    memset(visit,0,sizeof(visit)); // @@ [HERE IS THE CRITICAL ERROR: this line clears the visit array again, including resetting visit[del] back to 0! So when bfs(0) is called next, the deleted vertex is no longer marked as visited, so it gets traversed again. That's why the second BFS outputs "0 1 2" instead of "0 2". The fix is to set visit[del]=1 AFTER this memset, or avoid clearing it.]
    memset(s,0,sizeof(s));
    bfs(0);
    return 0;
}