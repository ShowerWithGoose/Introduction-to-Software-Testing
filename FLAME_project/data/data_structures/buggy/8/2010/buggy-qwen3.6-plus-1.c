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
    for(i = 0; i < m; i++) // @@ The loop bound should be 'n' (number of vertices), not 'm' (number of edges). Also, variable 'i' is global and shared with bfs, causing state corruption.
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
            for(j=0;i<m;j++) // @@ The loop condition uses global variable 'i' instead of local variable 'j'. It should be 'j < n' (number of vertices). Using 'i' causes infinite loop or incorrect bounds, and 'm' is wrong dimension.
                if (graph[tmp][j]==1 && visited[j]==0)
                    que[tail++]=j;
        }
    }
}
int main(){
    int v1,v2,v;
    scanf("%d %d",&m,&n); // @@ The input format is "n m" (vertices then edges), but the code reads into "m n". This swaps the number of vertices and edges.
    
    for(i=0;i<n;i++){ // @@ This loop runs 'n' times (which is actually edges count due to swap above). It should run 'm' times (actual edge count).
        scanf("%d %d",&v1,&v2);
        graph[v1][v2]=graph[v2][v1]=1;
    }
    scanf("%d",&v);
    dfs(0);
    printf("\n");
    memset(visited,0,sizeof(visited));
    bfs(0);
    printf("\n");
    for(i=0;i<m;i++){ // @@ Should iterate over 'n' (vertices) to clear connections for the deleted vertex. Due to swap, 'm' is vertices count, so this might accidentally work for clearing but logic is confused.
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