#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct edge{
	int num;
	struct edge *pNext;
}Elink;

typedef struct ver{
	int del;
	Elink *link;
}Vlink;

void DFS(Vlink *G,int v);
void BFS(Vlink *G,int v);
void change(Elink *head);

int visit[105],front=0,rear=0;
Vlink G[105];
int queue[105];
Elink *Insert(Elink *head,int v);

int main(){
	int v,e,v1,v2,i,delv;
	scanf("%d%d",&v,&e);
	for(i=0;i<e;i++){
		scanf("%d%d",&v1,&v2);
		G[v1].link=Insert(G[v1].link,v2);
		G[v2].link=Insert(G[v2].link,v1);
	}
	for(i=0;i<v;i++) change(G[i].link);
	scanf("%d",&delv);
	for(i=0;i<v;i++) DFS(G,i);
	printf("\n");
	memset(visit,0,sizeof(visit));
	for(i=0;i<v;i++) BFS(G,i);
	printf("\n");
	G[delv].del=1;
	memset(visit,0,sizeof(visit));
	for(i=0;i<v;i++) DFS(G,i);
	printf("\n");
	memset(visit,0,sizeof(visit));
	for(i=0;i<v;i++) BFS(G,i);
	return 0;
}

Elink *Insert(Elink *head,int v){
	Elink *e=(Elink *)malloc(sizeof(Elink));
	e->num=v;
	e->pNext=NULL;
	if(!head) return e;
	else{
		Elink *p=head;
		while(p->pNext) p=p->pNext;
		p->pNext=e;
		return head;
	}
}

void change(Elink *head){
	Elink *p,*n;
	for(p=head;p!=NULL;p=p->pNext){
		for(n=p->pNext;n!=NULL;n=n->pNext){
			if(p->num>n->num){
				int temp=p->num;
				p->num=n->num;
				n->num=temp;
			}
		}
	}
}

void DFS(Vlink *G,int v){
	if(!visit[v]&&!G[v].del){
		printf("%d ",v);
		visit[v]=1;
		Elink *p=G[v].link;
		while(p){
			DFS(G,p->num);
			p=p->pNext;
		}
	}
}

void BFS(Vlink *G,int v){
	if(!visit[v]&&!G[v].del){
		visit[v]=1;
		queue[rear]=v;
		rear=(rear+1)%105;
		while(front!=rear){
			int n=queue[front];
			printf("%d ",n);
			visit[n]=1;
			front=(front+1)%105;
			Elink *p;
			for(p=G[n].link;p!=NULL;p=p->pNext){
				if(!visit[p->num]&&!G[p->num].del){
					visit[p->num]=1;
					queue[rear]=p->num;
					rear=(rear+1)%105;
				}
			}
		}
	}
}

