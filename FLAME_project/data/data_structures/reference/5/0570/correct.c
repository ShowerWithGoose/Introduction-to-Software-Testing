#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
struct node {
	int coe;
	int pow;
	struct node *next;
};
typedef struct node Node;
typedef struct node *Nodeptr;
Nodeptr list1=NULL,list2=NULL;
 
void createlist1()
{
	Nodeptr p=list1,q;
	int a,n;
	char c;
	do{
		scanf("%d%d%c",&a,&n,&c);
		q=(Nodeptr)malloc(sizeof(Node));
		q->coe=a; q->pow=n; q->next=NULL;
		if(list1==NULL) p=list1=q;
		else {
			p->next=q;
			p=p->next;
		}
	}while(c!='\n');
}

void multList()
{
	Nodeptr p1,p2,p0,q;
	int a1,n1,a2,n2,a3;
	char c;
	do{
		scanf("%d%d%c",&a1,&n1,&c);
		for(p1=list1;p1!=NULL;p1=p1->next)
		{
			a3= p1->coe; a2=a1*a3; n2=n1+(p1->pow);
			q=(Nodeptr)malloc(sizeof(Node));
			q->coe=a2; q->pow=n2; q->next=NULL;
			if(list2==NULL) list2=q;
			else {
			for(p2=list2;p2!=NULL;p0=p2,p2=p2->next)
			{
				if(q->pow>p2->pow)
				{
					if(p2==list2) {
						q->next=p2;
						list2=q;
						break;
					}
					else{
						q->next=p2;
						p0->next=q; break;
					}
				}
				else if(q->pow==p2->pow){
					p2->coe=q->coe+p2->coe; break;
				}
			}
			if(p2==NULL) p0->next=q;
			}
		}	
	}while(c!='\n');
}

int main()
{
	Nodeptr p;
	createlist1();
	multList();
	for(p=list2;p!=NULL;p=p->next)
	printf("%d %d ",p->coe,p->pow);
	
}


