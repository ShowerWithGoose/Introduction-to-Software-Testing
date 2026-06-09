#include<stdio.h>
#include<string.h>
int weights[300][300],visited[300]={0},que[300];
int n,m;	
void bianli1(int v)
{
	int i;
	printf("%d ",v);
	visited[v]=1;		
	for(i = 0; i < n; i++)
		if (weights[v][i]&&visited[i]==0)
		{
			bianli1(i);	
		}
}
void bianli2(int v)
{
	int i,head=0,tail=1,tmp; 
	que[head]=v;
	while(head<=tail) 
	{
		tmp=que[head];	
		head++;		
		if(visited[tmp]);
		else
		{
			printf("%d ",tmp);		
			visited[tmp]=1;		 
			for(i=0;i<n;i++)
				if(weights[tmp][i] && visited[i]==0)	
					que[tail++]=i;		
		}
	}
}
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
	bianli1(0);puts("");
	
	memset(visited,0,sizeof(visited));
	bianli2(0);puts("");
	scanf("%d",&del);
	memset(visited,0,sizeof(visited));
	visited[del]=1;	
	bianli1(0);puts("");
	memset(visited,0,sizeof(visited));memset(que,0,sizeof(que));
	visited[del]=1;	
	bianli2(0);puts("");
	return 0;
}

