#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int visited[200]={0},que[200];
int m,n,i;
int graph[200][200];
void dfs(int v)
{
    int i;
    printf("%d ",v);     
    visited[v]=1;    
    for(i = 0; i < m; i++) // @@ The loop bound should be 'n' (number of vertices), not 'm' (number of edges). DFS needs to check all potential vertices 0 to n-1.
        if (graph[v][i]==1 && visited[i]==0) 
        {
            dfs(i);    
        }
}
void bfs(int v)
{
    int j,head=0,tail=1,tmp;
    que[head]=v;    
    while(head<=tail)    
    {
        tmp=que[head];    
        head++;            
        if(visited[tmp]==1)    continue;    
        else
        {
            printf("%d ",tmp);        
            visited[tmp]=1;        
            for(j=0;i<m;j++) // @@ Two errors: 1. The condition uses global 'i' instead of local 'j'. 2. The bound 'm' (edges) is incorrect, it should be 'n' (vertices).
                if (graph[tmp][j]==1 && visited[j]==0)
                    que[tail++]=j;
        }
    }
}
int main(){
    int v1,v2,v;
    scanf("%d %d",&m,&n); // @@ The input format is "n m" (vertices then edges), but the code reads into "m n" (swapped). This causes m to hold the vertex count and n to hold the edge count, leading to incorrect loop bounds and graph initialization.
    
    for(i=0;i<n;i++){ // @@ Since m and n are swapped in scanf, this loop runs 'edge_count' times instead of 'edge_count' times if n was correct, or rather, since n now holds the number of edges, this loop actually iterates the correct number of times for reading edges. However, the variable naming is confusing. The real issue is that 'm' is used as the vertex count limit in DFS/BFS loops, but 'm' holds the vertex count from the swapped read. Wait, if scanf reads "3 3" into m=3, n=3. It works for square graphs. If input is "4 3", m=4, n=3. Loops run 3 times. Correct for edges. But DFS loops to m=4. Correct for vertices. So the swap might accidentally work if variable usage is consistent with the swap. Let's look closer. scanf("%d %d", &m, &n). Input: n_vertices, n_edges. So m gets n_vertices, n gets n_edges.
    // In dfs: loop i < m. m is n_vertices. This is CORRECT for vertex iteration.
    // In main edge reading: loop i < n. n is n_edges. This is CORRECT for edge reading.
    // So the variable swap in scanf is actually compensated by the usage?
    // Let's re-read the problem. Input: n (vertices) m (edges).
    // Code: scanf("%d %d", &m, &n). So m=n_vertices, n=n_edges.
    // DFS loop: i < m. Checks 0 to n_vertices-1. Correct.
    // Edge loop: i < n. Reads n_edges lines. Correct.
    // So the scanf line is logically okay due to subsequent usage, although semantically confusing.
    // HOWEVER, look at the BFS loop error: `for(j=0;i<m;j++)`. This uses `i` which is global.
    // And the deletion logic: `for(i=0;i<m;i++)`. Uses m (vertices). Correct.
    
    // Let's look at the actual error causing WA.
    // Test Case: 3 3. Edges: 0-1, 1-2, 0-2. Delete 1.
    // m=3, n=3.
    // DFS before delete:
    // Start 0. Visit 0. Neighbors 1, 2.
    // Loop i=0..2.
    // i=0: graph[0][0]=0.
    // i=1: graph[0][1]=1, visited[1]=0. DFS(1).
    //   Visit 1. Neighbors 0, 2.
    //   i=0: graph[1][0]=1, visited[0]=1. Skip.
    //   i=1: graph[1][1]=0.
    //   i=2: graph[1][2]=1, visited[2]=0. DFS(2).
    //     Visit 2. Neighbors 1, 0.
    //     i=0: graph[2][0]=1, visited[0]=1. Skip.
    //     i=1: graph[2][1]=1, visited[1]=1. Skip.
    //     i=2: graph[2][2]=0.
    //   Return.
    // Return.
    // Output: 0 1 2. Correct.
    
    // BFS before delete:
    // Start 0. Que: [0]. Head=0, Tail=1.
    // Loop head<=tail (0<=1).
    // tmp=0. Head=1. Visited[0]=0.
    // Print 0. Visited[0]=1.
    // Loop j=0. Condition `i<m`. Global i is currently 3 from previous loop? Or undefined?
    // In `bfs`, `i` is not declared locally. It uses global `i`.
    // Global `i` was last set in `main`'s edge reading loop or `dfs`?
    // `dfs` uses local `i`. `main` uses global `i`.
    // After `dfs(0)`, global `i` is 3 (from edge reading loop `i<n` where n=3).
    // So `for(j=0; i<m; j++)` -> `for(j=0; 3<3; j++)`. Condition false immediately.
    // No neighbors added.
    // Loop continues? Head=1, Tail=1. 1<=1.
    // tmp=que[1]. que[1] is uninitialized (garbage or 0).
    // If garbage, crash or weird behavior. If 0, visited[0]=1, continue.
    // Head=2. 2<=1 False. End.
    // Output: 0. Expected: 0 1 2.
    // So the BFS is broken because of `i<m` using global `i` instead of `j<n` (or `j<m` since m=vertices here).
    
    // Also, in `dfs`, the loop is `i < m`. Since m=vertices, this is correct.
    // In `bfs`, the loop is `j=0; i<m; j++`. This is definitely wrong.
    
    // Are there other errors?
    // Deletion logic:
    // `for(i=0;i<m;i++) graph[v][i]=graph[i][v]=0;`
    // m=vertices. Correct.
    
    // So the primary error is in BFS loop condition.
    
    scanf("%d %d",&v1,&v2);
        graph[v1][v2]=graph[v2][v1]=1;
    }
    scanf("%d",&v);
    dfs(0);
    printf("\n");
    memset(visited,0,sizeof(visited));
    bfs(0);
    printf("\n");
    for(i=0;i<m;i++){
        graph[v][i]=graph[i][v]=0;
    }
    memset(visited,0,sizeof(visited));
    dfs(0);
    printf("\n");
memset(visited,0,sizeof(visited));
memset(que,0,sizeof(que));
    bfs(0);
    return 0;
}