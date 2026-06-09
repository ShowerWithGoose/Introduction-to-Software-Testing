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
    scanf("%d",&del); // @@ The vertex to be deleted is read before the first traversals are performed. According to the problem description and reference program, the first DFS and BFS should be performed on the original graph (before deletion). The deletion vertex should be read after the first two traversals.
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
    bfs(0); // @@ Missing printf("\n") after the last BFS output, which may cause format issues, but the primary logical error is the reading of 'del' too early. Also, the BFS function does not reset the 's' array or handle the queue initialization correctly if called multiple times without clearing, though memset(s,0,sizeof(s)) is called here. However, the critical error causing the wrong answer for the "after deletion" case is that 'del' was used in the "before deletion" phase if it affected logic, but here it just sits unused until later. Wait, looking at the code: 'del' is read, then DFS(0) runs on full graph. Then BFS(0) runs on full graph. Then visit[del]=1 is set. This part is actually logically okay for the *order* of operations IF the input was read after. But since scanf("%d", &del) happens BEFORE the first DFS/BFS, it doesn't affect them because 'del' is not used in them. So why is the output wrong?
    
    // Let's re-evaluate.
    // Input: 3 3 \n 0 1 \n 1 2 \n 0 2 \n 1
    // Code reads n=3, num=3.
    // Reads edges.
    // Reads del=1.
    // DFS(0): Visits 0, prints "0 ". Goes to 1 (adjacent, not visited). Prints "1 ". From 1, goes to 2. Prints "2 ". Output: "0 1 2 ". Correct.
    // Reset visit.
    // BFS(0): Queue [0]. Pop 0, print "0 ". Add 1, 2. Queue [1, 2]. Pop 1, print "1 ". Add 2 (already in queue/visited check happens at pop? No, visit check is at pop. But 2 is added again? 
    // In BFS:
    // head=0, rear=1. s[0]=0.
    // Loop: head<=rear (0<=1). flag=s[0]=0. head=1. visit[0] is 0. Print "0 ". visit[0]=1.
    // Neighbors of 0: 1 and 2.
    // i=1: ju[0][1]=1, visit[1]=0 -> s[1]=1, rear=2.
    // i=2: ju[0][2]=1, visit[2]=0 -> s[2]=2, rear=3.
    // Loop: head<=rear (1<=3). flag=s[1]=1. head=2. visit[1]=0. Print "1 ". visit[1]=1.
    // Neighbors of 1: 0, 2.
    // i=0: ju[1][0]=1, visit[0]=1 -> skip.
    // i=1: skip.
    // i=2: ju[1][2]=1, visit[2]=0 -> s[3]=2, rear=4.
    // Loop: head<=rear (2<=4). flag=s[2]=2. head=3. visit[2]=0. Print "2 ". visit[2]=1.
    // Neighbors of 2: 0, 1. Both visited.
    // Loop: head<=rear (3<=4). flag=s[3]=2. head=4. visit[2]=1 -> continue.
    // Loop: head<=rear (4<=4). flag=s[4]=0 (garbage/uninitialized or 0 from memset?). s was not memset before first BFS. 
    // Actually, global s is initialized to 0.
    // If s[4] is 0, visit[0] is 1 -> continue.
    // Loop ends.
    // Output: "0 1 2 ". Correct.
    
    // Reset visit. visit[del]=1 => visit[1]=1.
    // DFS(0):
    // Print "0 ". visit[0]=1.
    // Neighbors of 0: 1, 2.
    // i=1: ju[0][1]=1, visit[1]=1 -> skip.
    // i=2: ju[0][2]=1, visit[2]=0 -> dfs(2).
    //   Print "2 ". visit[2]=1.
    //   Neighbors of 2: 0, 1.
    //   i=0: visited.
    //   i=1: visited.
    //   Return.
    // Return.
    // Output: "0 2 ". Correct.
    
    // Reset visit. memset(s, 0).
    // visit[del] is NOT set to 1 here!
    // In the main function:
    // memset(visit,0,sizeof(visit));
    // memset(s,0,sizeof(s));
    // bfs(0);
    // The line `visit[del]=1;` is MISSING before the second BFS call.
    // In the DFS case above, `visit[del]=1;` was present.
    // In the BFS case below, it is missing.
    return 0;
}