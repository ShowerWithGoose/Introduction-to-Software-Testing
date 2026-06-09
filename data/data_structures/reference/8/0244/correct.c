#include<stdio.h>
#include<string.h>
int weights[200][200],visited[200]={0},que[200];
int n,m;
int main()
{	
	int u,v,i,del;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v); 
		weights[u][v]=1;
		weights[v][u]=1;
	}
	travelDFS(0);puts("");	
	
	memset(visited,0,sizeof(visited));	 
	travelBFS(0);puts("");	
	
	scanf("%d",&del);
	memset(visited,0,sizeof(visited));	
	visited[del]=1;		 
	travelDFS(0);puts("");	
	
	memset(visited,0,sizeof(visited));memset(que,0,sizeof(que));//********注意：队列初始化不要忘了
	visited[del]=1;		
	travelBFS(0);puts("");	
	return 0;
}
	 
void travelDFS(int v)
{
	int i;
	printf("%d ",v);	
	visited[v]=1;		 
	for(i = 0; i < n; i++)
		if (weights[v][i] && !visited[i])	 
		{
			travelDFS(i);		
		}
}
void travelBFS(int v)
{
	int i,head=0,tail=1,tmp;	 
	que[head]=v;	
	while(head<=tail)	
	{
		tmp=que[head];	
		head++;			
		if(visited[tmp])	continue;	
		else
		{
			printf("%d ",tmp);		
			visited[tmp]=1;	
			for(i=0;i<n;i++)
				if (weights[tmp][i] && !visited[i])	
					que[tail++]=i;		
		}
	}
}




