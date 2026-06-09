#include<stdio.h>
#include<string.h>
int w[200][200],vi[200],q[200];
int n,m;
void travelDFS(int u)
{
	int i;
	printf("%d ",u);
	vi[u]=1;
	for(i = 0; i < n; i++)
		if (w[u][i] && !vi[i])
		{
			travelDFS(i);		
		}
}
void travelBFS(int u)
{
	int i,head=0,tail=1,tmp;	
	q[head]=u;	
	while(head<=tail)	
	{
		tmp=q[head];	
		head++;		
		if(vi[tmp])	continue;	
		else
		{
			printf("%d ",tmp);	
			vi[tmp]=1;			
			for(i=0;i<n;i++)
				if (w[tmp][i] && !vi[i])	
					q[tail++]=i;	
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
		w[u][v]=1;
		w[v][u]=1;
	}
	travelDFS(0);puts("");	
	for(int i=0;i<200;i++){
		vi[i]=0;
	}	
	travelBFS(0);puts("");	
	
	scanf("%d",&del);
	for(int i=0;i<200;i++){
		vi[i]=0;
	}		
	vi[del]=1;		
	travelDFS(0);puts("");
	
	for(int i=0;i<200;i++){
		vi[i]=0;
		q[i]=0;
	}
	vi[del]=1;	
	travelBFS(0);puts("");	
	return 0;
}

