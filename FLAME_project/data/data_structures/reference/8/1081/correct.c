#include <stdio.h>
#include <memory.h>
int G[200][200];
int v_n;//¶¥µãÊý£¬·Ç±àºÅ 
int e_n;
int visited[100];
void dfs(int v)
{ 
    printf("%d ",v);
    visited[v]++;
    int i;
    for(i=0;i<=v_n-1;i++)
    {
    	 if(!visited[i]&&G[v][i])
    	 {
    	 	 dfs(i);
		 }
	}
}
void bfs()
{
	 int queue[200];
	 int front=0,rear=-1;
	 queue[++rear]=0;
	 visited[0]++;
	 int i; 
	 while(front<=rear)
	 {
	 	 int k=queue[front++];
	 	 printf("%d ",k);
	 	 for(i=0;i<=v_n-1;i++)
	 	 {
	 	 	 if(!visited[i]&&G[k][i])
	 	 	 {
	 	 	 	  visited[i]++;
	 	 	 	  queue[++rear]=i;
			   }
		  }
	 }
	 puts("");
	 memset(visited,0,sizeof(visited));
}
int main()
{
	 scanf("%d%d",&v_n,&e_n);
	 int i;
	 int x,y;
	 for(i=1;i<=e_n;i++)
	 {
	 	 scanf("%d%d",&x,&y);
	 	 G[x][y]=G[y][x]=1;
	 }
	 int be_deleted;
	 scanf("%d",&be_deleted);
	 dfs(0);
	 puts("");
	 memset(visited,0,sizeof(visited));
	 bfs();
	 for(i=0;i<=v_n-1;i++)
	 {
	 	 G[i][be_deleted]=G[be_deleted][i]=0;
	 }
	 dfs(0);
	 	 memset(visited,0,sizeof(visited));
	 puts("");
	 bfs();
	 return 0; 
}

