#include<stdio.h>
#include<string.h>
int weights[200][200],visited[200]={0},que[200];

int n,m;	
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
void gg()
{
	travelDFS(0);puts("");	
	
	memset(visited,0,sizeof(visited));	 
	travelBFS(0);puts("");
	
	
 } 
 void ff()
 {
 		travelDFS(0);puts("");	
	
	memset(visited,0,sizeof(visited));memset(que,0,sizeof(que));
	
 }
 void ee(){
 memset(visited,0,sizeof(visited));	
 }
 void dd()
 {
 	travelBFS(0);puts("");
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
	gg();
	scanf("%d",&del);
	ee();	
	visited[del]=1;		
	ff();
	visited[del]=1;		
	dd();
	return 0;
}



