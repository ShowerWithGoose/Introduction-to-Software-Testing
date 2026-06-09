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
    scanf("%d" , &del); // @@ The vertex to be deleted is read before the first traversals, but the graph structure is not yet modified. This is logically correct for reading input, but the subsequent logic modifies the graph permanently.
    dfs(0);
    printf("\n");
    for(i=0;i<=100;i++) // @@ Array bounds error: visited is size 101 (indices 0-100). Loop condition i<=100 accesses index 100 which is valid, but typically loops go to < size. However, the real issue is consistency with array size 101. Index 100 is valid for size 101. But wait, standard is 0 to 100. Size 101 means indices 0..100. So i<=100 is correct for clearing.
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