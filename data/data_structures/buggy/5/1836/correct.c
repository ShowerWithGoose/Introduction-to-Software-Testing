#include<stdio.h>
#include<stdlib.h>
struct Node{
	int coe;
	int pow;
	struct Node *next;
};
int main()
{
	int n;
	char cr;
	struct Node *ah , *bh , *ch , *a , *b , *c , *q , *p , *r;
	ah=NULL;
	bh=NULL;
	ch=NULL;
	scanf("%d" , &n);
	scanf("%c" , &cr);
	while(cr!='\n'){
		q=(struct Node*)malloc(sizeof(struct Node));
		q->next=NULL;
			q->coe=n;
		scanf("%d" , &n);
			q->pow=n;
			if(ah==NULL){
				ah=q;
				a=q;	
			}
			else{
				a->next=q;
				a=a->next;
			}
		scanf("%c" , &cr); 
		if(cr!='\n') scanf("%d" , &n);
	}
	scanf("%d" , &n);
	scanf("%c" , &cr);
	while(cr!='\n'){
		q=(struct Node*)malloc(sizeof(struct Node));
		q->next=NULL;
			q->coe=n;
		scanf("%d" , &n);
			q->pow=n;
			if(bh==NULL){
				bh=q;
				b=q;	
			}
			else{
				b->next=q;
				b=b->next;	
			}
		scanf("%c" , &cr);
		if(cr!='\n') scanf("%d" , &n);
	}
	while(ah!=NULL){
		p=bh;
		while(p!=NULL){
			q=(struct Node*)malloc(sizeof(struct Node));
			q->next=NULL;
			q->coe=(ah->coe)*(p->coe);
			q->pow=ah->pow+p->pow;
			if(ch==NULL){
				ch=q;	
			}
			else if(ch->pow<q->pow){
				q->next=ch;
				ch=q;
			}
			else{
				c=ch;
				while(c->next!=NULL && c->pow>q->pow){
					r=c;
					c=c->next;
				}
				if(c->pow==q->pow){
					c->coe=c->coe+q->coe;
				}
				else if(c->pow<q->pow){
					q->next=c;
					r->next=q;
				}
				else if(c->next==NULL){
					if(c->pow>q->pow){
						c->next=q;
					}
				}
			}
			p=p->next;
		}
		ah=ah->next;	
	}	
	while(ch!=NULL){
		printf("%d %d " , ch->coe , ch->pow);
		ch=ch->next;
	}
	return 0;
 } 

