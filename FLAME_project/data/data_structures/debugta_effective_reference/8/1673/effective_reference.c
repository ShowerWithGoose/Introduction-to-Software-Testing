#include<stdio.h>
#include<stdlib.h>
typedef struct  edge {
	int  adj;
	struct edge  *next;
} Elink;
typedef struct ver {
	Elink *link;
} Vlink;
int visit[512]= {0};
Vlink  G[512];
Elink *insert(Elink*head,int avex) {
	Elink *p,*e,*q=NULL;
	e=(Elink*)malloc(sizeof(Elink));
	e->adj=avex;
	e->next=NULL;
	if(head==NULL) {
		head =e;
		return head;
	}
	for(p=head; p != NULL && avex > p->adj;  q = p, p = p->next);
	if( p == head) {
		e->next = p;
		return e;
	} else {
		q->next = e;
		e->next = p;
		return head;
	}
}
Elink *Delete(Elink*head,int i) {
	Elink *p,*q;
	for(p=head; p->adj!=i; q=p,p=p->next);
	if(p==head) return p->next;
	else {
		q->next=p->next;
		return head;
	}
}
void DFS(int v);
void BFS(int v);
int main() {
	int n,m;
	int a,b,k;
	int s[100][100]={0};
	scanf("%d%d",&n,&m);
	for(int i=0; i<m; i++) {
		scanf("%d %d",&a,&b);
		s[a][b]=1;
		G[a].link=insert(G[a].link,b);
		G[b].link=insert(G[b].link,a);
	}
	for(int i=0; i<n; i++) visit[i]=0;
	DFS(0);
	printf("\n");
	for(int i=0; i<n; i++) visit[i]=0;
	BFS(0);
	printf("\n");
	scanf("%d",&k);
	for(int i=0; i<n; i++) {
		if(s[k][i]||s[i][k]) {
			G[i].link=Delete(G[i].link,k);
		}
	}
	for(int i=0; i<n; i++) visit[i]=0;
	for(int i=0; i<n; i++) {
		if(!visit[i]&&i!=k) DFS(i);
	}
	printf("\n");
	for(int i=0; i<n; i++) visit[i]=0;
	BFS(0);
}
void DFS(int i) {
	Elink *p;
	printf("%d ",i);
	visit[i]=1;
	for(p=G[i].link; p!=NULL; p=p->next) {
		if(!visit[p->adj]) {
			DFS(p->adj);
		}
	}
}
void BFS(int i) {
	Elink *p;
	int l=0;
	int line[520]= {0};
	for(int i=0; i<520; i++) {
		line[i]=0;
	}
	visit[i]=1;
	line[l]=i;
	l++;
	int front=0;
	while(front<l) {
		printf("%d ",line[front]);
		for(p=G[line[front]].link; p!=NULL; p=p->next) {
			if(!visit[p->adj]) {
				visit[p->adj]=1;
				line[l]=p->adj;
				l++;
			}
		}
		front++;
	}
}

