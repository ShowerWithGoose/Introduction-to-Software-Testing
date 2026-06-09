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
    for(i = 0; i < m; i++)
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
        if(visited[tmp]==1)    continue;    // @@ [Visited should be marked when a vertex is enqueued, not when popped. This can cause duplicate enqueues and incorrect BFS order.]
        else
        {
            printf("%d ",tmp);        
            visited[tmp]=1;        
            for(j=0;i<m;j++)    // @@ [Error: loop condition uses 'i' (global variable) instead of 'j'. Should be 'j<m'. This will either fail to iterate or cause an infinite loop.]
                if (graph[tmp][j]==1 && visited[j]==0)
                    que[tail++]=j;    // @@ [Visited should be set to 1 immediately after enqueuing to avoid duplicates. Missing visited[j]=1.]
        }
    }
}
int main(){
    int v1,v2,v;
    scanf("%d %d",&m,&n);    // @@ [Variable order swapped: first input (vertices) is stored in m, second (edges) in n. This is counterintuitive but consistent with loops. However, it may cause confusion.]
    
    for(i=0;i<n;i++){
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