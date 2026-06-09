#include<stdio.h>
#include<stdlib.h>
struct node{
	int n;
	int d;
	struct node* l;
	struct node* r;
};
typedef struct node* N;
void Btr(N x){
	if(x->l!=NULL)
		Btr(x->l);
	if(x->r!=NULL)
		Btr(x->r);
	if(x->r==NULL&&x->l==NULL)
		printf("%d %d\n",x->n,x->d);
}
int main(){
	int no,i,e;
	N q,h,s;
	scanf("%d",&no);
	scanf("%d",&e);
	h=(N)malloc(sizeof(struct node));
	h->d=1;
	h->n=e;
	h->l=NULL;
	h->r=NULL;
	for(i=1;i<no;i++){
		scanf("%d",&e);
		s=h;
		while(1){
			if(e<(s->n)){
				if(s->l==NULL){
					q=(N)malloc(sizeof(struct node));
					q->d=s->d+1;
					q->n=e;
					q->l=NULL;
					q->r=NULL;
					s->l=q;
					break;
				}
				else{
					s=s->l;
					continue;
				}
			}
			else if(e>=(s->n)){
				if(s->r==NULL){
					q=(N)malloc(sizeof(struct node));
					q->d=s->d+1;
					q->n=e;
					q->l=NULL;
					q->r=NULL;
					s->r=q;
					break;
				}
				else{
					s=s->r;
					continue;
				}
			}
			else
				break;
		}
	}
	Btr(h);
	return 0;
}

