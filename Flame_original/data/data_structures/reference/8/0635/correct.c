#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct graph_s
{
	int nv;
	int ne;
	int *edge;
}graph;
graph* SetMap();
int GetLoc(int m,int n);
void DFS(graph*map,int k,int *visited);
void BFS(graph* map,int k,int *quene,int *head,int*rear,int*visited);
void DeleteMap(graph*map);
int main()
{
	graph*map=SetMap();
	int *visited=(int*)malloc(sizeof(int)*(map->nv));
	int *quene=(int*)malloc(sizeof(int)*(map->nv));
    int head=0,rear=0;
	memset(visited,0,sizeof(int)*map->nv);
	DFS(map,0,visited);
	putchar('\n');
	memset(visited,0,sizeof(int)*map->nv);
	BFS(map,0,quene,&head,&rear,visited);
	putchar('\n');
	memset(visited,0,sizeof(int)*map->nv);
	head=0;rear=0;
	DeleteMap(map);
	DFS(map,0,visited);
	putchar('\n');
	memset(visited,0,sizeof(int)*map->nv);
	BFS(map,0,quene,&head,&rear,visited);
	putchar('\n');
	return 0;
}
graph* SetMap()
{
	graph* map=(graph*)malloc(sizeof(graph));
	scanf("%d%d",&map->nv,&map->ne);
	map->edge=(int *)malloc(sizeof(int)*(1+map->nv)*(map->nv)/2);
	memset(map->edge,0,sizeof(int)*(1+map->nv)*(map->nv)/2);
	int i;
	for(i=0;i<map->ne;i++)
	{
		int m,n;
		scanf("%d%d",&m,&n);
		map->edge[GetLoc(m,n)]=1;
	}
	return map;
}
int GetLoc(int m,int n)
{
	if(m>=n)
	return (1+m)*m/2+n;
	else return (1+n)*n/2+m;
}
void DFS(graph*map,int k,int *visited)
{
	printf("%d ",k);
	visited[k]=1;
	int i;
	for(i=0;i<map->nv;i++)
	{
		int loc=GetLoc(i,k);
		if(visited[i]==0&&map->edge[loc])
		{
			DFS(map,i,visited);
		} 
	}
	return;
}
void BFS(graph* map,int k,int *quene,int *head,int*rear,int*visited)
{
	printf("%d ",k);
	visited[k]=1;
	quene[((*rear)++)%(map->nv)]=k;
	int i,flag=0;
	while((*rear-*head)!=0||flag!=1)
	{
	k=quene[((*head)++)%(map->nv)];
	flag=1;
	for(i=0;i<map->nv;i++)
	{
		if(visited[i]==0&&map->edge[GetLoc(i,k)])
		{
			printf("%d ",i);
			visited[i]=1;
			quene[(*rear)++]=i;
			flag=0;
		}
	}
	}
	return;
}
void DeleteMap(graph*map)
{
	int k;
	scanf("%d",&k);
	int i;
	for(i=0;i<map->nv;i++)
	map->edge[GetLoc(i,k)]=0;
	return;
}



