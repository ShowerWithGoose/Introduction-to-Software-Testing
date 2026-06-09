#include<stdio.h>
#include<stdlib.h>
#define MAX 100000
typedef struct node
{
	int adjvex;
	int weight;
	struct node* next;
}elink;
typedef struct dio
{
	int vertex;
	elink *link;
}vlink;//存顶点 
vlink g[10000];
int visited[10000];
int que[10000];
int front=0;int rear =-1;
int nextadj(vlink g[],int v)
{
	elink*p=g[v].link;
	int tar=100000;
	if(p==NULL)return -1;
	else 
	{
		while(p!=NULL)
		{
			if(p->adjvex<tar&&visited[p->adjvex]==0)tar=p->adjvex;
			p=p->next;
		}
		if(tar==MAX)return -1;
		else return tar;
	}
}
//再给定了起始节点不是他的时候，只要让其他没有点到这里就相当于删除了 
 void delver(vlink g[],int n,int item)//删除指定条件的节点 
 {
 	int i,k;
 	elink*p,*q,*r;
    k=item;
	 for(i=0;i<n;i++)
	 {
	 	p=g[i].link;
	 	while(p!=NULL)
	 	{
	 		if(p->adjvex==k)
	 		{
	 			if(g[i].link ==p)g[i].link=p->next;
	 			else q->next=p->next;//用q存前面的，会比直接p->next->next 方便不少
				 r=p;
				 p=p->next;
				 free(r); 
			 }
			 else 
			 {
			 	q=p;
			 	p=p->next;//假如第一个不是，跳转到这里，用q存主现在的 
			 }
		 }
	 }
 }
void visit(int v)
{
	printf("%d ",g[v].vertex);
}
void adjlist(vlink g[],int n, int e)//创建图的邻接链表储存 
{
	int k, vi,vj,weight;
	elink*p,*q;
	for(k=0;k<n;k++)//这里不需要存任何东西 
	{
		g[k].vertex =k;
		g[k].link=NULL;
	}
	for(k=0;k<e;k++){
	
//	scanf("%d%d%d",&vi,&vj,&weight);
scanf("%d%d",&vi,&vj);
	p=(elink*)malloc(sizeof(elink));
	p->adjvex=vj;//这个是按照图中标号从1开始的恶，假如想要从0开始则不用减一 
//	p->weight=weight;
	p->next=NULL;
	if(g[vi].link==NULL)g[vi].link=p;//只要在刚开始为NULL的时候才要开用开始的指针 
	else {
	q=g[vi].link ;
	while(q->next!=NULL)q=q->next;
	q->next=p;}
	int temp=vi;
	vi=vj;
	vj=temp;
		p=(elink*)malloc(sizeof(elink));
	p->adjvex=vj;//这个是按照图中标号从1开始的恶，假如想要从0开始则不用减一 
//	p->weight=weight;
	p->next=NULL;
	if(g[vi].link==NULL)g[vi].link=p;//只要在刚开始为NULL的时候才要开用开始的指针 
	else {
	q=g[vi].link ;
	while(q->next!=NULL)q=q->next;
	q->next=p;}
	}
 } 
 void dfs(vlink g[],int v)//深搜 
 {
 	int w;
 	visit(v);
 	visited[v]=1;
 	w=nextadj(g,v);
 	while(w!=-1)
 	{
 		if(visited[w]==0)dfs(g,w);
 		w=nextadj(g,v);
	 }
 }
 void travel_dfs(vlink g[],int n)
 {
 	int i;
 	for(i=0;i<n;i++)visited[i]=0;
    dfs(g,0);
 }
 void bfs(vlink g[],int v)
 {
 	int w;
 	visit(v);
 	visited[v]=1;
 	que[++rear]=v;
 	while(front<=rear)
 	{
 		v=que[front++];
 		w=nextadj(g,v);
 		while(w!=-1)
 		{
 			if(visited[w]==0)
 			{
 				visit(w);
 				que[++rear]=w;
 				visited[w]=1;
			 }
			 w=nextadj(g,v);
		 }
 		
	 }
 	
 }
 void travel_bfs(vlink g[],int n)//定义是对几个进行遍历 
 {
 	int i;
 	for(i=0;i<n;i++)visited[i]=0;
    bfs(g,0);
 }
 int main()
 {
 	int n,e;
 	scanf("%d%d",&n,&e);
 	adjlist(g,n,e);
 	int todo;
 	scanf("%d",&todo);
 	travel_dfs(g,n);
 	printf("\n");
 	travel_bfs(g,n);
 	printf("\n");
 	delver(g,n,todo);
 	travel_dfs(g,n);
 	printf("\n");
 	travel_bfs(g,n);
 	printf("\n");
 	return 0;
 	
 }



