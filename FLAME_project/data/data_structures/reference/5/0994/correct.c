#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>

typedef struct MULT{
	
	long long coef;
	long long  expon;
	struct MULT *link;
	
}mult;
 
void Insert(mult **,mult **);

mult *ReadPoly();

mult *Mult(mult *,mult *);

int main(){
	
	mult *head1,*head2;
	head1=ReadPoly();
	head2=ReadPoly();
	
	mult *ans=Mult(head1,head2);
	mult *pt=ans;
	while(pt!=NULL){
		printf("%lld %lld ",pt->coef,pt->expon);
		pt=pt->link;
	}
	
	return 0;
}

mult *ReadPoly(){
	
	mult *p,*q,*head=NULL;
	char c;
	do{
		p=(mult *)malloc(sizeof(mult));
		scanf("%lld%lld",&p->coef,&p->expon);
		p->link=NULL;
		if(head==NULL){
			head=q=p;
		}
		else{
			q->link=p;
		}
		q=p;
		c=getchar();
	}while(c!='\n');
	
	return head;
}

mult *Mult(mult *_p1,mult *_p2){
	
	mult *p1,*p2,*r,*ans=NULL;
	p1=_p1;
	while(p1!=NULL){
		p2=_p2;
		while(p2!=NULL){
			r=(mult *)malloc(sizeof(mult));
			r->coef=p1->coef*p2->coef;
			r->expon=p1->expon+p2->expon;
			r->link=NULL;
			if(ans==NULL){
				ans=r;
			}
			else{
				Insert(&ans,&r);
			}
			p2=p2->link;
		}
		p1=p1->link;
	}
	return ans;
	
}

void Insert(mult **_ans,mult **_r){
	
	mult *ans=*_ans;
	mult *r=*_r;
	if(r->expon>ans->expon){
		r->link=ans;
		*_ans=*_r;
		return ;
	}
	else{
		mult *p=ans;
		for(;p->link!=NULL;p=p->link){
			if(p->expon==r->expon){
				p->coef+=r->coef;
				free(r);
				return ;
			}
			else if(p->expon>r->expon){
				if(p->link->expon>=r->expon){
					continue;
				}
				else{
					r->link=p->link;
					p->link=r;
					return ;
				}
			}
		}
		if(r->expon==p->expon){
			p->coef+=r->coef;
			free(r);
			return ;
		}
		else{
			p->link=r;
		}
	}
}

