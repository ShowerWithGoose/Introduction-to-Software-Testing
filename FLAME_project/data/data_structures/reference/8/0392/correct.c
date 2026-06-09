#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int visit[100];
int sum_dot,sum_dash;
char ddash[100][100];
int Firstdot(int v)
{
	int i;
	for(i=0;i<sum_dot;i++)
	{
		if(ddash[v][i]!=-1&&visit[i]==0)
		return i;
	}
	return 101;
}
int Nextdot(int w,int v)
{
	int i;
	for(i=w;i<sum_dot;i++)
	{
		if(ddash[v][i]!=-1&&visit[i]==0)
		return i;
	}
	return 101;
}
void DFS(int v)
{
	int w;
	printf("%d ",v);
	visit[v]=1;
	w=Firstdot(v);
	while(w!=101)
	{
		if(visit[w]==0)
		DFS(w);
		w=Nextdot(w,v);
	}
	return;
}
void TDFS()
{
	int i;
	for(i=0;i<sum_dot;i++)
	visit[i]=0;
	for(i=0;i<sum_dot;i++)
	if(visit[i]==0)
	DFS(i);
}
void DTDFS(int dit)
{
	int i;
	for(i=0;i<sum_dot;i++)
	visit[i]=0;
	visit[dit]=1;
	for(i=0;i<sum_dot;i++)
	if(visit[i]==0)
	DFS(i);
}

int q[100],sum_q=0;
void BFS(int v)
{
	int w,i;
	printf("%d ",v);
	visit[v]=1;
	q[sum_q]=v;
	sum_q++;
	while(sum_q!=0)
	{
		v=q[0];
		for(i=0;i<sum_q;i++)
		{
			q[i]=q[i+1];
		}
		sum_q--;
		w=Firstdot(v);
		while(w!=101)
		{
			if(visit[w]==0)
			{
				printf("%d ",w);
				visit[w]=1;
				q[sum_q]=w;
				sum_q++;
			}
			w=Nextdot(w,v);
		}
	}
	return;
}
void TBFS()
{
	int i;
	for(i=0;i<sum_dot;i++)
	visit[i]=0;
	for(i=0;i<sum_dot;i++)
	{
		if(visit[i]==0)
		BFS(i);
	}
}
void DTBFS(int dit)
{
	int i;
	for(i=0;i<sum_dot;i++)
	visit[i]=0;
	visit[dit]=-1;
	for(i=0;i<sum_dot;i++)
	{
		if(visit[i]==0)
		BFS(i);
	}
}
int main()
{
	int i,j,first,last,dit;
	scanf("%d %d",&sum_dot,&sum_dash);
	for(i=0;i<100;i++)
	{
		for(j=0;j<100;j++)
		ddash[i][j]=-1;
	}
	for(i=0;i<sum_dash;i++)
	{
		scanf("%d %d",&first,&last);
		ddash[first][last]=1;
		ddash[last][first]=1;
	}
	scanf("%d",&dit);
	TDFS();
	printf("\n");
	TBFS();
	printf("\n");
	DTDFS(dit);
	printf("\n");
	DTBFS(dit);
	printf("\n");
	return 0;
}

