#include<stdio.h>
#include<string.h>
int weights[400][400],visited[400]={0},ch[200];
int n1,n2;	//顶点数和边数 
void travelDFS(int v)
{
	int i;
	printf("%d ",v);
	visited[v]=1;		
	for(i = 0; i < n1; i++)
		if (weights[v][i] && !visited[i])	
		{
			travelDFS(i);	
		}
}
void travelBFS(int v)
{
	int i,head=0,tail=1,tmp;	
	ch[head]=v;	//入队 
	while(head<=tail)
	{
		tmp=ch[head];	//出队 
		head++;		
		if(visited[tmp])	continue;	
		else
		{
			printf("%d ",tmp);		
			visited[tmp]=1;			
			for(i=0;i<n1;i++)
			{
			
				if (weights[tmp][i] && !visited[i])	
				{
					ch[tail++]=i;	
				}
		    }
		}
	}
}
int main()
{	
	int u,v,i,op;
	scanf("%d %d",&n1,&n2);
	for(i=0;i<n2;i++)
	{
		scanf("%d %d",&u,&v); //录入图的数据 
		weights[u][v]=1;
		weights[v][u]=1;
	}
	travelDFS(0);
	puts("");
	memset(visited,0,sizeof(visited));	
	travelBFS(0);
	puts("");	
	scanf("%d",&op);
	memset(visited,0,sizeof(visited));
	visited[op]=1;		
	travelDFS(0);
	puts("");	
	memset(visited,0,sizeof(visited));
	memset(ch,0,sizeof(ch));
	visited[op]=1;		
	travelBFS(0);puts("");	
	return 0;
}



