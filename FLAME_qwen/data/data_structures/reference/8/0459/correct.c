#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
struct node{
	int num;
	struct node *list;
}*n[200];
typedef struct node *Nodeptr;
typedef struct node Node;
int queue[200],last=-1;
void enq(int v){
	queue[++last]=v;
}
int outq(){
	int v=queue[0];
	for(int i=0;i<last;i++){
		queue[i]=queue[i+1];
	}
	last--;
	return v;
}
int visited[200]={0};
void creat(int vnum){
	for(int i=0;i<vnum;i++){
		n[i]=(Nodeptr)malloc(sizeof(Node));
		n[i]->num=i;
		n[i]->list=NULL;
	}
}
Nodeptr insert(Nodeptr p,int b){
	if(p==NULL){
		p=(Nodeptr)malloc(sizeof(Node));
		p->num=b;
		p->list=NULL;
	}else{
		if(p->list!=NULL&&b<p->list->num){
			Nodeptr q=(Nodeptr)malloc(sizeof(Node));
			q->num=b;
			q->list=p->list;
			p->list=q;
		}else{
			p->list=insert(p->list,b);
		}
		
	}
	
	return p;
}
void initial(int vnum){
	for(int i=0;i<vnum;i++){
		visited[i]=0;
	}
	printf("\n");
}
void bfs(int vnum,int x){
	for(int i=0;i<vnum;i++){
		if(visited[i]==1||i==x){
			continue;
		}
		Nodeptr p;
		printf("%d ",i);
		visited[i]=1;
		enq(i);
		while(last!=-1){
			p=n[outq()]->list;
			for(;p!=NULL;p=p->list){
				if(!visited[p->num]){
					printf("%d ",p->num);
					visited[p->num]=1;
					enq(p->num);
				}
			}
		}
	}
	
}
void dfs(Nodeptr q,int vnum){
	if(visited[q->num]==0){
		printf("%d ",q->num);
		visited[q->num]=1;
	}
	for(Nodeptr p=q->list;p!=NULL;p=p->list){
		if(visited[p->num]==0){
			printf("%d ",p->num);
			visited[p->num]=1;
			for(int i=0;i<vnum;i++){
				if(n[i]->num==p->num){
					dfs(n[i],vnum);
				}
			}
			
		}
	}
}
	

int main(){
	int vnum,ednum,a,b,ex;
	scanf("%d %d",&vnum,&ednum);
	creat(vnum);
	for(int i=0;i<ednum;i++){
		scanf("%d %d",&a,&b);
		if(b<a){
			ex=a;
			a=b;
			b=ex;
		}
		n[a]=insert(n[a],b);
		n[b]=insert(n[b],a);
	}

	dfs(n[0],vnum);
	initial(vnum);	
	bfs(vnum,-1);
	initial(vnum);
	
	int de;
	scanf("%d",&de);
	for(int i=0;i<vnum;i++){
		for(Nodeptr p=n[i];p->list!=NULL;p=p->list){
			if(p->list->num==de){
				p->list=p->list->list;
				break;
			}
		}
	}
//	for(int i=de;i<vnum-1;i++){
//		n[i]=n[i+1];
//	}
//	vnum--;
//	for(int i=0;i<vnum;i++){
//		for(Nodeptr p=n[i];p!=NULL;p=p->list){
//			printf("%d ",p->num);
//		}
//		printf("\n");
//	}
	
	dfs(n[0],vnum);
	initial(vnum+1);
	bfs(vnum,de);
	return 0;
}
