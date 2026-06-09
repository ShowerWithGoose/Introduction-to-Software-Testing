#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX 105
typedef struct edge{
	int ad;
	struct edge *next;
}Elink;
typedef struct ver{
	int num;
	Elink *link;
}Vlink;
Vlink gragh[MAX];
int visited[MAX]={0},queue[MAX],n1,n2,front=0,rear=MAX-1,count=0;

void createGragh();
Elink *insertEdge(Elink *head,int avex);
void travelIDFS();
void DFS(int v);
int VISIT(int v);
void travelBFS();
void BFS(int v);
void enQueue(int v);
int deQueue();
int isEmpty(); 
void delet(int v);

int main (){
	int v;
	scanf("%d %d",&n1,&n2);
	createGragh();
	travelIDFS();
	printf("\n");
	travelBFS();
	printf("\n");
	scanf("%d",&v);
	delet(v);
	travelIDFS();
	printf("\n");
	travelBFS();
	printf("\n");
}
void createGragh(){
	int i,v1,v2;
	
	for(i=0;i<n2;i++){
		scanf("%d%d",&v1,&v2);
		gragh[v1].link =insertEdge(gragh[v1].link ,v2);
		gragh[v2].link =insertEdge(gragh[v2].link ,v1);
		gragh[v1].num =1;
		gragh[v2].num =1;
	}
}

Elink *insertEdge(Elink *head,int avex){
	Elink *e,*p,*q;
	e=(Elink*)malloc(sizeof(Elink));
	e->ad =avex;e->next =NULL;
	if(head==NULL) {head=e;return head;	}
	for(p=q=head;p->next !=NULL;q=p,p=p->next ){
		if(p->ad >e->ad ) break;
	}
	if(p->ad >e->ad ){
		if(p==head){
			e->next =head;
			head=e;
		}
		else{
			e->next =p;
			q->next =e;
		}
	}
	else {
		p->next =e;
	}
	/*for(p=q=head;p->next !=NULL&&q->ad <=e->ad;q=p,p=p->next )
	;
	if(q->ad >e->ad ){
		if(q==head){
			e->next =head;
			head=e;
		}
	}
	else if(p->ad <e->ad ){
		p->next =e;
	}
	else{
		e->next =p;
		q->next =e;
	}
if(q==head){
		if(q->ad>e->ad ) {
			e->next =head;
			head=e;
		}
		else{
			if(q->next ==NULL) q->next =e;
			else if(p->ad<e->ad ) p->next =e;
			else{
				e->next =p;
				q->next =e;
			}
		}
	}
	else if(p->next ==NULL ) {
		if(p->ad <e->ad ) p->next =e;
		else {
			e->next =p;
			q->next =e;
		}
	}
	else {
		e->next =p;
		q->next =e;
	}*/
	return head;
}
void travelIDFS(){
	int i;
	for(i=0;i<n1;i++) visited[i]=0;
	for(i=0;i<n1;i++)
		if(!visited[i]) DFS(i);
}
void DFS(int v){
	Elink *p;
	int i;
	visited[v]=1;
	VISIT(v);
	if(gragh[v].num !=-1){
		p=gragh[v].link;
		do{
			if(!visited[p->ad ]) DFS(p->ad );
			p=p->next;
		}while(p!=NULL&&p!=gragh[v].link );
	}
		
}
int VISIT(int v){
	if(gragh[v].num !=-1) printf("%d ",v );
}
void travelBFS(){
	int i;
	for(i=0;i<n1;i++) visited[i]=0;
	for(i=0;i<n1;i++)
		if(!visited[i]) BFS(i);
}
void BFS(int v){
	Elink *p;
	visited[v]=1;
	if(gragh[v].num !=-1){
		enQueue(v);
		while(!isEmpty()){
			v=deQueue();
			VISIT(v);
			p=gragh[v].link ;
			do{
				if(!visited[p->ad ]){
					visited[p->ad ]=1;
					enQueue(p->ad );
				}
				p=p->next;
			}while(p!=NULL&&p!=gragh[v].link );
		}
	}
		
}
void enQueue(int v){
	rear=(rear+1)%MAX;
	queue[rear]=v;
	count++;
}
int deQueue(){
	int e;
	e=queue[front];
	count--;
	front=(front+1)%MAX;
	return e;
}
int isEmpty(){
	return count==0;
}
void delet(int v){
	int i;
	Elink *p,*q;
	for(i=0;i<n1;i++){
		if(i!=v){
			for(p=q=gragh[i].link;p!=NULL&&p->ad !=v;q=p,p=p->next );
			if(p!=NULL){
				if(p->next ==NULL) {
					q->next =NULL;
				}
				else if(p==gragh[i].link ){
					q=q->next ;
					gragh[i].link =q;
				}
				else {
					q->next =p->next ;
				}
				free(p);
			}
		}
	}
	gragh[v].link =NULL;
	gragh[v].num =-1;
}
