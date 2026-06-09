/*#include<stdio.h>
#include<stdlib.h>
typedef struct edge{
	int adjvex;
	struct edge *next;
}ELink;
typedef struct ver{
	int vertex;
	ELink *link;
}VLink;
VLink G[105];
void ADJLIST(VLink G[],int n,int e)//建立邻接表结构 
{
	int k,vi,vj;
	ELink *p1,*p2,*q1,*q2;
	for(k=0;k<n;k++)
	{
		G[k].vertex=k;
		G[k].link=NULL;
	}
	for(k=0;k<e;k++)
	{
		scanf("%d%d",&vi,&vj);
		p1=(ELink *)malloc(sizeof(ELink));
		p1->adjvex=vj;
		p1->next=NULL;
		if(!G[vi].link)
		{
			G[vi].link=p1;
		}
		else
		{
			q1=G[vi].link;
			while(q1->next)
			{
				q1=q1->next;
			}
			q1->next=p1;
		}
		p2=(ELink *)malloc(sizeof(ELink));
		p2->adjvex=vi;
		p2->next=NULL;
		if(!G[vj].link)
		{
			G[vj].link=p2;
		}
		else
		{
			q2=G[vj].link;
			while(q2->next)
			{
				q2=q2->next;
			}
			q2->next=p2;
		}
	}
}
ELink *insertEdge(VLink G[],ELink *head,int k,int avex)
{
	ELink *e,*p,*temp,*r;
	e=(ELink *)malloc(sizeof(ELink));
	e->adjvex=avex;
	e->next=NULL;
	if(head==NULL)
	{
		head=e;
		return head;
	}
	if(avex<head->adjvex)
	{
		e->next=G[k].link;
		G[k].link=e;
		return e;
	}
	for(p=head,r=p;p!=NULL;p=p->next)
	{
		r=p;
		if(avex<p->adjvex)break;
	}
	e->next=r->next;
	r->next=e;
	return head;
}
void create(VLink G[],int n,int e)
{
	int k,vi,vj;
	ELink *p1,*p2,*q1,*q2;
	for(k=0;k<n;k++)
	{
		G[k].vertex=k;
		G[k].link=NULL;
	}
	for(k=0;k<e;k++)
	{
		scanf("%d%d",&vi,&vj);
		G[vi].link=insertEdge(G,G[vi].link,vi,vj);
		G[vj].link=insertEdge(G,G[vj].link,vj,vi);
	}
}
void DELVER(VLink G[],int n,int item)//删除顶点 
{
	int i;
	ELink *p,*q,*r;
	p=G[item].link;
	while(p!=NULL)
	{
		r=p;
		p=p->next;
		free(r);
	}
	for(i=0;i<n;i++)
	{
		if(i==item)continue;
		else
		{
			p=G[i].link;
			while(p!=NULL)
			{
				if(p->adjvex==item)
				{
					if(G[i].link==p)
					    G[i].link=p->next;
					else
					    q->next=p->next;
					r=p;
					p=p->next;
					free(r);
				}
				else
				{
					q=p;
					p=p->next;
				}
			}
		}
	}
}
int visited[105];
void DFS(VLink G[],int v)
{
	ELink *p;
	visited[v]=1;
	printf("%d ",v);
	for(p=G[v].link;p!=NULL;p=p->next)
	{
		if(visited[p->adjvex]==0)
		{
			DFS(G,p->adjvex);
		}
	}
}
void TRAVEL_DFS(VLink G[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
		    DFS(G,i);
	}
}
int q[105],front=-1,rear=-1;
void BFS(VLink G[],int v)
{
	ELink *p;
	visited[v]=1;
	q[++rear]=v;
	while(front<rear)
	{
		v=q[++front];
		printf("%d ",v);
		for(p=G[v].link;p!=NULL;p=p->next)
		{
			if(!visited[p->adjvex])
			{
				visited[p->adjvex]=1;
			    q[++rear]=p->adjvex;
			}
			
		}
	}
}
void TRAVEL_BFS(VLink G[],int n)
{
	int i;
	for(i=0;i<n;i++)visited[i]=0;
	for(i=0;i<n;i++)
	{
		if(!visited[i])
		    BFS(G,i);
	}
	
}
int main()
{
	int n,e,i,item;
	scanf("%d%d",&n,&e);
	ADJLIST(G,n,e);
	scanf("%d",&item);
	TRAVEL_DFS(G,n);
	printf("\n");
	TRAVEL_BFS(G,n);
	printf("\n");
	DELVER(G,n,item);
	TRAVEL_DFS(G,n);
	printf("\n");
	TRAVEL_BFS(G,n);
	return 0;
}*/


#include<stdio.h>
int a[105][105],visited[105];
void ADJMATRIX(int a[][105],int n,int e)
{
	int i,j,k;
	for(k=0;k<e;k++)
	{
		scanf("%d%d",&i,&j);
		a[i][j]=1;
		a[j][i]=1;
	}
}
void DFS(int a[][105],int n,int v)
{
	int i,j,k;
	printf("%d ",v);
	visited[v]=1;
	for(i=0;i<n;i++)
	{
		if(a[v][i]==1&&visited[i]==0)
		    DFS(a,n,i);  
	}
}
void TRAVEL_DFS(int a[][105],int visited[],int n)
{
	int i;
	
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
		    DFS(a,n,i);
	}
}
int q[105];
void BFS(int a[][105],int n,int v)
{
	int i,front=-1,rear=-1;
	visited[v]=1;
	q[++rear]=v;
	while(front<rear)
	{
		v=q[++front];
		printf("%d ",v);
		for(i=0;i<n;i++)
		{
			if(a[v][i]==1&&visited[i]==0)
			{
				visited[i]=1;
				q[++rear]=i;
			}
		}
	}
}
void TRAVEL_BFS(int a[][105],int n)
{
	int i;

	for(i=0;i<n;i++)
	{
		if(!visited[i])
		    BFS(a,n,i);
	}
	
}
void DELETE(int a[][105],int n,int item)
{
	int i;
	for(i=0;i<n;i++)
	{
		a[i][item]=0;
	}
	for(i=0;i<n;i++)
	{
		a[item][i]=0;
	}
}
int main()
{
	int n,e,i,item;
	scanf("%d%d",&n,&e);
	ADJMATRIX(a,n,e);
	scanf("%d",&item);
	for(i=0;i<n;i++)visited[i]=0;
	TRAVEL_DFS(a,visited,n);
	printf("\n");
	for(i=0;i<n;i++)visited[i]=0;
	TRAVEL_BFS(a,n);
	printf("\n");
	DELETE(a,n,item);
	for(i=0;i<n;i++)visited[i]=0;
	visited[item]=1;
	TRAVEL_DFS(a,visited,n);
	printf("\n");
	for(i=0;i<n;i++)visited[i]=0;
	visited[item]=1;
	TRAVEL_BFS(a,n);
	printf("\n");
	return 0;
}

