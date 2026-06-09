#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct _polynomial{
	int coefficient;
	int numerical;
	struct _polynomial *link;
};
typedef struct _polynomial *ppoly;
typedef struct _polynomial poly;

int main()
{
	ppoly p,q,r,s,t,list=NULL,res0,res,head=NULL;
	int i=0,j,k,l,coe,num;
	char c;
	list=NULL;
	p=NULL;
	do{
		scanf("%d%d%c",&coe,&num,&c);
		q=(ppoly)malloc(sizeof(poly));
		q->coefficient=coe;
		q->numerical=num;
		q->link=NULL;
		
		if(list==NULL){
			list=p=q;
		}
		else{
			p->link=q;
			p=q;
		}
	}while(c!='\n');
	
	
	res=NULL;

	do{
		scanf("%d%d%c",&coe,&num,&c);
		i++;
		q=(ppoly)malloc(sizeof(poly));
		q->coefficient=coe;
		q->numerical=num;
		if(i==1){
			for(p=list;p!=NULL;p=p->link){
				t=(ppoly)malloc(sizeof(poly));
				t->coefficient=(p->coefficient)*(q->coefficient);
				t->numerical=(p->numerical)+(q->numerical);
				t->link=NULL;				
				if(head==NULL){
					head=res=t;
				}
				else{
					res->link=t;
					res=t;					
				}
			}			
		}
		else{
			for(p=list;p!=NULL;p=p->link){
				res0=(ppoly)malloc(sizeof(poly));
				res0->numerical=(p->numerical)+(q->numerical);
				res0->coefficient=(p->coefficient)*(q->coefficient);
				for(r=head,s=r;(r->numerical > res0->numerical) && (r->link!=NULL);r=r->link){
					s=r;
				}
				if((r->link==NULL) && (r->numerical>res0->numerical)){
					r->link=res0;
					res0->link=NULL;
				}
				else if((r->link==NULL) && (r->numerical==res0->numerical)){
					r->coefficient+=res0->coefficient;
				}
				else if((r->link!=NULL) && (r->numerical==res0->numerical)){
					r->coefficient+=res0->coefficient;
				}
				else{
					res0->link=s->link;
					s->link=res0;
				}
			}
		}	
	}while(c!='\n');
	
	for(r=head;r->link!=NULL;r=r->link){
		printf("%d %d ",r->coefficient,r->numerical);
	}
	printf("%d %d ",r->coefficient,r->numerical); 
	return 0;
}

