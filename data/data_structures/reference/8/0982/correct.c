#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
typedef struct edge{
	int num;
	struct edge *next;
}Link;
int visited[105],del=-1;

Link* insertEdge(Link* head,int edge)//为无向图插入一条边
{
	Link *p,*q,*p0;
	p0=(Link*)malloc(sizeof(Link));
	p0->num=edge;
	p0->next=NULL;
	if(head==NULL)
		head=p0;
	else if(p0->num<head->num)
	{
		p0->next=head;
		head=p0;
	}
	else
	{
		for(q=head,p=q->next;p!=NULL;q=p,p=p->next)
			if(p0->num<p->num)
			{
				p0->next=p;
				q->next=p0;
				break;
			}
		if(p==NULL)
			q->next=p0;
	}
	return head;
}

void DFS(Link graph[],int vex)
{
	if(vex==del)
		return;
	Link *p;
	visited[vex]=1;
	printf("%d ",vex);
	for(p=graph[vex].next;p!=NULL;p=p->next)
		if(!visited[p->num])
			DFS(graph,p->num);
}
void travelDFS(Link graph[],int vexnum)//深度优先遍历
{
	int vex;
	for(vex=0;vex<vexnum;vex++)
		if(!visited[vex])
			DFS(graph,vex);
	printf("\n");
}

void BFS(Link graph[],int vex)
{
	Link *p;
	int queue[105],front=0,rear=-1;
	visited[vex]=1;
	if(vex!=del)
		queue[++rear]=vex;
	while(rear>=front)
	{
		vex=queue[front++];
		printf("%d ",vex);
		for(p=graph[vex].next;p!=NULL;p=p->next)
			if(!visited[p->num])
			{
				visited[p->num]=1;
				if(p->num!=del)
				queue[++rear]=p->num;
			}
	}
}
void travelBFS(Link graph[],int vexnum)//广度优先遍历
{
	int vex;
	for(vex=0;vex<vexnum;vex++)
		if(!visited[vex])
			BFS(graph,vex);
	printf("\n");
}

int main()
{
	Link graph[105];
	int vexnum,edgenum,vex,edge,i,de;
	scanf("%d%d",&vexnum,&edgenum);
	for(i=0;i<vexnum;i++)
		graph[i].next=NULL;
	for(i=0;i<edgenum;i++)
	{
		scanf("%d%d",&vex,&edge);
		graph[vex].next=insertEdge(graph[vex].next,edge);
		graph[edge].next=insertEdge(graph[edge].next,vex);
	}
	scanf("%d",&de);
	travelDFS(graph,vexnum);
	memset(visited,0,sizeof(visited));
	travelBFS(graph,vexnum);
	memset(visited,0,sizeof(visited));
	del=de;
	travelDFS(graph,vexnum);
	memset(visited,0,sizeof(visited));
	travelBFS(graph,vexnum);	
    return 0;
}
