#include<stdio.h>
int weights[200][200],visited[200]={0},que[200];
int n,m; 
void travel_DFS(int v)
{
 int i;
 printf("%d ",v); 
 visited[v]=1;   
 for(i = 0; i < n; i++)
  if (weights[v][i]&&!visited[i]) 
  {
   travel_DFS(i);  //DFS·ÃÎÊ 
  }
}
void travel_BFS(int v)
{
 int i,head=0,tail=1,tmp; 
 que[head]=v; 
 while(head<=tail) 
 {
  tmp=que[head]; 
  head++;   
  if(visited[tmp]) continue; 
  else
  {
   printf("%d ",tmp);  
   visited[tmp]=1;   
   for(i=0;i<n;i++)
    if (weights[tmp][i]&&!visited[i]) 
     que[tail++]=i;  
  }
 }
}
int main()
{ 
 int u,v,deletes;
 scanf("%d %d",&n,&m);
 for(int i=0;i<m;i++)
 {
  scanf("%d %d",&u,&v);
  weights[u][v]=1;
  weights[v][u]=1;
 }
 scanf("%d",&deletes);
 travel_DFS(0);printf("\n"); //DFS
 memset(visited,0,sizeof(visited)); 
 
 travel_BFS(0);printf("\n"); //BFS
 memset(visited,0,sizeof(visited)); 
 
 visited[deletes]=1;  
 travel_DFS(0);printf("\n"); //DFS
 memset(visited,0,sizeof(visited));memset(que,0,sizeof(que));
 
 visited[deletes]=1;  
 travel_BFS(0);printf("\n"); //BFS
 return 0;
}



