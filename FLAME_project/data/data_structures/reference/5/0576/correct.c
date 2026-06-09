#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node{
	int coe;
	int pow;
	struct node* link;
}*q,*list=NULL;
struct node* insert(struct node* list,int,int);

int main ()
{
	int a,b,c;
	struct node *list1=NULL,*p;
	do{
		scanf("%d%d%c",&a,&b,&c);
		q=(struct node*)malloc(sizeof(struct node));
		q->coe =a;
		q->pow =b;
		q->link =NULL;
		if(list1==NULL)
			list1=p=q;
		else {
			p->link =q;
			p=p->link ;
		}	
	}while(c!='\n');
	
	do{
		scanf("%d%d%c",&a,&b,&c);
		for(p=list1;p!=NULL;p=p->link ){
			q=(struct node*)malloc(sizeof(struct node));
			q->coe =a*p->coe ;
			q->pow =b+p->pow ;
			q->link =NULL;
			list=insert(list,q->coe ,q->pow );
		}
	}while(c!='\n');
	
	for(p=list;p!=NULL;p=p->link ){
		printf("%d %d ",p->coe ,p->pow );
	}
}

struct node* insert(struct node* list,int a,int b){
	struct node *p1=NULL,*p=NULL,*q;
	q=(struct node*)malloc(sizeof(struct node));
	q->coe =a;
	q->pow =b;
	q->link =NULL;
	int flag=0;
	if(list==NULL)
		list=p=p1=q;
	else {
		for(p1=p=list;p!=NULL;p1=p,p=p->link ){
			if(p->pow >q->pow ) 
				continue;
			else if(p->pow==q->pow){
				p->coe +=q->coe ;
				flag=1;
				break;
			}
			else {
				q->link =p;
				p1->link=q;
				flag=1;
				break;
			}
		}
		if(!flag){
			p1->link=q;
		}
	}
	return list;
}
