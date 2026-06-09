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
        if(!visited[tmp]){ // @@ Marking visited on dequeue instead of enqueue can cause multiple enqueues of the same vertex, potentially affecting BFS order and queue size.
            printf("%d " , tmp);
            visited[tmp]=1;
            for(i=0;i<num_vertex;i++){
                if(weights[tmp][i] && !visited[i]) que[tail++] = i; // @@ Since visited is not set until dequeue, the same vertex may be enqueued multiple times by different neighbors.
            }
        }
    }
}
int main()
{
    int u , v , i , del;
    scanf("%d %d" , &num_vertex , &num_edge);
    for(i=0;i<100;i++)
    for(int j=0;j<100;j++) // @@ Declaration of 'j' inside for loop may cause compilation error in C89 compilers.
    weights[i][j]=0;
    for(int j=0;j<100;j++) // @@ Declaration of 'j' inside for loop (again) may cause compilation error in C89 compilers.
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
    bfs(0);
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