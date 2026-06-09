#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct node {
	int data;
	int row;
	struct node *next;
};
int main() {
	struct node *head,*head2,*head3,*head4,*p,*q,*t,*s,*x,*y;
	int n,i,a,b;
	char c;
	head=head2=head3=head4=NULL;
	while(~scanf("%d%d",&a,&b)) {
		p=(struct node*)malloc(sizeof(struct node));
		p->data=a;
		p->row=b;
		p->next=NULL;
		if(head==NULL) {
			head=p;
		} else q->next=p;
		q=p;
		if(c=getchar()=='\n') break;
	}
	while(~scanf("%d%d",&a,&b)) {
		p=(struct node*)malloc(sizeof(struct node));
		p->data=a;
		p->row=b;
		p->next=NULL;
		if(head2==NULL) {
			head2=p;
		} else q->next=p;
		q=p;
	}
	t=head;
	while(t!=NULL) { //³Ë
		s=head2;
		while(s!=NULL) {
			a=t->data*s->data;
			b=t->row+s->row;
			p=(struct node*)malloc(sizeof(struct node));
			p->data=a;
			p->row=b;
			p->next=NULL;
			if(head3==NULL) {
				head3=p;
			} else q->next=p;
			q=p;
			s=s->next;
		}
		t=t->next;
	}
	x=head3;
	while(x!=NULL) { //ºÏ²¢
		s=x;
		while(s->next!=NULL) {
			if(s->next->row==x->row) {
				x->data+=s->next->data;
				s->next=s->next->next;
			}
			else s=s->next;
		}
		x=x->next;
	}
	x=head3;
	while(x!=NULL) { //ÅÅÐò
		if(x->data==0) {
			x=x->next;
			continue;
		}
		p=(struct node*)malloc(sizeof(struct node));
		p->data=x->data;
		p->row=x->row;
		p->next=NULL;
		if(head4==NULL) {
			head4=p;
		} else {
			y=head4;
			while(y!=NULL) {
				if(y->next==NULL||y->next->row<x->row) {
					p->next=y->next;
					y->next=p;
					break;
				}
				y=y->next;
			}
		}
		x=x->next;
	}
	y=head4;
	while(y!=NULL){ //Êä³ö 
		printf("%d %d ",y->data,y->row);
		y=y->next;
	}
	getchar();
	getchar();
	return 0;
}


