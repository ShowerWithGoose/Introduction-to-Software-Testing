#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

int flag,dele;

struct ver {
	struct edge *link;
};

struct edge {
	int adj;
	struct edge *next;
};

struct ver v[100];



void insert(int a1,int a2) {
	struct edge *p,*q;
	p=(struct edge*)malloc(sizeof(struct edge));
	p->adj=a2;
	p->next=NULL;
	if(v[a1].link==NULL) {
		v[a1].link=p;
		return;
	}
	if(p->adj<v[a1].link->adj) {

		p->next=v[a1].link;
		v[a1].link=p;

		return;
	}
	for(q=v[a1].link; q->next!=NULL; q=q->next) {
		if(p->adj>q->adj&&p->adj<q->next->adj)
			break;
	}
	p->next=q->next;
	q->next=p;
}

void del(int a,int q) {
	struct edge *p,*t;
	if(q==a) {
		v[q].link=NULL;
	} else {
		p=v[q].link;
		if(p->adj==a) {
			v[q].link=p->next;
			return;
		}
		for(; p->next!=NULL; t=p,p=p->next) {
			if(p->adj==a) {
				t->next=p->next;
				return;
			}
		}
	}
}

int visit[100]= {0};


void dfs(int u) {
	struct edge *p;
	visit[u]=1;
	printf("%d ",u);
	for(p=v[u].link; p!=NULL; p=p->next) {
		if(!visit[p->adj]) {
			dfs(p->adj);
		}
	}

}


void traveld(int n) {
	int i;
	for(i=0; i<n; i++) {
		visit[i]=0;
	}
	if(flag==1)
		visit[dele]=1;
	for(i=0; i<n; i++) {
		if(!visit[i])
			dfs(i);
	}
}



int queue[100],rear=99,front=0,count=0;

void enqueue(int item) {
	rear=(rear+1)%100;
	queue[rear]=item;
	count++;
}

int  dequeue() {
	int e;
	e=queue[front];
	count--;
	front=(front+1)%100;
	return e;
}

int isempty() {
	return count==0;
}

void bfs(int u) {
	struct edge *p;
	printf("%d ",u);
	visit[u]=1;

	enqueue(u);
	while(!isempty()) {
		u=dequeue();
		p=v[u].link;
		for(; p!=NULL; p=p->next) {
			if(!visit[p->adj]) {
				printf("%d ",p->adj);
				visit[p->adj]=1;
				enqueue(p->adj);
			}
		}
	}


}


void travelb(int n) {
	int i;
	for(i=0; i<n; i++) {
		visit[i]=0;
	}
	if(flag==1)
		visit[dele]=1;
	for(i=0; i<n; i++) {
		if(!visit[i])
			bfs(i);
	}
}


int main() {
	int  vnb,enb,e,u;



	scanf("%d%d",&vnb,&enb);

	for(int i=0; i<enb; i++) {
		scanf("%d%d",&u,&e);
		insert(u,e);
		insert(e,u);
	}

	//printf("%d",v[8].link->next->adj);

	scanf("%d",&dele);


	traveld(vnb);
	printf("\n");
	travelb(vnb);
	printf("\n");

	for(int i=0; i<vnb; i++) {
		del(dele,i);
	}
	flag=1;

	traveld(vnb);
	printf("\n");
	travelb(vnb);
	printf("\n");


	return 0;
}

