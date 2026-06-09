#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h> 
#define pi 3.14159265
#define eps 1e-10
#define max 300
int weight[max][max];
int visite[200];
int que[200];
void DFS(int v,int n)
{
	int i;
	printf("%d ",v);
	visite[v]=1;		
	for(i = 0; i < n; i++)
		if (weight[v][i] && !visite[i])	
		{
			DFS(i,n);	
		}
//	printf(" ");
//	puts(" ");
}
void BFS(int v,int n)
{
	int i,head=0,tail=1,tmp;
	que[head]=v;
	while(head<=tail)
	{
		tmp=que[head];	
		head++;			
		if(visite[tmp])	continue; 
		else
		{
			printf("%d ",tmp);	
			visite[tmp]=1;			
			for(i=0;i<n;i++)
				if (weight[tmp][i] && !visite[i])
					que[tail++]=i;	
		}
	}
	printf(" \n");
}
int main()
{	
	int u,v,d,n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&u,&v); 
		weight[u][v]=1;
		weight[v][u]=1;
	}
	DFS(0,n);
	printf(" \n");	
	memset(visite,0,sizeof(visite));	
	BFS(0,n);	
	scanf("%d",&d);
	memset(visite,0,sizeof(visite));	
	visite[d]=1;	
	DFS(0,n);
	printf(" \n");
	memset(visite,0,sizeof(visite));
	memset(que,0,sizeof(que));
	visite[d]=1;		
	BFS(0,n);	
	return 0;
}


