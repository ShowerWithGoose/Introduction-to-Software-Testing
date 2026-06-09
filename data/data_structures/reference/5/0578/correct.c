#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
	int an;
	int n;
	struct node *link;
};
typedef struct node *Nodeptr;
typedef struct node Node;
Nodeptr lc=NULL;
Nodeptr createlist(Nodeptr list);
void searchword(Nodeptr q);
void insertword(Nodeptr p,Nodeptr q);
int main(){
	Nodeptr la=NULL,lb=NULL;
	la=createlist(la);
	lb=createlist(lb);
	Nodeptr p,q,r;
	for(p=la;p!=NULL;p=p->link){
	 for(q=lb;q!=NULL;q=q->link){
		r=(Nodeptr)malloc(sizeof(Node));
		r->an=p->an*q->an;
		r->n=p->n+q->n;
		r->link=NULL;
		searchword(r);
	 }
	}
	for(p=lc;p!=NULL;p=p->link){
		printf("%d %d ",p->an,p->n);
	}
	return 0;
}
Nodeptr createlist(Nodeptr list)
{
	Nodeptr p=NULL,q=NULL;
	int an,n;
	char c;	
	do{
		scanf("%d%d%c",&an,&n,&c);
		q=(Nodeptr)malloc(sizeof(Node));
		q->an=an;
		q->n=n;
		q->link=NULL;
		if(list==NULL) list=p=q;
		else {
		p->link=q;
		p=p->link;
	    }
	}while(c!='\n');
	return(list);
}
void searchword(Nodeptr q){
	Nodeptr p,r=NULL;
	for(p=lc;p!=NULL||lc==NULL;r=p,p=p->link){
		if(lc==NULL){
			lc=q;
			return 0;
		}
		else if(q->n==p->n){
			p->an+=q->an;
			return 0;
		}
		else if(q->n>p->n){
			insertword(r,q);
			return 0;
		}
	}
	r->link=q;
	
}
void insertword(Nodeptr p,Nodeptr q){
	if(lc==NULL){//空链表 
		lc=q;
	}
	else if(p==NULL){//插入到头结点前  
	  q->link=lc;
	  lc=q;
    }
    else{
	  q->link=p->link;
	  p->link=q;
    }
}

