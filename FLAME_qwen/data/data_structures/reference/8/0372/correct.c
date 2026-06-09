#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int G[100][100],visit[100],cnt=0,dui[100]={0};
void shendu(int n,int p)
{
	int u=p,v;
	visit[u]=1;
	printf("%d ",u);
	for(v=0;v<n;v++)
		if(G[u][v]==1&&visit[v]!=1)
		{
			shendu(n,v);
		}
	if(v==n)	return;		
}
void guangdu(int n, int p)
{
	int i=0,k=0,u=p,v;
	dui[i]=u;
	visit[u]=1;
	while(dui[0]==0||dui[i]!=0&&i>0)
	{
		u=dui[i];
		printf("%d ",u);
		cnt++;
		if(cnt==n)	break;
		dui[i]=-1;	//取出队头 
		for(v=0;v<n;v++)
			if(G[u][v]==1&&visit[v]!=1)
			{
				dui[++k]=v;
				visit[v]=1;
			}
		i+=1;
	}
}
int main()
{
	int n,m,i=0,j=0,u,v,del;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		G[u][v]=G[v][u]=1;
	}
	scanf("%d",&del);
	shendu(n,0);
	printf("\n");
	for(i=0;i<n;i++)	visit[i]=0;
	cnt=0;
	guangdu(n,0);
	printf("\n");
	cnt=0;
	for(i=0;i<n;i++)	
	{
		visit[i]=0;
		dui[i]=0;
	}
	for(i=0;i<n;i++)	//删除 
	{
		G[del][i]=G[i][del]=0;
	}
	shendu(n,0);
	printf("\n");
	for(i=0;i<n;i++)	visit[i]=0;
	cnt=0;
	guangdu(n,0);
	return 0;
}


