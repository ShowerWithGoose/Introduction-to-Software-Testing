#include<stdio.h>
#include <stdlib.h>
typedef struct node {
	int coe; //系数
	int pow; //指数
	struct node *link;
}lnode,*list;
int main() {
	int a,n;
	char c;
	list p,q,heada,headb,pa,pb,r;
	heada = p = NULL;
	do {
		scanf("%d%d%c",&a,&n,&c);
		q=(list)malloc(sizeof(lnode));
		q->coe=a;
		q->pow=n;
		q->link=NULL;
		if(heada==NULL) heada=p=q;
		else {
			p->link=q;
			p=p->link;
		}
	} while(c!='\n');
	headb=pb=NULL;
	do {
		scanf("%d%d%c",&a,&n,&c);
		for(pa=heada; pa!=NULL;) {
			q=(list)malloc(sizeof(lnode));
			q->coe=pa->coe*a;
			q->pow=pa->pow+n;
			q->link=NULL;
			if(headb==NULL) headb=pb=q;
			else {
				pb->link=q;
				pb=pb->link;
			}
			pa=pa->link;
		}
	} while(c!='\n');
	for(r=headb; r->link!=NULL;) {
		int itempow=r->pow;
		q=r;
		p=r->link;
		while(p!=NULL) {
			if(p->pow==itempow) {
				r->coe+=p->coe;
				q->link=p->link;
				free(p);
				p=q->link;
			} else {
				q=p;
				p=p->link;
			}
		}
		if(r->coe==0){
			list s;
			if(r==headb){
				headb=headb->link;
				free(r);
				r=headb;
			}
			else{
				for(s=headb;s->link!=r;s=s->link){
					s->link=r->link;
					free(r);
					r=s->link;
				}
			}
		}
		else r=r->link;
	}
	
	list tail=NULL;
	while(headb!=tail){
		p=headb;
		while(p->link!=tail){
			q=p->link;
			if(p->pow<q->pow){
				int tmp=p->pow;
				p->pow=q->pow;
				q->pow=tmp;
				tmp=p->coe;
				p->coe=q->coe;
				q->coe=tmp;
			}
			p=p->link;
		}
		tail=p;
	}
	
	p=headb;
	while(p!=NULL){
		printf("%d %d ",p->coe,p->pow);
		p=p->link;
	}
	return 0;
}

