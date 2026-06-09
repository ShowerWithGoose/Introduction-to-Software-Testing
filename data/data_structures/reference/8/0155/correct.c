#include<stdio.h>
#include<stdlib.h>
typedef struct edge{
	int adjvex;
	struct edge *next;
}elink;
typedef struct ver{
	elink *link;
}vlink;
int visited[100]={0};
void dfs(vlink g[],int v){
	elink *p;
	visited[v]=1;
	printf("%d ",v);
	for(p=g[v].link;p!=NULL;p=p->next){
		if(!visited[p->adjvex]){
			dfs(g,p->adjvex);
		}
	}
}
void traveldfs(vlink g[],int n,int m){
	int i;
	for(i=0;i<n;i++){
		visited[i]=0;
	}
	for(i=0;i<n;i++){
		if(i==m){
			continue;
		}
		if(!visited[i]){
			dfs(g,i);
		}
	}
}
void bfs(vlink g[],int v,int dui[],int font,int rear){
	elink *p;
	printf("%d ",v);
	visited[v]=1;
	dui[rear]=v;
	rear++;
	while(rear-font>0){
		v=dui[font];
		font++;
		p=g[v].link;
		for(;p!=NULL;p=p->next){
			if(!visited[p->adjvex]){
				printf("%d ",p->adjvex);
			    visited[p->adjvex]=1;
			    dui[rear]=p->adjvex;
			    rear++;
			}
		}
	}
}
void travelbfs(vlink g[],int n,int m){
	int i;
	int dui[100],font=0,rear=0;
	for(i=0;i<n;i++){
		visited[i]=0;
	}
	for(i=0;i<n;i++){
		if(i==m){
			continue;
		}
		if(!visited[i]){
			bfs(g,i,dui,font,rear);
		}
	}
}
int main(){
	int n,nedge,i,v1,v2,m;
	vlink *graph;
	elink *p,*q,*r;
	scanf("%d %d",&n,&nedge);
	graph=(vlink*)malloc(n*sizeof(vlink));
	for(i=0;i<n;i++){
		graph[i].link=NULL;
	}
	i=0;
	for(i;i<nedge;i++){
		scanf("%d %d",&v1,&v2);
		p=(elink*)malloc(sizeof(elink));
		p->adjvex=v2;
		p->next=NULL;
		q=graph[v1].link;
		r=NULL;
		for(q;q!=NULL;q=q->next){
			if(q->adjvex>v2){
				break;
			}
			r=q;
		}
		if(r==NULL){
			p->next=q;
			graph[v1].link=p;
		}else{
			p->next=q;
			r->next=p;
		}
		p=(elink*)malloc(sizeof(elink));
		p->adjvex=v1;
		p->next=NULL;
		q=graph[v2].link;
		r=NULL;
		for(q;q!=NULL;q=q->next){
			if(q->adjvex>v1){
				break;
			}
			r=q;
		}
		if(r==NULL){
			p->next=q;
			graph[v2].link=p;
		}else{
			p->next=q;
			r->next=p;
		}
	}
	scanf("%d",&m);
	traveldfs(graph,n,n+1);
	printf("\n");
	travelbfs(graph,n,n+1);
	printf("\n");
	for(i=0;i<n;i++){
		p=graph[i].link;
		r=p;
		for(;p!=NULL;p=p->next){
			if(p->adjvex==m){
				if(p==graph[i].link){
					graph[i].link=p->next;
				}else{
					r->next=p->next;
				}
			}r=p;
		}
	}
	traveldfs(graph,n,m);
	printf("\n");
	travelbfs(graph,n,m);
	printf("\n");
	return 0;
} 

