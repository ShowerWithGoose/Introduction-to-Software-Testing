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
Nodeptr j,i,p1,n,p,op=NULL;
int main() {
	Nodeptr list1=NULL,list2=NULL,list3=NULL;
	i=list1;
	int a,b=0;
	char c='\0';
	do {
		scanf("%d%d%c",&a,&b,&c);
		j = (Nodeptr)malloc(sizeof(Node));
		j->coe=a;
		j->pow=b;
		j->link=NULL;
		if(list1==NULL) {
			list1=i=j;
		} else {
			i->link=j;
			i=i->link;
		}
	} while(c!='\n');
	do {
		scanf("%d%d%c",&a,&b,&c);
		for(i=list1; i!=NULL; p1=i,i=i->link) {
			j = (Nodeptr)malloc(sizeof(Node));
			j->coe=a*i->coe;
			j->pow=b+i->pow;
			j->link=NULL;
			if(list2==NULL) {
				list2=n=j;
			} else {
				n->link=j;
				n=n->link;
			}
		}
	} while(c!='\n');
	for(i=list2; i!=NULL; p1=i,i=i->link) {
		j = (Nodeptr)malloc(sizeof(Node));
		j->coe=i->coe;
		j->pow=i->pow;
		j->link=NULL;
		if(list3==NULL) {
			list3=n=j;
		} else {
			for(p=list3; p!=NULL; op=p,p=p->link) {
				if(j->pow>p->pow) {
					if(p==list3) {
						j->link=p;
						list3=j;
						break;
					} else {
						j->link=p;
						op->link=j;
						break;
					}
				}else if(j->pow==p->pow){p->coe+=j->coe;break;
				}
			}
			if(p==NULL) {
				op->link=j;
				j->link=NULL;
			}
		}
	}




	for(i=list3; i!=NULL; i=i->link) {
		printf("%d %d ",i->coe,i->pow);
	}


	return 0;
}

