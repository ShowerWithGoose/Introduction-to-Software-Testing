#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct node{
	int coe;
	int pow;
	struct node *next;
};
typedef struct node Node;
typedef struct node *Nodeptr; 
int main()
{
	int a,n,flag=0;
	char c;
	Nodeptr head1=NULL,head2=NULL,p=NULL,p1,q,p0;
	do{
		scanf("%d%d%c",&a,&n,&c);//long long
		q=(Nodeptr)malloc(sizeof(Node));
		q->coe=a;
		q->pow=n;
		q->next=NULL;
		if(head1==NULL) head1=q;
		else p->next=q;
		p=q;
	}while(c!='\n');
	do{
		scanf("%d%d%c",&a,&n,&c);
		if(flag==0){
			for(p=head1;p!=NULL;p=p->next){
				q=(Nodeptr)malloc(sizeof(Node));
				q->coe=a*p->coe;
				q->pow=n+p->pow;
				q->next=NULL;
				if(head2==NULL) head2=q;
				else p0->next=q;
				p0=q;
			}
			flag=1;
		}
		else{
			for(p=head1;p!=NULL;p=p->next){
				q=(Nodeptr)malloc(sizeof(Node));
				q->coe=a*p->coe;
				q->pow=n+p->pow;
				q->next=NULL;
				for(p1=head2;p1!=NULL;p0=p1,p1=p1->next){
					if(q->pow>p1->pow){
						if(p1==head2){
							q->next=head2;
							head2=q;
							break;
						}
						else{
							q->next=p1;
							p0->next=q;
							break;
						}
					}
					else if(q->pow==p1->pow){
						p1->coe+=q->coe;
						free(q);break;
					}
				}
				if(p1==NULL) p0->next=q;
			}
		}
	}while(c!='\n');
	for(p=head2;p!=NULL;p=p->next) printf("%d %d ",p->coe,p->pow);
	return 0;
}




