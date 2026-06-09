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
        if(visited[tmp]==1)    continue;    
        else
        {
            printf("%d ",tmp);        
            visited[tmp]=1;        
            for(j=0;i<m;j++) // @@ [The loop condition uses 'i' instead of 'j', causing incorrect loop behavior and potential infinite loop or out-of-bounds access]
                if (graph[tmp][j]==1 && visited[j]==0)
                    que[tail++]=j;
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