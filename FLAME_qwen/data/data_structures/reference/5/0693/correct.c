#include <stdio.h>
#include <stdlib.h>
struct node{
	int coe;
	int pow;
	struct node *link;
};

int main(){
	int a,n,a2,n2;
	char c;
	struct node *head,*p,*q,*p0,*head2=NULL,*p3,*q3;
	head=p=NULL;
	do{
		scanf("%d %d%c",&a,&n,&c);
		if(head==NULL){
			head=p=(struct node*)malloc(sizeof(struct node));
		}
		else{
			p->link=(struct node*)malloc(sizeof(struct node));
			p=p->link;
		}
		p->coe=a;
		p->pow=n;
		p->link=NULL;
	}while(c!='\n');
	
	
	do{
		scanf("%d %d%c",&a,&n,&c);
		q=(struct node*)malloc(sizeof(struct node));
		q->coe=a;
		q->pow=n;
		q->link=NULL;
		for(p=head;p!=NULL;p=p->link){
			a2=a*p->coe;
			n2=n+p->pow;
			
			p3=(struct node*)malloc(sizeof(struct node));
			p3->coe=a2;
			p3->pow=n2;
			p3->link=NULL;
			
			if(head2==NULL){
				head2=q3=p3;
			}
			else{
				for(q3=head2;q3!=NULL;p0=q3,q3=q3->link){
					if(p3->pow>q3->pow){
						if(q3==head2){
							p3->link=head2;
							head2=p3;
							break;
						}
						else{
				            p3->link=q3;
							p0->link=p3;
							break;	
						}
					}
					else if(p3->pow==q3->pow){
						q3->coe=q3->coe+p3->coe;
						break;
					}
				}
				if(q3==NULL){
					p0->link=p3;
				}
			}
			
		}
	}while(c!='\n');
	
	for(q3=head2;q3!=NULL;q3=q3->link){
		printf("%d %d ",q3->coe,q3->pow);
	}
	return 0;
}

