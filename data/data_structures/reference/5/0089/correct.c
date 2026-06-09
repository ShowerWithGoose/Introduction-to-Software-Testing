#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Pol{
	int coe;
	int time;
	struct Pol *next;
}; 
typedef struct Pol *Nodeptr;
typedef struct Pol Node;
Nodeptr merge(Nodeptr head,int a,int b);
int main()
{
	Nodeptr head,head1,pre,pre1,p;
	int a,b,c,d;
	char ch;
	head1=(Nodeptr)malloc(sizeof(Node));
	head1->next=NULL;
	pre1=head1;
	do{
		scanf("%d%d%c",&a,&b,&ch);
		pre1->coe=a;pre1->time=b;
		pre1->next=(Nodeptr)malloc(sizeof(Node));
		pre1=pre1->next;
		pre1->next=NULL;
	}while(ch!='\n');
	head=NULL;
	do{
		scanf("%d%d%c",&a,&b,&ch);
		pre1=head1;
		while(pre1->next!=NULL){
			c=a*pre1->coe;
			d=b+pre1->time;
			head=merge(head,c,d);
			pre1=pre1->next;
		}
	}while(ch!='\n');
	pre=head;
	while(pre!=NULL){
		printf("%d %d ",pre->coe,pre->time);
		p=pre;
		pre=pre->next;
		free(p);
	}
}
Nodeptr merge(Nodeptr head,int a,int b)
{
	Nodeptr p,q,r;
	r=(Nodeptr)malloc(sizeof(Node));
	r->coe=a;r->time=b;
	r->next=NULL;
	if(head==NULL)
	return r;
	else{
		for(p=head;p!=NULL&&p->time>b;q=p,p=p->next);
		if(p==NULL){
			q->next=r;
			r->next=p;
		}
		else if(p->time==b) {
			p->coe+=a;
			free(r); 
		}
		else{
			q->next=r;
			r->next=p;
		}
	return head;
	}
}

