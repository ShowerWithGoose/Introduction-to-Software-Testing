#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct enode{
	struct enode* next;
	int adjvex;//顶点编号 
};
struct vnode{
	struct enode* link;
};
struct vnode G[105];
int visited[105];
int Visited[105];
void dfs(struct vnode G[],int);
void bfs(struct vnode G[],int);
struct enode* insert(struct enode*, int);
int queue[1024];
int empty(int queue[]);
int deQueue(int queue[]);
int front=0;
int rear=-1;
void enQueue(int );
int delet;
int main(){
	int n,m;
	scanf("%d%d",&n,&m);//n为顶点个数，m为边的个数 
	int i;
	int v1,v2;
	for(i=0;i<m;i++){
		scanf("%d%d",&v1,&v2);
		G[v1].link=insert(G[v1].link,v2);
		G[v2].link=insert(G[v2].link,v1);
	}
	scanf("%d",&delet);
	for(i=0;i<n;i++){
		if(visited[i]==0){
			dfs(G,i);
		}
	}
	printf("\n");
	for(i=0;i<n;i++){
		if(Visited[i]==0){
			bfs(G,i);
		}
	}
	printf("\n");
	for(i=0;i<n;i++){
		if(i!=delet){
			visited[i]=0;
			Visited[i]=0;
		}
		else{
			visited[i]=1;
			Visited[i]=1;
		}
	}
	for(i=0;i<n;i++){
		if(visited[i]==0){
			dfs(G,i);
		}
	}
	printf("\n");
	for(i=0;i<n;i++){
		if(Visited[i]==0){
			bfs(G,i);
		}
	}
	printf("\n");	
}
struct enode* insert(struct enode* head, int v){
	struct enode* p;
	p=(struct enode*)malloc(sizeof(struct enode));
	p->adjvex=v;
	p->next=NULL;
	if(head==NULL){
		head=p;
		return head;
	}
	else{
		struct enode* q;
		struct enode* q0;
		for(q=head;q!=NULL;q0=q,q=q->next){
			if(v<q->adjvex && q!=head){
				q0->next=p;
				p->next=q;
				return head;
			}
			else if(v<q->adjvex && q==head){
				p->next=head;
				head=p;
				return head;
			}
		}
		q0->next=p;
		return head;
	}
}


void dfs(struct vnode G[],int v){
	visited[v]=1;
	if(v==0) printf("%d",v);
	else printf(" %d",v);
	struct enode* p;
	for(p=G[v].link;p!=NULL;p=p->next){
		if(visited[p->adjvex]==0){
			dfs(G,p->adjvex);
		}
	}
}

void bfs(struct vnode G[],int v){
	Visited[v]=1;
	if(v==0) printf("%d",v);
	else printf(" %d",v);
	enQueue(v);
	while(empty(queue)!=0){
		int k=deQueue(queue);
		struct enode* p;
		for(p=G[k].link;p!=NULL;p=p->next){
			if(Visited[p->adjvex]==0){
				Visited[p->adjvex]=1;
				printf(" %d",p->adjvex);
				enQueue(p->adjvex);
			}
		}
	}
}
int empty(int queue[]){
	if(front>rear) return 0;
	else return 1;
}
void enQueue(int v){
	queue[++rear]=v;
}
int deQueue(int queue[]){
	front++;
	return queue[front-1];
}




