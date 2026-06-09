#include<stdio.h>
#include<stdlib.h>
typedef struct edge{
	int adj;
	struct edge *next;//指向下一个边结点 
}Elink; //边结点 
typedef struct ver{
	int ver;
	Elink *link;
}vlink;//顶点
vlink list[105];
int sum1,sum2,visit[105];//visit标记是否访问过结点
int queue[210],rear=-1,front=0,a=-1;
Elink *insert(Elink *head,int v);
void creatgraph();
void DFS(vlink list[],int v);
void TRAVEL_DFS();
void BFS(vlink list[],int v);
void TRAVEL_BFS();
int main()
{
	scanf("%d %d",&sum1,&sum2);//顶点，边 
	creatgraph();
//	Elink *p=list[0].link;
//	for(;p!=NULL;p=p->next)
//	printf("%d ",p->adj);
	TRAVEL_DFS();
	printf("\n");
	TRAVEL_BFS();
	printf("\n");
	scanf("%d",&a);
	TRAVEL_DFS();
	printf("\n");
	TRAVEL_BFS();
	printf("\n");
 } 
Elink *insert(Elink *head,int v)
{
	Elink *p,*q,*r;
	p=(Elink *)malloc(sizeof(Elink));
	p->adj=v;
	p->next=NULL;
	if(head==NULL)
	return p;
	else if(v<head->adj)
	{
		p->next=head;
		return p;
	}
	else
	{
		for(q=head;q!=NULL&&q->adj<v;q=q->next)
		r=q;
		r->next=p;
		p->next=q;
		return head;
	}
}
void creatgraph()
{
	int i,vi,vj;
//	Elink *p,*q,*head;
	for(i=0;i<sum1;i++)
	{
		list[i].link=NULL;
	}
	for(i=0;i<sum2;i++)
	{
		scanf("%d %d",&vi,&vj);
		list[vi].link=insert(list[vi].link,vj);
		list[vj].link=insert(list[vj].link,vi);	
	}
}
void DFS(vlink list[],int v)
{
	Elink *p;
	visit[v]=1;
	printf("%d ",v);
	for(p=list[v].link;p!=NULL;p=p->next)
	if(visit[p->adj]==0)
	DFS(list,p->adj); 
}
void TRAVEL_DFS()
{
	int i;
	for(i=0;i<sum1;i++)
	visit[i]=0;
	if(a!=-1) visit[a]=1;
	DFS(list,0);
}
void BFS(vlink list[],int v)
{
	Elink *p;
	visit[v]=1;
	queue[++rear]=v;
	while(front!=rear+1)
	{
		v=queue[front++];
		printf("%d ",v);
		for(p=list[v].link;p!=NULL;p=p->next){
			if(visit[p->adj]==0){
			visit[p->adj]=1;
			queue[++rear]=p->adj;
			}
		}
	}
}
void TRAVEL_BFS()
{
	int i;
	for(i=0;i<sum1;i++)
	visit[i]=0;
	if(a!=-1) visit[a]=1;
	BFS(list,0);
}

