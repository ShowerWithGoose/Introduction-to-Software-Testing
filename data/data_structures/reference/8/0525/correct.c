#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
struct dd {
	int linbian;
	struct dd *next;
};

struct dingdian {
	struct dd *next;
};
int queue[105];
int front,rear;

struct dingdian insert_dd(struct dingdian p,int aa);
void DFS(struct dingdian p[],int a);
void BFS(struct dingdian p[],int a);
struct dingdian delete_dd(struct dingdian p,int aa);
int visited[105];
int m,n,k;
struct dingdian ss[105];
int main() {
	scanf("%d %d",&m,&n);

	int i;
	for(i=0; i<m; i++) {
		ss[i].next=NULL;
	}
	int tem1,tem2;
	for(i=0; i<n; i++) {
		scanf("%d %d",&tem1,&tem2);
		ss[tem1]=insert_dd(ss[tem1],tem2);
		ss[tem2]=insert_dd(ss[tem2],tem1);
	}
	scanf("%d",&k);
	for(i=0; i<m; i++) {
		if(visited[i]==0) {
			DFS(ss,i);
		}
	}
	printf("\n");
	for(i=0; i<m; i++) {
		visited[i]=0;
	}
	for(i=0; i<m; i++) {
		if(visited[i]==0) {
			BFS(ss,i);
		}
	}
	printf("\n");
	for(i=0; i<m; i++) {
		visited[i]=0;
	}
	for(i=0; i<m; i++) {
		if(i==k)continue;
		ss[i]=delete_dd(ss[i],k);
	}
	for(i=0; i<m; i++) {
		if(i==k)continue;
		if(visited[i]==0) {
			DFS(ss,i);
		}
	}
	printf("\n");
	for(i=0; i<m; i++) {
		visited[i]=0;
	}
	for(i=0; i<m; i++) {
		if(i==k)continue;
		if(visited[i]==0) {
			BFS(ss,i);
		}
	}
	return 0;
}

struct dingdian insert_dd(struct dingdian p,int aa) {
	if(p.next==NULL) {
		p.next=(struct dd*)malloc(sizeof(struct dd));
		p.next->linbian=aa;
		p.next->next=NULL;
	} else {
		struct dd* q=p.next;
		if(aa<q->linbian) {
			struct dd* r=NULL;
			r=(struct dd*)malloc(sizeof(struct dd));
			r->linbian=aa;
			r->next=q;
			p.next=r;
		} else {
			while(q->next!=NULL&&q->next->linbian<aa) {
				q=q->next;
			}
			struct dd* r=NULL;
			r=(struct dd*)malloc(sizeof(struct dd));
			r->linbian=aa;
			r->next=q->next;
			q->next=r;
		}
	}
	return p;
}

void DFS(struct dingdian p[],int a) {
	struct dd *q;
	visited[a]=1;
	printf("%d ",a);
	for(q=p[a].next; q!=NULL; q=q->next) {
		if(visited[q->linbian]==0) {
			DFS(p,q->linbian);
		}
	}
}
void BFS(struct dingdian p[],int a) {
	visited[a]=1;
	printf("%d ",a);
	queue[rear++]=a;
	struct dd *q;
	while(front<rear) {
		a=queue[front++];
		q=p[a].next;
		for(; q!=NULL; q=q->next) {
			if(visited[q->linbian]==0) {
				visited[q->linbian]=1;
				printf("%d ",q->linbian);
				queue[rear++]=q->linbian;
			}
		}
	}
}

struct dingdian delete_dd(struct dingdian p,int aa) {
	struct dd* q=p.next;
	struct dd* r;
	if(q->linbian==aa) {
		p.next=q->next;
	} else {
		for(; q!=NULL; q=q->next) {
			if(q->linbian==aa){
				r->next=q->next;
				break;
			}
			r=q;
		}
	}
	return p;
}
