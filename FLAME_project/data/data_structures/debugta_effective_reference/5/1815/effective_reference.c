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
	Nodeptr p=NULL,q=NULL,ans=NULL;
	int a=0,b=0;
	do{
		scanf("%d %d",&a,&b);
		q=(Nodeptr)malloc(sizeof(Node));
		q->xi=a;
		q->ci=b;
		q->link=NULL;
		if(ans==NULL)
		ans=p=q;
		else
		p->link=q;
		p=q;
	}while(getchar()!='\n');
	return ans;
}
Nodeptr ssort(Nodeptr ans,Nodeptr end)
{
	Nodeptr p=ans;
	if(ans->link==end)return ans;
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
	if(con==0)return ans;
	else ans=ssort(ans,end);
	return ans;
}
int main()
{
	Nodeptr Nodeptr1,Nodeptr2,p1,p2;
	Nodeptr ans=NULL,p,q;
	Nodeptr1=createList();
	Nodeptr2=createList();
	p1=Nodeptr1;p2=Nodeptr2;
	while(p1!=NULL){
		p2=Nodeptr2;
		while(p2!=NULL){
			q=(Nodeptr)malloc(sizeof(Node));
			q->link=NULL;
			q->xi=p1->xi*p2->xi;
			q->ci=p1->ci+p2->ci;
			if(ans==NULL)
		    ans=p=q;
		    else
		    p->link=q;
	    	p=q;
	    	p2=p2->link;
		}
		p1=p1->link;
	}
	ans=ssort(ans,NULL);
	p=ans;
	while(p->link!=NULL){
		if(p->ci==p->link->ci){
			p->xi+=p->link->xi;
			p->link=p->link->link;
		}
		else p=p->link;
	}
	for(p=ans;p!=NULL;p=p->link){
		printf("%d %d ",p->xi,p->ci);
	}
	return 0;
}

