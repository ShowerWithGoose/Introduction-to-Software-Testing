#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct edge
{
	int adj;
	struct edge *elink;
};
struct ver
{
	int id;
	struct edge *link;
} graph[1000];
struct edge* insertedge(struct edge *head,int avex)
{
	struct edge *edge,*p,*ver_queue=NULL;
	edge=(struct edge *)malloc(sizeof(struct edge));
	edge->adj=avex;
	edge->elink=NULL;
	if(head==NULL)
	{
		head=edge;
		return head;
	}
	for(p=head; p!=NULL&&graph[p->adj].id<=graph[edge->adj].id; ver_queue=p,p=p->elink);
	if(p==head)
	{
		head=edge;
		edge->elink=p;
		return head;
	}
	ver_queue->elink=edge;
	edge->elink=p;
	return head;

}
int visited[1000],ver_queue[1000],rear=-1,front=0;
void DFS(int v,int id)
{
	struct edge *p;
	visited[v]=1;
	printf("%d ",id);
	for(p=graph[v].link; p!=NULL; p=p->elink)
		if(!visited[p->adj])
			DFS(p->adj,graph[p->adj].id);
}
void travelDFS(int ver)
{
	int i;
	for(i=0; i<ver; i++)
		visited[i]=0;
	for(i=0; i<ver; i++)
		if(graph[i].link!=NULL)
			if(!visited[i])
				DFS(i,graph[i].id);
}
void BFS(int v)
{
	visited[v]=1;
	struct edge *p;
	ver_queue[++rear]=v;
	while(front<=rear)
	{
		v=ver_queue[front++];
		printf("%d ",graph[v].id);
		for(p=graph[v].link; p!=NULL; p=p->elink)
		{
			if(!visited[p->adj])
			{
				visited[p->adj]=1;
				ver_queue[++rear]=p->adj;
			}
		}

	}
}
void travelBFS(int ver)
{
	int i;
	rear=-1;
	front=0;
	for(i=0; i<ver; i++)
		visited[i]=0;
	for(i=0; i<ver; i++)
		if(graph[i].link!=NULL)
			if(!visited[i])
				BFS(i);
}
void delgraphv(int v)
{
	struct edge *p;
	for(p=graph[v].link; p!=NULL; p=p->elink)
	{
		struct edge *ver_queue,*a=NULL;
		for(ver_queue=graph[p->adj].link; ver_queue!=NULL; a=ver_queue,ver_queue=ver_queue->elink)
		{
			if(ver_queue->adj==v)
			{
				if(ver_queue==graph[p->adj].link)
				{
					graph[p->adj].link=ver_queue->elink;
					free(ver_queue);
				}
				else
				{
					a->elink=ver_queue->elink;
					free(ver_queue);
				}
				break;
			}
		}
	}
	graph[v].link=NULL;
}
int main()
{
	int ver,edge,i;
	scanf("%d%d",&ver,&edge);
	for(i=0; i<edge; i++)
	{
		int vi,vj;
		scanf("%d%d",&vi,&vj);
		graph[vi].id=vi;
		graph[vj].id=vj;
		graph[vi].link=insertedge(graph[vi].link,vj);
		graph[vj].link=insertedge(graph[vj].link,vi);
	}
	int dele_num;
	scanf("%d",&dele_num);
	travelDFS(ver);
	printf("\n");
	travelBFS(ver);
	printf("\n");
	delgraphv(dele_num);
//	for(i=0; i<n; i++)
//	{
//		struct edge *p;
//		printf("%d:",graph[i].id);
//		for(p=graph[i].link; p!=NULL; p=p->elink)
//			printf("%d ",graph[p->adj].id);
//		printf("\n");
//	}
	travelDFS(ver);
	printf("\n");
	travelBFS(ver);
	printf("\n");
	return 0;
}


