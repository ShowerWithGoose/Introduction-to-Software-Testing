#include<stdio.h>
#include<stdlib.h>
struct Node {
	int coe;
	int pow;
	struct Node *next;
};
int main() {
	int a,n,f=0;
	char c;
	struct Node *head0,*head,*r,*q,*s,*p;
	head0=s=p=NULL;
	while(scanf("%d%d%c",&a,&n,&c)!=EOF) {
		if(head0==NULL)
			head0=s=(struct Node*)malloc(sizeof(struct Node));
		else {
			s->next=(struct Node*)malloc(sizeof(struct Node));
			s=s->next;
		}
		s->coe=a,s->pow=n,s->next=NULL;
		if(c=='\n') break;
	}
	head=r=NULL;
	for(s=head0; s!=NULL; s=s->next) {
		if(s==head0)
			head=r=(struct Node*)malloc(sizeof(struct Node));
		else {
			r->next=(struct Node*)malloc(sizeof(struct Node));
			r=r->next;
		}
		r->coe=s->coe,r->pow=s->pow,r->next=NULL;
	}
	while(scanf("%d%d%c",&a,&n,&c)!=EOF) {
		if(f==0) {
			for(s=head; s!=NULL; s=s->next) {
				s->coe=a*s->coe,s->pow=n+s->pow;
			}
			f=1;
		} else if(f==1) {
			q=(struct Node*)malloc(sizeof(struct Node));
			for(p=head0; p!=NULL; p=p->next) {
				q=(struct Node*)malloc(sizeof(struct Node));
				q->coe=a*p->coe,q->pow=n+p->pow;
				q->next=NULL;
				for(r=head; r!=NULL; s=r,r=r->next) {
					if(q->pow>r->pow) {
						if(r==head) {
							q->next=head;
							head=q;
							break;
						} else {
							q->next=r;
							s->next=q;
							break;
						}
					} else if(q->pow==r->pow) {
						r->coe+=q->coe;
						break;
					}
				}
				if(r==NULL) s->next=q;
			}
		}
		if(c=='\n') break;
	}
	for(r=head; r!=NULL; r=r->next) {
		printf("%d %d ",r->coe,r->pow);
	}
	return 0;
}

