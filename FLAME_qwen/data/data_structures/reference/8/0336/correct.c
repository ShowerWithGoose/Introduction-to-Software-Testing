#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int Vnum,Enum;
int visit[101]={0};
int edge[101][101]={{0}};
void shendu(int v);
void guangdu(int v);
int main()
{
	
	scanf("%d %d",&Vnum,&Enum);
	int i,v1,v2;
	for(i=0;i<Enum;i++)
	{
		scanf("%d %d",&v1,&v2);
		edge[v1][v2]=1;
		edge[v2][v1]=1;
	}
	shendu(0); 
	printf("\n");
	for(i=0;i<Vnum;i++)
	{
		visit[i]=0;
	}
	guangdu(0);
	printf("\n");
	for(i=0;i<Vnum;i++)
	{
		visit[i]=0;
	}
	int del;
	scanf("%d",&del);
	for(i=0;i<Vnum;i++)
	{
		edge[i][del]=0;
		edge[del][i]=0;
	}
	shendu(0); 
	printf("\n");
	for(i=0;i<Vnum;i++)
	{
		visit[i]=0;
	}
	guangdu(0);
	return 0;
}
void shendu(int v)
{
	int i;
	printf("%d ",v);
	visit[v]=1;
	for(i=0;i<Vnum;i++)
	{
		if(edge[i][v]==1)
		{
			if(visit[i]==0)
			{
				shendu(i);
			}
		}
	}
}
void guangdu(int v)
{
	int vnow,i;
	int queue[102]={0};
	int rear=-1,head=0;
	queue[++rear]=v;
	printf("%d ",v);
	visit[v]=1;
	while(rear>=head)
	{
		vnow=queue[head++];
		for(i=0;i<Vnum;i++)
		{
			if(edge[i][vnow]==1)
			{
				if(visit[i]==0)
				{
					queue[++rear]=i;
					printf("%d ",i);
					visit[i]=1;
				}
			}
		}
	}
}



