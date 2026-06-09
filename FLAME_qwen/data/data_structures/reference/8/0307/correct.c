#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int  list[100000],fr,re,G[1000][1000],Visited[100000];
void travelBFS(int G[][1000],int n,int A)//可能有问题
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		Visited[i]=0;
	}
	fr=0;
	re=0;
	for(k=0;k<n;k++)
	{
		i=k;
		if(!Visited[i]&&i!=A)
		{
			printf("%d ",i);
			Visited[i]=1;
			list[re++]=i;
			re%=100000;
			while(re!=fr)
			{
				i=list[fr++];
				fr%=100000;
				for(j=0;j<n;j++)
				{
					if(G[i][j]==1&&!Visited[j])
					{
						printf("%d ",j);
						Visited[j]=1;
						list[re++]=j;
						re%=100000;
					}
				}
			} 
		}
	}
} //广度优先无向图，有上限100000 

void travelDFS(int G[][1000],int n,int p)//可能有问题 
{
	int i;
	Visited[p]=1;
	printf("%d ",p); 
	for(i=0;i<n;i++)
	{
		if(Visited[i]==0&&G[p][i]!=0)
		{
			travelDFS(G,n,i);
		}
	}
}//矩阵的无向图遍历 

int main()
{
	int n,m,a,b,i,A;
	scanf("%d%d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d%d",&a,&b);
		G[a][b]=1;
		G[b][a]=1;
	}
	scanf("%d",&A);
	travelDFS(G,n,0);
	printf("\n");
	travelBFS(G,n,-1);
	printf("\n");
	for(i=0;i<n;i++)
	{
		G[i][A]=0;
	}
	for(i=0;i<n;i++)
	{
		G[A][i]=0;
	}
	for(i=0;i<1000;i++)
	{
		Visited[i]=0;
	}
	travelDFS(G,n,0);
	printf("\n");
	travelBFS(G,n,A);
	return 0;
}

