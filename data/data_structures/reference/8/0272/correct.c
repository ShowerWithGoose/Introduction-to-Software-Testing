#include <stdio.h>
#include <stdlib.h>
typedef struct edge{
	int adj;
	int wei;
	struct edge *next;
}Elink;//点 
typedef struct ver{
	Elink *link;
}Vlink;
Vlink G[110];
int visited[110]={0}; 
Elink *insertEdge(Elink*head,int avex)//在链表尾插入一个节点，head是点，avex是联结点 
{
	Elink *e,*p,*r;
	e=(Elink *)malloc(sizeof(Elink));//创建一个节点 
	e->adj=avex;//节点 
	e->wei=1;//权重 
	e->next=NULL;
	if(head==NULL){//头节点 
		head=(Elink *)malloc(sizeof(Elink));
		head->adj=-1;
		head->next=e;
		return head;
	}
	for(r=head,p=head->next;p!=NULL&&p->adj<e->adj;r=p,p=p->next);
		//printf("%d %d\n",r->adj,e->adj);
		e->next=p;
		r->next=e;
	return head;
}
int createGraph(Vlink graph[]) 
{
	int i;
	int point,len;
	scanf("%d%d",&point,&len);
	int tmp1,tmp2;
	for(i=0;i<len;i++)
	{
		scanf("%d%d",&tmp1,&tmp2);
		graph[tmp1].link=insertEdge(graph[tmp1].link,tmp2);
		graph[tmp2].link=insertEdge(graph[tmp2].link,tmp1);
	 } 
	 return point;
}
void DFS(Vlink G[],int v)//G是邻接树，v是某一个节点的序号 
{
	Elink *p;
	visited[v]=1;
	printf("%d ",v);
	for(p=G[v].link->next;p!=NULL;p=p->next)
	{
		if(!visited[p->adj])
		DFS(G,p->adj);
	 } 
} 
void traveldfs(Vlink G[],int n){//这是这个图，n是有多少个节点 
	int i;
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	for(i=0;i<n;i++)
	{
		if(!visited[i])
		DFS(G,i);
	}
}
void ptraveldfs(Vlink G[],int n,int del)
{
	int i;
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	visited[del]=1;
	for(i=0;i<n;i++)
	{
		if(!visited[i])
		DFS(G,i);
	}
}
void BFS(Vlink G[],int v)
{
	Elink *q;
	int p;
	visited[v]=1;
	int queue[100];//队，N为顶点数
	int front,rear;
	queue[0]=v; 
	front=-1;
	rear=0;
	while(front<rear)
	{
		p=queue[++front];
		printf("%d ",p);
		for(q=G[p].link->next;q!=NULL;q=q->next)
		{
			if(visited[q->adj]==0)
			{
				visited[q->adj]=1;
				queue[++rear]=q->adj ;
				//printf("q:%d\n",q->adj );
			}
		}
	}
	
}
void travelbfs(Vlink G[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			BFS(G,i);
		}
	}
}
void ptravelbfs(Vlink G[],int n,int del)
{
	int i;
	for(i=0;i<n;i++)
	{
		visited[i]=0;
	}
	visited[del]=1;
	for(i=0;i<n;i++)
	{
		if(visited[i]==0)
		{
			BFS(G,i);
		}
	}
}
int main()
{
	int num;
	num=createGraph(G);
	int i,del;
	scanf("%d",&del);
	traveldfs(G,num);
	putchar('\n');
	travelbfs(G,num);
	putchar('\n');
	visited[del]=1;
	Elink *p,*r;
	for(i=0;i<num;i++)
	{
		if(i==del)
		G[i].link->next=NULL;
		for(r=G[i].link,p=G[i].link->next;p!=NULL;r=p,p=p->next)
		{
			if(p->adj==del)
			{
				r->next=p->next;
		        free(p);
				break;
			}
		}
	 } 
	 ptraveldfs(G,num,del);
	 putchar('\n');
	 ptravelbfs(G,num,del);
	 putchar('\n');
	return 0;
}



