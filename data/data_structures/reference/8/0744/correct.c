#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct edge{
	int adj;
	struct edge* next;
};

struct adjvex{
	struct edge* head;
};

struct adjvex G[1024];
int judge[1024][1024];//判断这条路是否被走过 
int flage[1024];
struct adjvex queue[1024];
int queue_num;
struct edge* insert(struct edge* head,int elem)
{
	struct edge* p=(struct edge*)malloc(sizeof(struct edge));
	struct edge* q,* front;
	p->adj=elem;
	p->next=NULL;
	if(head==NULL)return p;
	
	for(q=head,front=head;q!=NULL;front=q,q=q->next)
	{
		if(p->adj<q->adj)break;
	}
	if(q==head)
	{
		p->next=q;
		return p;
	}else if(q==NULL)
	{
		front->next=p;
		return head;
	}else
	{
		front->next=p;
		p->next=q;
		return head;
	}
}

void dfs(int a,int delete_num)
{
	printf("%d ",a);
	flage[a]=1;
	struct edge* p;
	p=G[a].head;
	for(p=G[a].head;p!=NULL;p=p->next)
	{
		if(flage[p->adj]!=1&&p->adj!=delete_num)
		{
			
			flage[p->adj]=1;//不可以解开 
			dfs(p->adj,delete_num);
		//	judge[a][p->adj]=0;
		//	flage[p->adj]=0;
		}
	}
}

void bfs(int delete_num)
{
	int low=0,high=0,i;
	struct edge* p;
	struct adjvex q;
	queue[high++]=G[0];
	flage[0]=1;
	printf("%d ",0);
	while(low<high)
	{
		q=queue[low];
		low++;
		for(p=q.head;p!=NULL;p=p->next)
		{
			if(flage[p->adj]!=1&&p->adj!=delete_num)
			{
				queue[high++]=G[p->adj];
				flage[p->adj]=1;
				printf("%d ",p->adj);
			}
		}
	}
}
int main()
{
	int adjvex_num,edge_num,i,a,b,delete_num;
	scanf("%d%d",&adjvex_num,&edge_num);
	for(i=0;i<edge_num;++i)
	{
		scanf("%d%d",&a,&b);
		G[a].head=insert(G[a].head,b);
		G[b].head=insert(G[b].head,a);
	}
	scanf("%d",&delete_num);
	dfs(0,-1);
	for(i=0;i<adjvex_num;++i)
	flage[i]=0;
	printf("\n");
	bfs(-1);
	for(i=0;i<adjvex_num;++i)
	flage[i]=0;
	printf("\n");
	dfs(0,delete_num);
	for(i=0;i<adjvex_num;++i)
	flage[i]=0;
	printf("\n");
	bfs(delete_num);
	return 0;
}

