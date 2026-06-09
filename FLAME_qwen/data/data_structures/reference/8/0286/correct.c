#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct edge {
	int data;
	struct edge *next;
} Edge;
typedef struct node {
	int data;
	struct edge *link;
} Node;
Node G[105];
int visit[105];
void DFS(Node root) {
	visit[root.data]=1;
	printf("%d ",root.data);
	Edge *p;
	p=root.link;
	while(p!=NULL) {
		if(visit[p->data]==0) {
			DFS(G[p->data]);
		}
		p=p->next;
	}
	return ;
}
Node queue[105];
int front,rear;
void BFS() {
	Node temp;
	Edge *q;
	int front=0,rear=0,trear;
	queue[0]=G[0]; 
	while(front<=rear) {
		trear=rear;
		while(front<=trear) {
			temp=queue[front];
			if(!visit[temp.data]){
				printf("%d ",temp.data);
				visit[temp.data]=1;
				q=G[temp.data].link;
				while(q!=NULL){
					if(!visit[q->data])
					queue[++rear]=G[q->data];
					q=q->next;
				}
			}
			front++;
		}
	}
}
int main() {
	int Nnode,Nedge;
	int start,end;
	int dele;
	scanf("%d%d",&Nnode,&Nedge);
	for(int i=0; i<105; i++) {
		G[i].data=-1;
		G[i].link=NULL;
	}
	while(Nedge) {
		scanf("%d%d",&start,&end);
		Edge *p,*r;
		if(G[start].data==-1) {
			G[start].data=start;
		}
		if(G[end].data==-1) {
			G[end].data=end;
		}
		p=G[start].link;
		if(!p) {
			p=(Edge *)malloc(sizeof(Edge));
			p->data=end;
			p->next=NULL;
			G[start].link=p;
		} else {
			r=(Edge *)malloc(sizeof(Edge));
			r->data=end;
			r->next=NULL;
			if(p->data>end) {
				G[start].link=r;
				r->next=p;
			} else {
				while(p->next!=NULL&&p->next->data<end) {
					p=p->next;
				}
				if(p->next!=NULL) {
					r->next=p->next;
				}
				p->next=r;
			}
		}
		p=G[end].link;
		if(!p) {
			p=(Edge *)malloc(sizeof(Edge));
			p->data=start;
			p->next=NULL;
			G[end].link=p;
		} else {
			r=(Edge *)malloc(sizeof(Edge));
			r->data=start;
			r->next=NULL;
			if(p->data>start) {
				G[end].link=r;
				r->next=p;
			} else {
				while(p->next!=NULL&&p->next->data<start) {
					p=p->next;
				}
				if(p->next!=NULL) {
					r->next=p->next;
				}
				p->next=r;
			}
		}
		Nedge--;
	}
	DFS(G[0]);
	memset(visit,0,sizeof(visit));
	printf("\n");
	BFS();
	memset(visit,0,sizeof(visit));
	printf("\n");
	scanf("%d",&dele);
	visit[dele]=1;
	DFS(G[0]);
	memset(visit,0,sizeof(visit));
	printf("\n");
	visit[dele]=1;
	BFS();
	memset(visit,0,sizeof(visit));
	printf("\n");
}

