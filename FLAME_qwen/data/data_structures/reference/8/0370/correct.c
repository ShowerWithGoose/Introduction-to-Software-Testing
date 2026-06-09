#include<stdio.h>
#include<stdlib.h>
typedef struct edge{
	int end;
	struct edge *next;
}Elink;
typedef struct ver{
	Elink *link;
}Vlink;
Vlink G[10000];
Elink *insert(Elink *head, int num){
	Elink *e, *p, *q;
	e=(Elink*)malloc(sizeof(Elink));
	e->end=num,e->next=NULL;
	if(head==NULL){
		head=e;
		return head;
	}
	for(q=p=head;p!=NULL;q=p,p=p->next){
		if((e->end)<(head->end)){
			e->next=head;
			head=e;
			break;
		}
		else if((e->end)>(q->end)&&(e->end)<(p->end)){
			q->next=e;
			e->next=p;
			break;
		}
		else if(p->next==NULL&&(e->end)>(p->end)){
			p->next=e;
			break;
		}
	}
	return head;
}
int vis[150];
void dfs(Vlink G[],int v){
	Elink *p;
	vis[v]=1;
	printf("%d ",v);
	for(p=G[v].link;p!=NULL;p=p->next){
		if(!vis[p->end]){
			dfs(G,p->end);
		}
	}
	return;
}
void bfs(Vlink G[],int v){
	Elink *p;
	vis[v]=1;
	int q[200],fr=-1,re=-1;
	q[++re]=v;
	while(fr<re){
		v=q[++fr];
		printf("%d ",v);
		for(p=G[v].link;p!=NULL;p=p->next){
			if(!vis[p->end]){
				vis[p->end]=1;
				q[++re]=p->end;
			}
		}
	}
}
int main(){
	int i,e,m,n,v1,v2;
	scanf("%d%d",&e,&n);
	for(i=0;i<n;i++){
		G[i].link=NULL;
	}
	for(i=0;i<n;i++){
		scanf("%d%d",&v1,&v2);
		G[v1].link=insert(G[v1].link,v2);
		G[v2].link=insert(G[v2].link,v1);
	}
	scanf("%d",&m);
	for(i=0;i<e;i++){
		if(!vis[i]) dfs(G,i);
	}
	printf("\n");
	for(i=0;i<e;i++){
		vis[i]=0;
	}
	for(i=0;i<e;i++){
		if(!vis[i]) bfs(G,i);
	}
	printf("\n");
	for(i=0;i<e;i++){
		vis[i]=0;
	}
	vis[m]=1;	
	for(i=0;i<e;i++){
		if(!vis[i]) dfs(G,i);
	}
	printf("\n");
	for(i=0;i<e;i++){
		vis[i]=0;
	}
	vis[m]=1;
	for(i=0;i<e;i++){
		if(!vis[i]) bfs(G,i);
	}
	return 0;
}

