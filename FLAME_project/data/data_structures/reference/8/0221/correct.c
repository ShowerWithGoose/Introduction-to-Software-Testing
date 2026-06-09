#include<stdio.h>
#include<stdlib.h>
#define MAX 105
typedef struct node{
	int id;
	struct node*next;
}node,*LinkList;
LinkList A[MAX];
int v[MAX];
int Q[MAX];
int front=0,rear=MAX-1,len=0;
int n,b; 
void insert(int a,int b);
void bfs();
void BFS(int a);
int deQueue();
void enQueue(int a);
void DFS(int a);
void dfs();
void destory(int a);
int main(){
	LinkList p;
	int i,n1,n2,n3;
	scanf("%d%d",&n,&b);
	for(i=0;i<b;i++){
		scanf("%d%d",&n1,&n2);
		insert(n1,n2);
		insert(n2,n1);
	}
	scanf("%d",&n3);
/*	for(i=0;i<n;i++){
		for(p=A[i];p;p=p->next){
			printf("%d",p->id);
		}
		printf("\n");
	}*/
	dfs();
	printf("\n");
	bfs();
	printf("\n");	
	destory(n3);
	dfs();
	printf("\n");
	bfs();
	return 0;
} 
void insert(int a,int b){
	LinkList p,q,r;
	if(!A[a]){
		A[a]=(LinkList)malloc(sizeof(node));
		A[a]->id=a;
		A[a]->next=NULL;
		p=(LinkList)malloc(sizeof(node));
		p->id=b;
		p->next=A[a]->next;
		A[a]->next=p;
	}
	else {
		q=A[a];
		for(p=A[a]->next;p;p=p->next){
			if(p->id>b){
				r=(LinkList)malloc(sizeof(node));
				r->id=b;
				r->next=p;
				q->next=r;
				break;		
			}
			q=p;
		}
		if(!p){
			r=(LinkList)malloc(sizeof(node));
			r->id=b;
			r->next=p;
			q->next=r;
		}
	}
}
void bfs(){
	int i;
	for(i=0;i<n;i++){
		v[i]=0;
	}
	for(i=0;i<n;i++){
		if(!v[i]&&A[i]){
			BFS(i);
		}
	}
}
void BFS(int a){
    LinkList q;
    v[a]=1; //标识某顶点已入队
    enQueue(a);
    while(len){
         a=deQueue();  //取出队头元素
         printf("%d ",A[a]->id);
         for(q=A[a]->next;q!=NULL;q=q->next) //访问该顶点的每个邻接顶点
             if(!v[q->id]) {
                v[q->id]=1; //标识某顶点入队
                enQueue(q->id);
           }
     }
}
void enQueue(int a){
	rear=(rear+1)%MAX;
	Q[rear]=a;
	len++;
}

int deQueue(){
	len--;
	int a;
	a=Q[front];
	front=(front+1)%MAX;
	return a;
}

void dfs(){
	int i;
	for(i=0;i<n;i++){
		v[i]=0;
	}
	for(i=0;i<n;i++){
		if(!v[i]&&A[i]){
			DFS(i);
		}
	}
}
void DFS(int a){
    LinkList p;
    v[a]=1; //标识某顶点被访问过
    printf("%d ",A[a]->id); 
	    for(p=A[a]->next;p!=NULL;p=p->next)
         if(!v[p->id])
            DFS(p->id);
}

void destory(int a){
	LinkList p=A[a]->next,q,r;
	for(;p;p=p->next){
		for(q=A[p->id]->next,r=A[p->id];q;q=q->next){
			if(q->id==a){
				r->next=q->next;
				free(q);
				break;
			}
			r=q;
		}
	}
	A[a]=NULL;
}

