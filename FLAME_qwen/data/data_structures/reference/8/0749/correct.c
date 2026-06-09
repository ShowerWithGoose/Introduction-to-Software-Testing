#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct edge{
	int index;
	struct edge *next;
}Elink;
typedef struct ver{
	int index;
	Elink *link;
}Vlink;
Vlink G[105];
int gn,en;
int visit[105];
int d=-1;
Elink *insertEdge(Elink *head,int v){
	Elink *p=head,*e=NULL,*q=head;
	e=(Elink *)malloc(sizeof(Elink));
	e->index=v;
	e->next=NULL;
	if(head==NULL){
		head=e;
		return head;
	}
	else if(head->index>v){
		e->next=head;
		return e;
	}
	for(p=head;p!=NULL&&p->index<v;p=p->next)
	q=p;
	e->next=q->next;
	q->next=e;
	return head;
}
void createGraph(){
	int i,v1,v2;
	for(i=0;i<gn;i++)
		G[i].link=NULL;
	for(i=0;i<en;i++){
		scanf("%d%d",&v1,&v2);
		G[v1].link=insertEdge(G[v1].link,v2);
		G[v2].link=insertEdge(G[v2].link,v1);
	}
}
void DFS(int v){
	Elink *p;
	visit[v]=1;
	printf("%d ",v);
	for(p=G[v].link;p!=NULL;p=p->next)
		if(!visit[p->index])
			DFS(p->index); 
}
void travelDFS(){
	for(int i=0;i<gn;i++)
		visit[i]=0;
	if(d!=-1) visit[d]=1;
	DFS(0);
	//for(int i=0;i<gn;i++)
	//	if(!visit[i]) DFS(i);
}
int front=0,rear=-1;
int queue[205];
int Empty(){
	if(front==rear+1)
		return 1;
	return 0;
}
int deQueue(){
	return queue[front++];
}
void enQueue(int v){
	queue[++rear]=v;
}
void BFS(int v){
	Elink *p;
	visit[v]=1;//ÒÑÈë¶Ó 
	enQueue(v);
	while(!Empty()){
		v=deQueue();
		printf("%d ",v);
		for(p=G[v].link;p!=NULL;p=p->next){
			if(!visit[p->index]){
				visit[p->index]=1;
				enQueue(p->index); 
			}
		}
	}
}
void travelBFS(){
	for(int i=0;i<gn;i++)
		visit[i]=0;
	if(d!=-1) visit[d]=1;
	BFS(0);
	//for(int i=0;i<gn;i++)
	//	if(!visit[i]) BFS(i);
}
Elink *deleteL(int v,int index){
	Elink *p=G[index].link,*q=NULL;
	if(p->index==v)
		return p->next; 
	while(p!=NULL){
		if(p->index==v){
			q->next=p->next;
			free(p);
			return G[index].link;
		}
		else{
			q=p;
			p=p->next;
		}
	}
	return G[index].link;
}
void deleteVex(int v){
	Elink *head=G[v].link,*p;
	for(p=head;p!=NULL;p=p->next)
		G[p->index].link=deleteL(v,p->index);
	G[v].link=NULL;
}
int main()
{
	scanf("%d%d",&gn,&en);
	createGraph();
	/*Elink *p=G[1].link;
	for(;p!=NULL;p=p->next)
	printf("%d ",p->index);*/
	travelDFS();printf("\n");
	travelBFS();printf("\n");
	scanf("%d",&d);
	deleteVex(d);
	travelDFS();printf("\n");
	travelBFS();
	return 0;
} 

