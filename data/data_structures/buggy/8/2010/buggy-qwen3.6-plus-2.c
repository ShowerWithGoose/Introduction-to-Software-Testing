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
        if(visited[tmp]==1)    continue;    // @@ Error: Checking visited status upon dequeuing is incorrect for BFS; it should be marked upon enqueuing to prevent duplicate entries in the queue.
        else
        {
            printf("%d ",tmp);        
            visited[tmp]=1;        // @@ Error: Marking visited here (on dequeue) is incorrect. Vertices should be marked visited when they are added to the queue.
            for(j=0;i<m;j++)       // @@ Error: Loop condition incorrectly uses global variable 'i' instead of loop variable 'j', leading to incorrect iteration or an infinite loop.
                if (graph[tmp][j]==1 && visited[j]==0)
                    que[tail++]=j; // @@ Error: Missing 'visited[j]=1;' here. In BFS, a vertex must be marked as visited immediately when enqueued to avoid processing it multiple times.
        }
    }
}
int main(){
    int v1,v2,v;
    scanf("%d %d",&m,&n);
    
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