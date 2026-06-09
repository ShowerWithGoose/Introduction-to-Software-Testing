#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int w[200][200],fw[200]={0},que[200];
int n,m;	 
void DFS(int v);
void BFS(int v);
int main()
{	
	int u,v,i,del;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v);  
		w[u][v]=1;
		w[v][u]=1;
	}
	DFS(0);puts("");	
	memset(fw,0,sizeof(fw));	
	BFS(0);puts("");	
	scanf("%d",&del);
	memset(fw,0,sizeof(fw));	
	fw[del]=1;		
	DFS(0);puts("");	
	memset(fw,0,sizeof(fw));
	memset(que,0,sizeof(que));
	fw[del]=1;		
	BFS(0);puts("");
	return 0;
}
void DFS(int v)
{
	int i;
	printf("%d ",v);	 
	fw[v]=1;		 
	for(i = 0; i < n; i++)
		if (w[v][i] && !fw[i])	
		{
			DFS(i);	 
		}
}
void BFS(int v)
{
	int i,head=0,tail=1,tmp;	
	que[head]=v;	
	while(head<=tail)	
	{
		tmp=que[head];
		head++;		
		if(fw[tmp])	continue;
		else
		{
			printf("%d ",tmp);		
			fw[tmp]=1;		
			for(i=0;i<n;i++)
				if (w[tmp][i] && !fw[i])	
					que[tail++]=i;	 
		}
	}
}

