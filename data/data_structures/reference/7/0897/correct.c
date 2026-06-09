#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>


struct node{
	int data,width;
	struct node *l,*r;
};
void visit(struct node *p){
	if(p->l==NULL&&p->r==NULL){
		printf("%d %d\n",p->data,p->width);
	}
}
void bfs(struct node*);
void bfs(struct node *p){
	if(p!=NULL){
		visit(p);
		bfs(p->l);
		bfs(p->r);
	}
}

int main(){
	struct node *first,*p,*q;
	int n,d;
	scanf("%d",&n);
	first=(struct node*)malloc(sizeof(struct node));
	p=first;
	first->l=NULL;
	first->r=NULL;
	first->width=1;
	scanf("%d",&first->data);
	for(int i=1;i<n;i++){
		scanf("%d",&d);
		q=p=first;
		int j=1;
		while(p!=NULL){
		    if(d<p->data){
		    	q=p;
				p=p->l;
			}
			else {
				q=p;
				p=p->r;
			}
			j++;
		}
		p=(struct node*)malloc(sizeof(struct node));
		p->data=d;
		p->width=j;
		if(d<q->data){
			q->l=p;
		}
		else{
			q->r=p;
		}
		p->l=p->r=NULL; 
	}
	bfs(first);
	
	
	/*while(ff==ll==n){
		if(q[ff]->l!=NULL){
			q[++ll]=ff->l;
		}
		if(q[ff]->r!=NULL){
			q[++ll]=ff->r;
		}
		ff++;
		if(q[ff]->l==NULL&&q[ff]->r==NULL){
			
		}
		
	}*/
	
	
	return 0;
} 

