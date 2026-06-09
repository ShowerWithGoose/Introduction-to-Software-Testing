
#include <stdio.h>
#include <stdlib.h>
struct  Node { //一个多项式节点结构
    int coe; //系数
    int pow; //幂
    struct Node *next;
}; 
int main()
{
    int a,n;
    char c;
    struct Node *head1,*head2,*head3,*p,*q1,*q2,*p0,*q3,*r,*r0,*t;
    head1 = p = NULL;
    do {  
        scanf("%d%d%c",&a, &n, &c);
        q1 =  (struct Node *)malloc(sizeof(struct Node));
        q1->coe = a; q1->pow = n; q1->next = NULL;
        if( head1 == NULL) 
             head1 = p = q1;
       else {
            p->next = q1;
            p = p->next;
       }
	} while ( c != '\n');
	head2 = p = NULL;
    do {  
        scanf("%d%d%c",&a, &n, &c);
        q2 =  (struct Node *)malloc(sizeof(struct Node));
        q2->coe = a; q2->pow = n; q2->next = NULL;
        if( head2 == NULL) 
             head2 = p = q2;
       else {
            p->next = q2;
            p = p->next;
       }
	} while ( c != '\n');
	t=head3=NULL;	
	
	for(p=head1; p!=NULL; p0=p,p=p->next){
		for(r=head2;r!=NULL;r0=r,r=r->next){
			q3 =  (struct Node *)malloc(sizeof(struct Node));
			q3->coe=(p->coe)*(r->coe);
			q3->pow=(p->pow)+(r->pow);
			q3->next=NULL;
	        if( head3 == NULL) 
	             head3 = t = q3;
	        else {
	            t->next = q3;
	            t = t->next;
	       }
		}
	}
	r0=NULL;
	for(p=head3;p!=NULL;p=p->next){
		for(r=p;r->next!=NULL;r=r->next){
			if(r->next->pow==p->pow){
				p->coe+=r->next->coe;
				r->next=r->next;
				r->next=r->next->next;
			}
		}
	}
	for(p=head3;p!=NULL;p=p->next){
		for(r=p->next;r!=NULL;r=r->next){
			if(r->pow>p->pow){
				r->pow ^= p->pow;
				p->pow ^= r->pow;
				r->pow ^= p->pow;
				r->coe ^= p->coe;
				p->coe ^= r->coe;
				r->coe ^= p->coe;
			}
		}
	}
	for(p=head3;p!=NULL;p=p->next){
		printf("%d %d ",p->coe,p->pow);
	}
	while(head1!=NULL){
		p0 = head1;
		head1 = head1->next;
		free(p0);
	}
/*	free(head1);
	while(head2!=NULL){
		p0 = head2;
		head2 = head2->next;
		free(p0);
	}
	free(head2);
	while(head3!=NULL){
		p0 = head3;
		head3 = head3->next;
		free(p0);
	}
	free(head3);*/
	return 0;
}



