#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node {
	int coe;
	int pow;
	struct node*link;
};
typedef  struct node *Nodeptr;
typedef  struct node Node;
Nodeptr q,p,p1,p2,p3,p4=NULL;
int main() {
	Nodeptr list1=NULL,list2=NULL,list3=NULL;
	p=list1;
	int a,b=0;
	char c='\0';
	do {
		scanf("%d%d%c",&a,&b,&c);
		q = (Nodeptr)malloc(sizeof(Node));
		q->coe=a;
		q->pow=b;
		q->link=NULL;
		if(list1==NULL) {
			list1=p=q;
		} else {
			p->link=q;
			p=p->link;
		}
	} while(c!='\n');
	do {
		scanf("%d%d%c",&a,&b,&c);
		for(p=list1; p!=NULL; p1=p,p=p->link) {
			q = (Nodeptr)malloc(sizeof(Node));
			q->coe=a*p->coe;
			q->pow=b+p->pow;
			q->link=NULL;
			if(list2==NULL) {
				list2=p2=q;
			} else {
				p2->link=q;
				p2=p2->link;
			}
		}
	} while(c!='\n');
	for(p=list2; p!=NULL; p1=p,p=p->link) {
		q = (Nodeptr)malloc(sizeof(Node));
		q->coe=p->coe;
		q->pow=p->pow;
		q->link=NULL;
		if(list3==NULL) {
			list3=p2=q;
		} else {
			for(p3=list3; p3!=NULL; p4=p3,p3=p3->link) {
				if(q->pow>p3->pow) {
					if(p3==list3) {
						q->link=p3;
						list3=q;
						break;
					} else {
						q->link=p3;
						p4->link=q;
						break;
					}
				}else if(q->pow==p3->pow){p3->coe+=q->coe;break;
				}
			}
			if(p3==NULL) {
				p4->link=q;
				q->link=NULL;
			}
		}
	}




	for(p=list3; p!=NULL; p=p->link) {
		printf("%d %d ",p->coe,p->pow);
	}


	return 0;
}

