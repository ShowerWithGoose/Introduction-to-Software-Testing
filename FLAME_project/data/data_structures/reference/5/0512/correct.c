#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
	int coef;
	int exp;
	struct Node* link;
}PNode,*PLinkList;
void link_sort(PNode *head)
{
 int value;
 PNode *p = head;
 PNode *q = NULL;

 while(p!=NULL)
 {
  q = p->link;
  while(q!=NULL)
  {
   if(p->exp < q->exp)
   {
    value = p->exp;
    p->exp = q->exp;
    q->exp = value;
    value = p->coef;
    p->coef = q->coef;
    q->coef = value;
   }
   q = q->link;
  }
  p = p->link;
 }

}
int main(){
	PLinkList p,q,r,lista=NULL,listb=NULL;
	int co,ex,i=0;
	char c;
	do{
		scanf("%d %d%c",&co,&ex,&c);
		p=(PNode*)malloc(sizeof(PNode));
		p->coef=co;
		p->exp=ex;
		if(lista==NULL){
			lista=p;
		}
		else{
			q->link=p;
		}
		q=p;
	}while(c!='\n');
	q->link=NULL;
	do{
		scanf("%d %d%c",&co,&ex,&c);
		r=lista;
		while(r!=NULL){
			p=(PNode*)malloc(sizeof(PNode));
			p->coef= r->coef*co;
			p->exp=r->exp+ex;
			if(listb==NULL){
				listb=p;
			}
			else{
				q->link=p;
			}
			q=p;
			r=r->link;
		}
	}while(c!='\n');  
	q->link=NULL;
	link_sort(listb);
	    p=listb;
	    q=p->link;
	while(p!=NULL&&q!=NULL){
		while(p->exp==q->exp){
			p->coef+=q->coef;
			p->link=q->link;
			q=q->link;
		}
		p=p->link;
		q=q->link;
	}		
	p=listb;
	while(p!=NULL){
		printf("%d %d ",p->coef,p->exp);
		free(p);
		p=p->link;
	}
	return 0;
}

