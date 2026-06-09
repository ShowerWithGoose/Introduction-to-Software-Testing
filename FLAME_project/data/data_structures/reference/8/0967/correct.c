#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct gg{
	struct gg *next;
	int atom,adjvex;
}elink;
typedef struct ff{
	elink* next;
	int vertex;
}vlink;
vlink G[101];
elink* insertgraph(elink* head,int m){
	elink*q=(elink*)malloc(sizeof(elink));
	elink*p;
	p=head;
	q->next=NULL;
	q->adjvex=m;
	if(p==NULL){
		return q;
	}else{
		while(p->next!=NULL){
			p=p->next;
		}
		p->next=q;
		return head;
	}
}
void DFS(vlink head,int flag[]){
	elink*p;
	int min;
	p=head.next;
	printf("%d ",head.vertex);
	if(p==NULL){
		return;
	}else{
		while(1){
			p=head.next;min=500;
			while(p!=NULL){
				if(flag[p->adjvex]==0){
					if(min>p->adjvex){
						min=p->adjvex;
					}
				}
				p=p->next;
			}
			if(min==500){
				return;
			}
				flag[min]=1;
				DFS(G[min],flag);
		}
		return;
	}
}
vlink queue[200];
int start,end;
void BFS(vlink head,int flag[]){
	elink*q;
	vlink p;
	int min;
	queue[end]=head;
	end++;
	while(end!=start){
		p=queue[start];
		printf("%d ",p.vertex);
		start++;
		q=p.next;
		while(1){
			q=p.next;min=500;
			while(q!=NULL){
				if(flag[q->adjvex]==0){
					if(q->adjvex<min){
						min=q->adjvex;
					}
				}
				q=q->next;
			}
			if(min==500){
				break;
			}
			queue[end]=G[min];
			flag[min]=1;
			end++;		
		}
	} 
}
int main()
{
	int n,m,i,v1,v2,tarv,flag[200]={};
	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++){
		G[i].next=NULL;
		G[i].vertex=i;
	}
	for(i=0;i<m;i++){
		scanf("%d%d",&v1,&v2);
		G[v1].next=insertgraph(G[v1].next,v2);
		G[v2].next=insertgraph(G[v2].next,v1);
	}
	scanf("%d",&tarv);
	flag[0]=1;
	DFS(G[0],flag);
	memset(flag,0,200);
	printf("\n");
	flag[0]=1;
	BFS(G[0],flag);
	memset(flag,0,200);
	printf("\n");
	flag[tarv]=1;
	flag[0]=1;
	DFS(G[0],flag);
	memset(flag,0,200);
	printf("\n");
	flag[0]=flag[tarv]=1;
	BFS(G[0],flag);
	memset(flag,0,200);
	printf("\n");
	return 0;
} 


