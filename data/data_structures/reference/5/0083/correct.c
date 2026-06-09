#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

struct node{
	int xi;
	int ci;
	struct node *link; 
};
typedef struct node *Nodeptr;
typedef struct node Node;
Nodeptr createList()
{
	Nodeptr p=NULL,q=NULL,list=NULL;
	int x=0,c=0;
	do{
		scanf("%d %d",&x,&c);
		q=(Nodeptr)malloc(sizeof(Node));
		q->xi=x;
		q->ci=c;
		q->link=NULL;
		if(list==NULL)
		list=p=q;
		else
		p->link=q;
		p=q;
	}while(getchar()!='\n');
	return list;
}
Nodeptr ssort(Nodeptr list,Nodeptr end)
{
	Nodeptr p=list;
	if(list->link==end)return list;
	int tem,tep,con=0;
	while(p->link!=end){
		if(p->ci<p->link->ci){
			tem=p->link->ci;
			tep=p->link->xi;
			p->link->ci=p->ci;
			p->link->xi=p->xi;
			p->ci=tem;
			p->xi=tep;
			p=p->link;
			con++;
		}
		else p=p->link;
	}
	end=p;
	if(con==0)return list;
	else list=ssort(list,end);
	return list;
}
int main()
{
	Nodeptr list1,list2,p1,p2;
	Nodeptr list=NULL,p,q;
	list1=createList();
	list2=createList();
	p1=list1;p2=list2;
	while(p1!=NULL){
		p2=list2;
		while(p2!=NULL){
			q=(Nodeptr)malloc(sizeof(Node));
			q->link=NULL;
			q->xi=p1->xi*p2->xi;
			q->ci=p1->ci+p2->ci;
			if(list==NULL)
		    list=p=q;
		    else
		    p->link=q;
	    	p=q;
	    	p2=p2->link;
		}
		p1=p1->link;
	}
	list=ssort(list,NULL);
	p=list;
	while(p->link!=NULL){
		if(p->ci==p->link->ci){
			p->xi+=p->link->xi;
			p->link=p->link->link;
		}
		else p=p->link;
	}
	for(p=list;p!=NULL;p=p->link){
		printf("%d %d ",p->xi,p->ci);
	}
	return 0;
}

