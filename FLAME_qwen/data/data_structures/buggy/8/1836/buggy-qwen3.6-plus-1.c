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
        if(!visited[tmp]){ // @@ [BFS should mark nodes as visited when enqueued, not dequeued, to prevent duplicate queue entries and incorrect traversal order]
            printf("%d " , tmp);
            visited[tmp]=1;
            for(i=0;i<num_vertex;i++){
                if(weights[tmp][i] && !visited[i]) que[tail++] = i; // @@ [Missing visited[i]=1; here. Nodes must be marked visited upon enqueue to prevent duplicates and potential queue overflow]
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
    scanf("%d" , &del);
    dfs(0);
    printf("\n");
    for(i=0;i<=100;i++)
    visited[i]=0; 
    bfs(0); // @@ [Missing printf("\n"); after this call. Each traversal sequence must be printed on a new line according to the output format.]
    for(i=0;i<=100;i++)
    visited[i]=0; 
    for(i=0;i<=100;i++){
        if(weights[i][del]==1){
            weights[i][del]=0;
            weights[del][i]=0;
        }
    }
    printf("\n");
    dfs(0);
    printf("\n");
    for(i=0;i<=100;i++)
    visited[i]=0; 
    bfs(0);
    return 0;
}