#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
struct multi1{
	long long a,b;
	struct multi1 *next;
}*head1,*p1,*q1;
struct multi2{
	long long a,b;
	struct multi2 *next;
}*head2,*p2,*q2;
struct multi{
	long long a,b;
	struct multi *next;
}*head,*p,*q,*t;

int main(){
	head1=NULL,head2=NULL,head=NULL;
	char s[1000];
	gets(s);
	int lenth=strlen(s),i,j,x,y;
	for(i=0,x=0,j=0;i<lenth;i++){
		if(s[i]!=' '){
			x=x*10+(s[i]-'0');
		}
		else{
			j++;
			if(j%2==1){
				p1=(struct multi1*)malloc(sizeof(struct multi1));
				p1->a=x;
				x=0;
				p1->next=NULL;
				if(head1==NULL){
					head1=p1;
				}
				else{
					q1->next=p1;
				}
				q1=p1;
			}
			else{
				p1->b=x;
				x=0;
			}
		}
	}
	p1->b=x;
	gets(s);
	lenth=strlen(s);
	for(i=0,j=0,x=0;i<lenth;i++){
		if(s[i]!=' '){
			x=x*10+(s[i]-'0');
		}
		else{
			j++;
			if(j%2==1){
				p2=(struct multi2*)malloc(sizeof(struct multi2));
				p2->a=x;
				x=0;
				p2->next=NULL;
				if(head2==NULL){
					head2=p2;
				}
				else{
					q2->next=p2;
				}
				q2=p2;
			}
			else{
				p2->b=x;
				x=0;
			}
		}
	}
	p2->b=x;
	p1=head1,p2=head2;
	while(p2!=NULL){
		p=(struct multi*)malloc(sizeof(struct multi));
		p->a=(p1->a)*(p2->a);
		p->b=(p1->b)+(p2->b);
		p->next=NULL;
		if(head==NULL){
			head=p;
		}
		else{
			q->next=p;
		}
		q=p;
		p2=p2->next;
	}
	p1=p1->next;
	p2=head2;
	q=head,p=q->next;
	while(p1!=NULL){
		while(p2!=NULL){
			x=(p1->a)*(p2->a);
			y=(p1->b)+(p2->b);
			while(p!=NULL){
				if(q->b==y){
					q->a+=x;
					break;
				}
				else if(q->b>y&&p->b<y){
					t=(struct multi*)malloc(sizeof(struct multi));
					t->next=p;
					q->next=t;
					q=t;
					q->a=x;
					q->b=y;
					break;
				}
				q=p;
				p=p->next;
			}
			if(p==NULL&&q->b==y){
				q->a+=x;
			}
			else if(p==NULL&&q->b!=y){
				p=(struct multi*)malloc(sizeof(struct multi));
				p->next=NULL;
				p->a=x;
				p->b=y;
				q->next=p;
			}
			p2=p2->next;
		}
		p1=p1->next;
		p2=head2;
		p=head;
	}
	p=head;
	while(p!=NULL){
		printf("%d %d ",p->a,p->b);
		p=p->next;
	}
	
	
	return 0;
}


