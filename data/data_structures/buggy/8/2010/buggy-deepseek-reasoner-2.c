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
    while(head<=tail) // @@ [Error: Condition should be head < tail because tail points to next free slot. Using <= will cause an extra iteration accessing invalid queue element.]
    {
        tmp=que[head];    
        head++;            
        if(visited[tmp]==1)    continue;    
        else
        {
            printf("%d ",tmp);        
            visited[tmp]=1;        
            for(j=0;i<m;j++) // @@ [Error: Condition uses 'i' instead of 'j'. Should be j<m. This causes infinite loop or incorrect iteration.]
                if (graph[tmp][j]==1 && visited[j]==0)
                    que[tail++]=j; // @@ [Error: Should mark visited[j]=1 when enqueuing to prevent duplicate nodes from being added.]
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