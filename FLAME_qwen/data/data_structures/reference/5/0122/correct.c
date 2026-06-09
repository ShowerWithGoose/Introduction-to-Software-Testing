#include<stdio.h>
#include<string.h>
struct node{
	int num;
	int pow;
	struct node *link;
};
typedef struct node Node;
typedef struct node *Nodeptr;


int main(){
	Nodeptr head,p,q,head2=NULL,p2=NULL,q2,p0=NULL;
	head=p=NULL;
	int n,po,n2,po2;
	char c=' ';
	while(c!='\n'){
		scanf("%d%d%c",&n,&po,&c);
		q=(Nodeptr)malloc(sizeof(Node));
		q->num=n;q->pow=po;
		q->link=NULL;
		if(head==NULL)
		head=p=q;
		else{
			p->link=q;
			p=p->link;
		}
	}c=' ';
	while(c!='\n'){
		scanf("%d%d%c",&n,&po,&c);
		for(p=head;p!=NULL;p=p->link){
			n2=n*p->num;
			po2=po+p->pow;
		
		q2=(Nodeptr)malloc(sizeof(Node));
		q2->num=n2;q2->pow=po2;
		q2->link=NULL;
		if(head2==NULL)
		head2=p2=q2;
		else{
			for(p2=head2;p2!=NULL;p0=p2,p2=p2->link){
				if(q2->pow>p2->pow){
					if(p2==head2){
						q2->link=head2;head2=q2;break;
					}
					else{
						q2->link=p2;p0->link=q2;break;
					}
				}
				else if(q2->pow==p2->pow){
						p2->num+=q2->num;break;
				}
				
			}
			if(p2==NULL) p0->link=q2;
		}}
		}
		for(p2=head2;p2!=NULL;p2=p2->link){
			printf("%d %d ",p2->num,p2->pow);}
			printf("\n");
	

	}

