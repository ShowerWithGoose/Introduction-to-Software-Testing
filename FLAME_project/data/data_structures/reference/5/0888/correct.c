#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
typedef struct base{
	int num;
	int up;
	struct base *link;
}node,*nodeptr;
int main(){
	int count=0,i,j;
	nodeptr head1,head2,head3,p,q,r,s;
	p=q=head1=(nodeptr)malloc(sizeof(node));
	do{
		q=(nodeptr)malloc(sizeof(node));
		scanf("%d %d",&q->num,&q->up);
		p->link=q;
		p=q;
	}while(getchar()!='\n');
	q->link=NULL;
	p=q=head2=(nodeptr)malloc(sizeof(node));
	do{
		q=(nodeptr)malloc(sizeof(node));
		scanf("%d %d",&q->num,&q->up);
		p->link=q;
		p=q;
	}while(getchar()!='\n');
	q->link=NULL;
	p=head1->link;
	r=head3=(nodeptr)malloc(sizeof(node));
	while(p!=NULL){
		q=head2->link;
		while(q!=NULL){
			s=(nodeptr)malloc(sizeof(node));
			s->num=p->num*q->num;
			s->up=p->up+q->up;
			r->link=s;
			r=s;
			q=q->link;
			count++;
		}
		p=p->link;
	}
	s->link=NULL;
	for(i=1;i<count;i++){
		p=head3->link;
		r=head3;
		for(j=0;j<count-i;j++){
			if(p->up>p->link->up){
				s=p->link->link;
				r->link=p->link;
				p->link->link=p;
				p->link=s;
				p=r->link;
			}else if(p->up==p->link->up){
				q=p->link;
				p->num+=p->link->num;
				p->link=p->link->link;
				free(q);
			}
			p=p->link;
			r=r->link;
		}
	}
	p=head3;
	q=head3->link;
	if(q->link!=NULL){
		s=head3->link->link;
		while(s->link!=NULL){
			q->link=p;
			p=q;
			q=s;
			s=s->link;
		}
		q->link=p;
		s->link=q;
		p=s;
		printf("%d %d ",p->num,p->up);
		while(p->link!=head3){
			p=p->link;
			printf("%d %d ",p->num,p->up);
		}
	}
	else
		printf("%d %d ",q->num,q->up);
	return 0;
}


