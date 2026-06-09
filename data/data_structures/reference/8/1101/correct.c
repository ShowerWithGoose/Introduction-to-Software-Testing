#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>
int weights[200][200],visited[200]={0},queue[200];
int n,m;
void travelDFS(int v)
{
	int i;
	printf("%d ",v);
	visited[v]=1;
	for(i=0;i<n;i++)
	{
		if(weights[v][i]&&!visited[i])
		{
			travelDFS(i);
		}
	}
}
void travelBFS(int v)
{
	int i,head=0,tail=1,temp;
	queue[head]=v;
	while(head<=tail)
	{
		temp=queue[head];
		head++;
		if(visited[temp])
		{
			continue;
		}
		else
		{
			printf("%d ",temp);
			visited[temp]=1;
			for(i=0;i<n;i++)
			{
				if(weights[temp][i]&&!visited[i])
				{
					queue[tail]=i;
					tail++;
				}
			}
		}
	}
}
int main()
{
	int i,j,k;
	int p;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++)
	{
		scanf("%d %d",&j,&k);
		weights[j][k]=1;
		weights[k][j]=1;
	}
	travelDFS(0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	travelBFS(0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	scanf("%d",&p);
	visited[p]=1;
	travelDFS(0);
	printf("\n");
	memset(visited,0,sizeof(visited));
	visited[p]=1;
	travelBFS(0);
	printf("\n");
	return 0;
}

