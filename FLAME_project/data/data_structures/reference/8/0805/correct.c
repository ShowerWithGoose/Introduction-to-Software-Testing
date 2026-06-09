#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct edge
{
	int adjvex;
	int weight;
	struct edge *next;
 } Elink;
 Elink *p,*q,*r;
 int n,e;
 typedef struct ver
 {
 	int vertex;
 	Elink *link;
 } Vlink;
 Vlink G[101];
 int visited[101];
 int w=0;
 void DFS(Vlink G[],int v)
 {
 	Elink *p;
 	if(visited[v]!=1)
 	printf("%d ",G[v].vertex);
 	visited[v]=1;
  	for(p = G[v].link;p!=NULL; p=p->next)
    if(visited[p->adjvex]!=1)
     DFS(G,p->adjvex);
 }
 void T_DFS(Vlink G[],int visited[],int n)
 {
 	int i;
 	for (i=0;i<n;i++)
 	DFS(G,i);
 }
 int Q[100];
 int front=-1;
 int rear=-1;
 void BFS(Vlink  G[], int v)
{
    Elink  *p;
     printf("%d ",G[v].vertex); //访问当前顶点
     visited[v] = 1; //标识某顶点被访问过
    Q[++rear]=v;
    while(front!=rear){
         v =Q[++front];  //取出队头元素
         p = G[v].link;  //获取该顶点第一个邻接顶点
         for(; p != NULL ; p = p->next ) //访问该顶点下的每个邻接顶点
             if( !visited[p->adjvex] ) {
                    printf("%d ",p->adjvex); //访问当前顶点
                    visited[p->adjvex] = 1; //标识某顶点被访问过
                    	Q[++rear]=p->adjvex;
           }
     }
}
 void T_BFS(Vlink G[],int visited[],int n)
 {
 	int i;
 	for (i=0;i<n;i++)
 	visited[i]=0;
 	BFS(G,0);
 }
 
 void ADJLIST (Vlink G[],int n,int e)
 {
 	int i,j,vi,vj,temp;
 	int a[101],b[101];
 	for(i=0;i<e;i++)
 	{
 		scanf("%d %d",&a[i],&b[i]);
 		if (a[i]>b[i])
 		{
 			temp=a[i];
 			a[i]=b[i];
 			b[i]=temp;
		 }
	 }
	 for (i=0;i<e-1;i++)
	 {
	 	for (j=0;j<e-i-1;j++)
	 	{
	 		if (a[j]>a[j+1])
	 		{
	 			temp=a[j];
	 			a[j]=a[j+1];
	 			a[j+1]=temp;
	 			temp=b[j];
	 			b[j]=b[j+1];
	 			b[j+1]=temp;
			 }
		 }
	 }
	 for (i=0;i<e-1;i++)
	 {
	 	for (j=0;j<e-i-1;j++)
	 	{
	 		if (b[j]>b[j+1]&&a[j]==a[j+1])
	 		{
	 			temp=b[j];
	 			b[j]=b[j+1];
	 			b[j+1]=temp;
			 }
		 }
	 }
	 
 	for (i=0;i<n;i++)
 	{
 		G[i].vertex=i;
 		G[i].link=NULL;
	 }

	 for (i=0;i<e;i++)
	 {
	 	p=(Elink*)malloc(sizeof(Elink));
	 	p->adjvex=b[i];
	 	p->next=NULL;
	 	if (!G[a[i]].link)
	 	G[a[i]].link=p;
	 	else 
	 	{
	 		q=G[a[i]].link;
	 		while(q->next)
	 		q=q->next;
	 		q->next=p;
	 }
	 
	 	p=(Elink*)malloc(sizeof(Elink));
	 	p->adjvex=a[i];
	 	p->next=NULL;
	 	if (!G[b[i]].link)
	 	G[b[i]].link=p;
	 	else 
	 	{
	 		q=G[b[i]].link;
	 		while(q->next)
	 		q=q->next;
	 		q->next=p;
	 }
	 
	 
 }
}
 void DELVER(Vlink G[],int n,int item)
 {
 	visited[item]=1;
 	int i,k=-1;
 	for (i=0;i<n;i++)
 	if (G[i].vertex==item)
 	{
 		k=i;
 		break;
	 }
	 
	 
	 if (k!=-1)//若找到那个节点 
	 {
	 	p=G[k].link;
		 while(p!=NULL)
		 {
		 	r=p;
		 	p=p->next;
		 	free(r);
		 }//FREE掉那个节点 
		 G[k].link=NULL;
		 
		 for (i=0;i<n;i++)
		 {
			if (i==k)
			continue;
			p=G[i].link;
			 	while (p!=NULL)
		 	{
		 		if (p->adjvex==k)
		 		{
		 			if (G[i].link==p)
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
 int main()
 {
 	int i,x;
 	scanf("%d %d",&n,&e);
 	ADJLIST(G,n,e);
 	scanf("%d",&x);
 	for (i=0;i<n;i++)
 	visited[i]=0;
	T_DFS(G,visited,n);
	printf("\n");
	T_BFS(G,visited,n);
	printf("\n");
	for (i=0;i<n;i++)
 	visited[i]=0;
	DELVER(G,n,x);
	T_DFS(G,visited,n);
	printf("\n");
	T_BFS(G,visited,n);
	printf("\n");
 }

