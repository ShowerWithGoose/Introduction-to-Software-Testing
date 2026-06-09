#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct ELink {
	int wei;
	struct ELink * next;
};
typedef struct VLink {
	struct ELink * link;
};
struct VLink G[200];
int san;
int all[105][105]= {0};
int visit[200]= {0};
void DFS(struct VLink G[ ], int v) {
	struct ELink *p;
//访问某顶点
	printf("%d ",v-1);
	visit[v] = 1;
	for(p = G[v].link; p !=NULL; p=p->next)
		if(!visit[p->wei] ) DFS(G, p->wei);
}
void travelDFS(struct VLink G[ ], int n) {
	int i;
	for(i=1; i<=n; i++) visit[i] = 0 ;
	for(i=1; i<=n; i++) if(!visit[i] &&i!=san) DFS(G, i);
}
void travelDFSS(struct VLink G[ ], int n) {
	int i;
	for(i=1; i<=n; i++) visit[i]=0 ;
	for(i=1; i<=n; i++) if(!visit[i]) DFS(G, i);
}

int Q[200]= {0};
int qian=0,hou=0;
void enQueue(int Q[],int a) {
	Q[hou++]=a;
}
int deQueue(int Q[]) {
	int x=Q[qian];
	qian++;
	return x;
}
int emptyQ(int Q[]) {
	if(qian!=hou) return 0;
	else return 1;
}
void BFS(struct VLink G[ ], int v) {
	struct ELink *p;
	printf("%d ",v-1);//访问当前顶点
	visit[v]=1; //标识某顶点被访问过
	enQueue(Q, v);
	while(!emptyQ(Q)) {
		v=deQueue(Q); //取出队头元素
		p=G[v].link; //获取该顶点第一个邻接顶点
		for(; p != NULL ; p = p->next ) //访问该顶点下的每个邻接顶点
			if(!visit[p->wei] ) {
				printf("%d ",p->wei-1);
				//访问当前顶点  VISIT(G, p->wei);
				visit[p->wei]=1; //标识某顶点被访问过
				enQueue(Q, p->wei);
			}
	}
}
void travelBFS(struct VLink G[ ], int n) {
	int i;
	for(i=1; i<=n; i++) visit[i] = 0 ;
	for(i=1; i<=n; i++) if( !visit[i]&&i!=san ) BFS(G,i);
}
void travelBFSS(struct VLink G[ ], int n) {
	int i;
	for(i=1; i<=n; i++) visit[i] = 0 ;
	for(i=1; i<=n; i++) if( !visit[i]) BFS(G,i);
}
struct ELink * insert(struct ELink *head, int a) {
	struct ELink *q,*p;
	q =(struct ELink *)malloc(sizeof(struct ELink));
	q->wei=a;
	q->next = NULL;
	if(head == NULL) {
		head=q;
		return head;
	}
	for(p=head; p->next != NULL; p=p->next);
	p->next = q;
	return head;
}

void delect(struct ELink *p,int i,int a) {
	struct ELink * q = NULL;
	while(p!=NULL) {
		if(p->wei==a&&p->next!=NULL) {
			if(q==NULL) G[i].link=G[i].link->next; 
			else q->next=p->next;
			return ;
		} else if(p->wei==a&&p->next==NULL) {
			if(q!=NULL) q->next=NULL;
			else p=NULL;
			return ;
		}
		q=p;
		p=p->next;
	}
}

void put(int a) {
	printf("%d: ",a);
	struct ELink *p=G[a].link;
	while(p!=NULL) {
		printf("%d ",p->wei);
		p=p->next;
	}
	printf("\n");
}
int main() {
	int n,e;
	scanf("%d%d",&n,&e);
	int i,x,y;
	for(i=1; i<=n; i++) {
		G[i].link=NULL;
	}
	i=1;
	for(i=1; i<=e; i++) {
		scanf("%d%d",&x,&y);
		x++;
		y++;
		all[x][y]=1;
		all[y][x]=1;
	}
	int j;
	for(i=1; i<=n; i++) {
		for(j=1; j<=n; j++) {
          if(all[i][j])
         G[i].link=insert(G[i].link,j);
		}
	}
	scanf("%d",&san);
	san++;
	travelDFSS(G,n);
	printf("\n");
	travelBFSS(G,n);
	printf("\n");
	for(i=1; i<=n; i++) {
		if(i!=san) {
		delect(G[i].link,i,san);
		}
		else G[i].link=NULL;
	}
//	for(j=1; j<=n; j++) put(j);
	travelDFS(G,n);
	printf("\n");
	travelBFS(G,n);
	return 0;
}

