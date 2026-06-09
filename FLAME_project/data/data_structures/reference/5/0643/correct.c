#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct multi{
	int num;
	int index;
	struct multi* next;
}Node;
Node *head1=NULL,*head2=NULL,*p=NULL,*r=NULL;
int temp1,temp2;
void sort(Node** head){
	Node *q,*tail;
	q=*head;
	tail=NULL;
	if(q==NULL||q->next==NULL){
		return;
	}
	while(q!=tail){
		while(q->next!=tail){
			if(q->index < q->next->index){
				temp1=q->index;
				q->index=q->next->index;
				q->next->index=temp1;
				temp2=q->num;
				q->num=q->next->num;
				q->next->num=temp2;
			}
			q=q->next;
		}
		tail=q;
		q=*head;
	}
}
void multiply(Node** a,Node** b){
	Node *head=NULL,*p=NULL,*p1=NULL,*p2=NULL,*t=NULL;
	int count=0;
	for(p1=*a;p1!=NULL;p1=p1->next){
		for(p2=*b;p2!=NULL;p2=p2->next){
			t=(Node*)malloc(sizeof(Node));
			t->num=p1->num*p2->num;
			t->index=p1->index+p2->index;
			t->next=NULL;
			if(head==NULL){
				head=p=t;
			}
			else{
				p->next=t;
				p=p->next;
			}
		}
	}
	for(p=head;p!=NULL;p=p->next){
		Node *r1=p,*r2=NULL;
		for(r2=p->next;r2!=NULL;r2=r2->next){
			if(r2->index==p->index){
				p->num+=r2->num;
				r1->next=r2->next;
				free(r2);
				r2=r1->next;
			}
			r1=r2;
		}
	}
	sort(&head);
	for(p=head;p!=NULL;p=p->next){
		printf("%d %d ",p->num,p->index);
	}
}
int main(){
	int i,j,k,x,y;
	char c;
	while(scanf("%d%d",&x,&y)!=EOF){
		r=(Node*)malloc(sizeof(Node));
		r->num=x;
		r->index=y;
		r->next=NULL;
		if(head1==NULL){
			head1=p=r;
		}
		else{
			p->next=r;
			p=p->next;
		}
		scanf("%c",&c);
		if(c=='\n'){
			break;
		}
	}
	while(scanf("%d%d",&x,&y)!=EOF){
		r=(Node*)malloc(sizeof(Node));
		r->num=x;
		r->index=y;
		r->next=NULL;
		if(head2==NULL){
			head2=p=r;
		}
		else{
			p->next=r;
			p=p->next;
		}
		scanf("%c",&c);
		if(c=='\n'){
			break;
		}
	}
	multiply(&head1,&head2);
	return 0;
}

