//采用邻接矩阵的方式存储图
#include<stdio.h>
#include<stdlib.h>
int visited[100]= {0};
int array[100][100]= {{0}};
typedef struct queue {
	int data;
	struct queue* next;
} queue;
queue* queue_head=NULL,*queue_rear=NULL;
void enqueue(int a) {
	queue* p=(queue*)malloc(sizeof(queue));
	p->data=a;
	p->next=NULL;
	if(queue_rear==NULL) {
		queue_rear=queue_head=p;
	} else {
		queue_rear->next=p;
		queue_rear=p;
	}
}
int outqueue() {
	queue *p;
	int a=-1;
	if(queue_head!=NULL) {
		p=queue_head;
		queue_head=queue_head->next;
		if(queue_head==NULL) {
			queue_rear=queue_head=NULL;
		}
		a=p->data;
		free(p);
	}
	return a;
}
void DFS(int start,int n) {
	printf("%d ",start);
	visited[start]=1;
	for(int i=0; i<n; i++) {
		if(array[start][i]&&visited[i]==0) {
			DFS(i,n);
		}
	}
}
void travelDFS(int start,int n,int del) {
	for(int i=0; i<n; i++) {
		visited[i]=0;
	}
	if(del>0) visited[del]=1;
	for(int i=0; i<n; i++) {
		if(visited[i]==0) {
			DFS(i,n);
		}
	}
}
void BFS(int start,int n) {
	int a;
	if(visited[start]==0) {
		enqueue(start);
		visited[start]=1;
	}
	while(queue_head!=NULL) {
		a=outqueue();
		printf("%d ",a);
		for(int i=0; i<n; i++) {
			if(array[a][i]&&!visited[i]) {
				enqueue(i);
				visited[i]=1;
			}
		}
	}

}
void travelBFS(int start,int n,int del) {
	queue_head=NULL;
	queue_rear=NULL;
	for(int i=0; i<n; i++) {
		visited[i]=0;
	}
	if(del>0) visited[del]=1;
	for(int i=0; i<n; i++) {
		if(visited[i]==0) {
			BFS(i,n);
		}
	}
}
int main() {
	int point_n,edge_n;
	int a,b;
	int delnum;
	scanf("%d%d",&point_n,&edge_n);
	for(int i=0; i<edge_n; i++) {
		scanf("%d%d",&a,&b);
		array[a][b]=1;
		array[b][a]=1;
	}
	scanf("%d",&delnum);
	travelDFS(0,point_n,-1);
	printf("\n");
	travelBFS(0,point_n,-1);
	printf("\n");
	for(int i=0; i<point_n; i++) {
		array[delnum][i]=0;
		array[i][delnum]=0;
	}
	travelDFS(0,point_n,delnum);
	printf("\n");
	travelBFS(0,point_n,delnum);
	return 0;
}
