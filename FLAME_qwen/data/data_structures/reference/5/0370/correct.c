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
	struct Node *head0,*head,*p,*q,*p0,*p1;
	head0=p0=p1=NULL;
	while(scanf("%d%d%c",&a,&n,&c)!=EOF) {
		if(head0==NULL)
			head0=p0=(struct Node*)malloc(sizeof(struct Node));
		else {
			p0->next=(struct Node*)malloc(sizeof(struct Node));
			p0=p0->next;
		}
		p0->coe=a,p0->pow=n,p0->next=NULL;
		if(c=='\n') break;
	}
	head=p=NULL;
	for(p0=head0; p0!=NULL; p0=p0->next) {
		if(p0==head0)
			head=p=(struct Node*)malloc(sizeof(struct Node));
		else {
			p->next=(struct Node*)malloc(sizeof(struct Node));
			p=p->next;
		}
		p->coe=p0->coe,p->pow=p0->pow,p->next=NULL;
	}
	while(scanf("%d%d%c",&a,&n,&c)!=EOF) {
		if(f==0) {
			for(p0=head; p0!=NULL; p0=p0->next) {
				p0->coe=a*p0->coe,p0->pow=n+p0->pow;
			}
			f=1;
		} else if(f==1) {
			q=(struct Node*)malloc(sizeof(struct Node));
			for(p1=head0; p1!=NULL; p1=p1->next) {
				q=(struct Node*)malloc(sizeof(struct Node));
				q->coe=a*p1->coe,q->pow=n+p1->pow;
				q->next=NULL;
				for(p=head; p!=NULL; p0=p,p=p->next) {
					if(q->pow>p->pow) {
						if(p==head) {
							q->next=head;
							head=q;
							break;
						} else {
							q->next=p;
							p0->next=q;
							break;
						}
					} else if(q->pow==p->pow) {
						p->coe+=q->coe;
						break;
					}
				}
				if(p==NULL) p0->next=q;
			}
		}
		if(c=='\n') break;
	}
	for(p=head; p!=NULL; p=p->next) {
		printf("%d %d ",p->coe,p->pow);
	}
	return 0;
}

