#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAXPOINT 105
typedef struct  node1 {
	int  adj;
	struct node1 *next;
} Elink;
typedef struct node2 {
	Elink *link;
} Vlink;
Vlink G[MAXPOINT];
int A[MAXPOINT][MAXPOINT];
int visit[MAXPOINT]= {0};
int que[MAXPOINT],front,rear,count;

void DFS(int v) {
	Elink  *p;
	visit[v] = 1;
	printf("%d ",v);
	for(p = G[v].link; p !=NULL;  p=p->next) {
		if(visit[p->adj]==0) DFS(p->adj);
	}
}
void  travelDFS(int n,int x) {
	int i;
	for(i=0; i<n; i++) visit[i] = 0 ;
	for(i=0; i<n; i++)
		if((visit[i]==0)&&(i!=x)) DFS(i);
}

int isempty() { //·Ç¿Õ·µ»Ø0
	return (count==0)?1:0;
}
int inqueue(int v) {
	rear++;
	que[rear]=v;
	count++;
}
int deQueue() {
	int e=que[front];
	front++;
	count--;
	return e;
}
void BFS(int v) {
	Elink  *p;
	visit[v] = 1;
	inqueue(v);
	while(isempty()==0) {
		v = deQueue();
		printf("%d ",v);
		for(p=G[v].link; p!=NULL; p=p->next )
			if(visit[p->adj]==0 ) {
				visit[p->adj] = 1;
				inqueue(p->adj);
			}
	}

}
void  travelBFS(int n,int x) {
	int i;
	memset(que,0,sizeof(que));
	front=0;
	rear=-1;
	count=0;
	for(i=0; i<n; i++) visit[i] = 0 ;
	for(i=0; i<n; i++)
		if((visit[i]==0)&&(i!=x)) BFS(i);
}

void addedge(int x1,int x2) {
	Elink *p,*q;
	p=(Elink*)malloc(sizeof(Elink));
	p->adj=x2;
	p->next=NULL;
	if(G[x1].link==NULL) G[x1].link=p;
	else {
		q=G[x1].link;
		while(q->next!=NULL) q=q->next;
		q->next=p;
	}
}

int main() {
	int n,e,x=-1,x1,x2,i,j;
	scanf("%d%d",&n,&e);
	for(i=0; i<e; i++) {
		scanf("%d%d",&x1,&x2);
		A[x1][x2]=1;
		A[x2][x1]=1;
	}
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if(A[i][j]==1) addedge(i,j);
		}
	}
	travelDFS(n,x);
	printf("\n");
	travelBFS(n,x);
	printf("\n");
	scanf("%d",&x);
	
	memset(G,0,sizeof(G));
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if((i==x)||(j==x)) A[i][j]=0;
			if(A[i][j]==1) addedge(i,j);
		}
	}
	travelDFS(n,x);
	printf("\n");
	travelBFS(n,x);
	return 0;
}

