#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#define MaxV 105
int d;
typedef struct edge {
	int adjvex;
	struct edge *next;
} ELink;
typedef struct ver {
	ELink *link;
} VLink;
VLink G[MaxV],H[MaxV];//105个顶点作为初始结点
int g[MaxV][MaxV]= {0};
int front=0,rear=0,count=0;
int Q[105];

int  Visited[105]= {0}; //标识顶点是否被访问过，N为顶点数
void DFS(VLink G[ ], int v) {
	ELink *p;
	Visited[v] = 1; 	//标识某顶点被访问过
	printf("%d ",v);	//访问某顶点
	for(p = G[v].link; p!=NULL; p=p->next) {
		if(!Visited[p->adjvex]) {
			DFS(G, p->adjvex);
		}
	}
}
void  travelDFS(VLink G[ ], int n) {
	int i;
	for(i=0; i<n; i++) {
		Visited[i] = 0;
	}
	for(i=0; i<n; i++) {
		if(!Visited[i]) {
			DFS(G, i);
		}
	}
}
void  travelDFS2(VLink G[ ], int n) {
	int i;
	for(i=0; i<n; i++) {
		Visited[i] = 0;
	}
	Visited[d]=1;
	for(i=0; i<n; i++) {
		if(!Visited[i]) {
			DFS(G, i);
		}
	}
}
//在链表尾插入一个节点
ELink  *insertEdge(ELink *head, int avex) {
	ELink *e,*p;
	e =(ELink *)malloc(sizeof(ELink));
	e->adjvex= avex;
	e->next = NULL;
	if(head == NULL)  {
		head=e;
		return head;
	}
	for(p=head; p->next != NULL; p=p->next)
		;
	p->next = e;
	return head;
}

void enQueue(int Q[ ],int v) {
	rear = (rear+1) % 105;
	count++;
	Q[rear]=v;
}
int deQueue(int Q[ ]) {
	int v;
	v=Q[front+1];
	count--;
	front = (front+1) % 105;
	return v;
}
void BFS(VLink G[ ], int v) {
	ELink *p;
	printf("%d ",v);
	Visited[v] = 1; //标识某顶点被访问过
	enQueue(Q, v);         //入口的第一个顶点入队
	while(count!=0) {
		v = deQueue(Q);  //取出队头元素
		p = G[v].link;         //获取该顶点第一个邻接顶点
		for(; p != NULL ; p = p->next ) {//访问该顶点下的每个邻接顶点
			if(Visited[p->adjvex]==0) {
				printf("%d ",p->adjvex); //访问当前顶点
				Visited[p->adjvex] = 1; //标识某顶点被访问过
				enQueue(Q, p->adjvex); //邻接顶点依次分别入队
			}
		}			
	}
}
void travelBFS2(VLink G[ ], int n) {
	int i;
	front=0,rear=0,count=0;
	for(i=0; i<n; i++) {
		Visited[i] = 0 ;
	}
	Visited[d]=1;
	for(i=0; i<n; i++) {
		if(!Visited[i]) {
			BFS(G, i);
		}
	}
}
void travelBFS(VLink G[ ], int n) {
	int i;
	front=0,rear=0,count=0;
	for(i=0; i<n; i++) {
		Visited[i] = 0 ;
	}
	for(i=0; i<n; i++) {
		if(!Visited[i]) {
			BFS(G, i);
		}
	}
}
int main() {
	int n,e,i,j,x,y;
	ELink *p=NULL,*q=NULL;
	scanf("%d%d",&n,&e);
	for(i=0; i<e; i++) {
		scanf("%d%d",&x,&y);
		g[x][y]=1;
		g[y][x]=1;
	}
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			if(g[i][j]==1) {
				G[i].link=insertEdge(G[i].link, j);
			}
		}
	}
	scanf("%d",&d);//输入要删除的顶点编号
	travelDFS(G,n);
	printf("\n");
	travelBFS(G,n);
	printf("\n");

	for(i=0; i<n; i++) { //看每一个链表里是否有d
		q=NULL;
		for(p=G[i].link; p->next!=NULL; q=p,p=p->next) {
			if(p->adjvex==d) {
				if(q==NULL) { //说明紧挨着顶点的是要删除的
					G[i].link=p->next;
					free(p);
					break;//删除了这个链表里的d，退出这层循环
				} else {
					q->next=p->next;
					free(p);
					break;
				}
			}
		}
	}
//	int v,i;
//	for(i=1;i<=10;i++){
//		enQueue(Q,i);
//	}
//	while(count!=0){
//		v=deQueue(Q);
//		printf("%d\n",v);
//	}
	
	travelDFS2(G,n);
	printf("\n");
	travelBFS2(G,n);
	printf("\n");
	return 0;
}

