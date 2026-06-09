#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct edge{
	int adjvex;
	struct edge *next;
}Elink;
typedef struct ver{
	Elink *link;
}Vlink;
Vlink g[120];
void insert(int a,int b){
	Elink *p,*q,*r;
	int min;
	p=(Elink *)malloc(sizeof(Elink));
	p->adjvex=b;
	p->next=NULL;
	if(g[a].link==NULL) g[a].link=p;
	else{
		for(r=g[a].link;r->next!=NULL;r=r->next){
			if(p->adjvex<r->adjvex){
				min=p->adjvex;
				p->adjvex=r->adjvex;
				r->adjvex=min;
			}
		}
		if(p->adjvex<r->adjvex){
				min=p->adjvex;
				p->adjvex=r->adjvex;
				r->adjvex=min;
			}
		r->next=p;
	}
	q=(Elink *)malloc(sizeof(Elink));
	q->adjvex=a;
	q->next=NULL;
	if(g[b].link==NULL) g[b].link=q;
	else{
		for(r=g[b].link;r->next!=NULL;r=r->next){
			if(q->adjvex<r->adjvex){
				min=q->adjvex;
				q->adjvex=r->adjvex;
				r->adjvex=min;
			}
		}
		if(q->adjvex<r->adjvex){
				min=q->adjvex;
				q->adjvex=r->adjvex;
				r->adjvex=min;
			}
		r->next=q;
	}
}
void DFS(int v,int visit[]){
	int i;
	Elink *p;
	visit[v]=1;
	printf("%d ",v);
	for(p=g[v].link;p!=NULL;p=p->next)
	if(!visit[p->adjvex]) DFS(p->adjvex,visit);
}
void BFS(int v,int visit[],int queue[]){
	Elink *p;
	int len1=0,len2=0;
	visit[v]=1;
	queue[len1++]=v;
	while(len1>len2){
		v=queue[len2++];
		printf("%d ",v);
		for(p=g[v].link;p!=NULL;p=p->next)
		if(!visit[p->adjvex]){
			queue[len1++]=p->adjvex;
			visit[p->adjvex]=1; 
		} 
	}
}
void ini(int a[],int n){
	int i;
	for(i=0;i<n;i++)
	a[i]=0;
}
int main()
{
	int i,v1,v2,n,m,visit[120],queue[120],flag;
	scanf("%d %d",&n,&m);
	for(i=0;i<m;i++){
		scanf("%d %d",&v1,&v2);
		insert(v1,v2);
		visit[i]=0;
	}
	scanf("%d",&flag);
	ini(visit,n);
	ini(queue,n);
	DFS(0,visit);
	printf("\n");
	ini(visit,n);
	BFS(0,visit,queue);
	printf("\n");
	ini(visit,n);
	ini(queue,n);
	visit[flag]=1; 
	DFS(0,visit);
	printf("\n");
	ini(visit,n);
	visit[flag]=1;
	queue[flag]=1;
	BFS(0,visit,queue);
	return 0;
} 

