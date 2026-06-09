#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int ven;
	struct node *next;
}LNODE,*linklist;
typedef struct edge{
	int data;
	linklist link;
}Lnode;
Lnode lnode[101];
int flag[101],line[101];
int j,k;
int top=0;
int D[101],B[101],pan[101];
void DFS(int v);
void BFS(int v);
int main(){
	int n,num,del,a,b;
	scanf("%d %d",&n,&num);
	for(int i=0;i<n;i++)
		lnode[i].link=NULL;
	for(int i=0;i<num;i++){
		scanf("%d %d",&a,&b);
		lnode[a].data=a;
		if(lnode[a].link==NULL){  //判断成功 
		    linklist p;
		    p=(linklist)malloc(sizeof(LNODE));
			p->ven=b;
			p->next=NULL;
			lnode[a].link=p;
		}
		else{
			linklist p;
	        p=lnode[a].link;
	        if(p->ven>b){
	        	linklist l;
	        	l=(linklist)malloc(sizeof(LNODE));
	        	lnode[a].link=l;
	        	l->next=p;
	        	l->ven=b;
			}
			else{
		while(p->next!=NULL&&p->next->ven<b){
			p=p->next;
		}
			linklist q;
			q=(linklist)malloc(sizeof(LNODE));
			if(p->next!=NULL){
				q->next=p->next;
				p->next=q;
				q->ven=b;
			}
			
			else{
				p->next=q;
				q->ven=b;
				q->next=NULL;
			}
		}
		}
			lnode[b].data=b;
		if(lnode[b].link==NULL){  //判断成功 
		    linklist p;
		    p=(linklist)malloc(sizeof(LNODE));
			p->ven=a;
			p->next=NULL;
			lnode[b].link=p;
		}
		else{
			linklist p;
	        p=lnode[b].link;
	        if(p->ven>a){
	        	linklist l;
	        	l=(linklist)malloc(sizeof(LNODE));
	        	lnode[b].link=l;
	        	l->next=p;
	        	l->ven=a;
			}
			else{
		while(p->next!=NULL&&p->next->ven<a){
			p=p->next;
		}
			linklist q;
			q=(linklist)malloc(sizeof(LNODE));
			if(p->next!=NULL){
				q->next=p->next;
				p->next=q;
				q->ven=a;
			}
			
			else{
				p->next=q;
				q->ven=a;
				q->next=NULL;
			}
		}
		}
	}
	scanf("%d",&del);
	DFS(0);
	for(int i=0;i<n;i++){
		printf("%d ",D[i]);
		D[i]=0;
		}
	printf("\n");//1
	for(int i=0;i<n;i++)	
		flag[i]=0;
	j=0;
	BFS(0);
	for(int i=0;i<n;i++){
		printf("%d ",B[i]);
		B[i]=0;
		}
	printf("\n");//2
	for(int i=0;i<n;i++)	
		flag[i]=0;
	j=0;
	int op=0;
	linklist p;
	p=lnode[del].link;
	while(p!=NULL){
		pan[op++]=p->ven;
		p=p->next;
	}
	lnode[del].link=NULL;
	for(int i=0;i<op;i++){
		linklist q;
		q=lnode[pan[i]].link;
		if(q->ven==del){
			lnode[pan[i]].link=q->next;
		}
		else{
		while(q->next->ven!=del){
			q=q->next;
		}
		linklist l;
		l=q->next->next;
		q->next=l;
		}
		pan[i]=0;
	}
	DFS(0);
	for(int i=0;i<n;i++)	
		flag[i]=0;
	j=0;
	BFS(0);
	for(int i=0;i<n-1;i++)
			printf("%d ",D[i]);
	printf("\n");//3
	for(int i=0;i<n-1;i++)
		printf("%d ",B[i]);
	printf("\n");//4
	return 0;
}
void DFS(int v){
	D[j++]=v;
	flag[v]=1;
	linklist p;
	for(p=lnode[v].link;p!=NULL;p=p->next){
		if(flag[p->ven]==0){
			DFS(p->ven);
		}
	}
}
void BFS(int v){
	int to;
	B[j++]=v;
	flag[v]=1;
	linklist p;
	p=lnode[v].link;
	while(p!=NULL){
		if(flag[p->ven]==0){
		flag[p->ven]=1; 
			line[k++]=p->ven;
		}
		p=p->next;
	}
	if(line[top]!=0){
		to=line[top];
		top++;
		BFS(to);
	}
} 

