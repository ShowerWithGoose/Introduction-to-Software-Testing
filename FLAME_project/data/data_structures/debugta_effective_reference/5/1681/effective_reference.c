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
	struct node *head1,*p1,*q2,*p0,*head3=NULL,*q3,*p3;
	head1=p1=NULL;
	do{
		scanf("%d %d%c",&a,&n,&c);
		if(head1==NULL){
			head1=p1=(struct node*)malloc(sizeof(struct node));
		}
		else{
			p1->link=(struct node*)malloc(sizeof(struct node));
			p1=p1->link;
		}
		p1->coe=a;
		p1->pow=n;
		p1->link=NULL;
	}while(c!='\n');
	
	
	do{
		scanf("%d %d%c",&a,&n,&c);
		q2=(struct node*)malloc(sizeof(struct node));
		q2->coe=a;
		q2->pow=n;
		q2->link=NULL;
		for(p1=head1;p1!=NULL;p1=p1->link){
			a2=a*p1->coe;
			n2=n+p1->pow;
			
			q3=(struct node*)malloc(sizeof(struct node));
			q3->coe=a2;
			q3->pow=n2;
			q3->link=NULL;
			
			if(head3==NULL){
				head3=p3=q3;
			}
			else{
				for(p3=head3;p3!=NULL;p0=p3,p3=p3->link){
					if(q3->pow>p3->pow){
						if(p3==head3){
							q3->link=head3;
							head3=q3;
							break;
						}
						else{
				            q3->link=p3;
							p0->link=q3;
							break;	
						}
					}
					else if(q3->pow==p3->pow){
						p3->coe=p3->coe+q3->coe;
						break;
					}
				}
				if(p3==NULL){
					p0->link=q3;
				}
			}
			
		}
	}while(c!='\n');
	
	for(p3=head3;p3!=NULL;p3=p3->link){
		printf("%d %d ",p3->coe,p3->pow);
	}
	return 0;
}

