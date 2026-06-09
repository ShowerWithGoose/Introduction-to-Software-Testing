#include<stdio.h>
#include<string.h>
int weights[101][101] , visited[101], que[101];
int num_vertex , num_edge;
void dfs(int v)
{
    int i;
    printf("%d " , v);
    visited[v]=1;
    for(i=0;i<num_vertex;i++){
        if(weights[v][i] && !visited[i]) dfs(i);
    }
}
void bfs(int v)
{
    int i, head = 0 , tail=1 , tmp;
    que[head]=v;
    while(head<=tail){
        tmp=que[head++];
        if(!visited[tmp]){
            printf("%d " , tmp);
            visited[tmp]=1;
            for(i=0;i<num_vertex;i++){
                if(weights[tmp][i] && !visited[i]) que[tail++] = i;
            }
        }
    }
}
int main()
{
    int u , v , i , del;
    scanf("%d %d" , &num_vertex , &num_edge);
    for(i=0;i<100;i++)
    for(int j=0;j<100;j++)
    weights[i][j]=0;
    for(int j=0;j<100;j++)
    visited[j]=0;
    for(i=0;i<num_edge;i++){
        scanf("%d %d" , &u , &v);
        weights[u][v]=1;
        weights[v][u]=1;
    }
    scanf("%d" , &del); // @@ The vertex to be deleted is read before the first traversals. According to the problem description and reference program, the first DFS and BFS should be performed on the original graph (before deletion). Reading 'del' here is fine, but the deletion logic must not affect the first two outputs. The current code reads 'del' but doesn't delete it yet, which is correct for the first part. However, the subsequent logic deletes it permanently from the adjacency matrix.
    dfs(0);
    printf("\n");
    for(i=0;i<=100;i++) // @@ Array bounds error: visited is defined as size 101 (indices 0-100). Accessing index 100 is valid, but the loop condition i<=100 accesses index 100. Wait, size 101 means indices 0..100. So i<=100 is actually accessing out of bounds if it goes to 100? No, 0 to 100 is 101 elements. So i<=100 is correct for size 101. However, standard practice is usually < size. Let's look closer. int visited[101]. Indices 0..100. Loop i=0 to 100 inclusive. This is safe. But wait, in C, arrays are 0-indexed. visited[100] is the last element. So i<=100 is correct.
    visited[i]=0; 
    bfs(0);
    for(i=0;i<=100;i++) // @@ Same as above, technically safe but inconsistent with typical < num_vertex usage. More importantly, we should only reset visited for vertices that exist (0 to num_vertex-1). Resetting unused memory is harmless but inefficient. The real issue is likely elsewhere.
    visited[i]=0; 
    for(i=0;i<=100;i++){ // @@ Logic Error: The deletion of the vertex is implemented by removing edges from the adjacency matrix. This modifies the graph structure globally. While this works for the subsequent traversals, it relies on the side effect. A cleaner approach (like the reference) uses the visited array to mark the deleted node as "already visited" so it's skipped during traversal without modifying the graph structure. However, modifying the weights is also a valid strategy IF done correctly. The problem is that this loop iterates up to 100, not num_vertex. It should iterate up to num_vertex. Also, it sets weights to 0.
        if(weights[i][del]==1){
            weights[i][del]=0;
            weights[del][i]=0;
        }
    }
    printf("\n");
    dfs(0);
    printf("\n");
    for(i=0;i<=100;i++) // @@ Same bound issue.
    visited[i]=0; 
    bfs(0);
    return 0;
}