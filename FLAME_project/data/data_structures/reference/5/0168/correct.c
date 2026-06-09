#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h> 
typedef struct node
{
	int num;
	int ind;
	struct node *link;
}Node,*Nodeptr;
Nodeptr insert(Nodeptr head, int num, int ind)
{
	Nodeptr p=head,q=NULL,r=NULL;
	r=(Nodeptr)malloc(sizeof(Node));
	r->num=num;
	r->ind=ind;
	r->link=NULL;
	if(head==NULL)
	return r;
	for(p=head;p!=NULL&&p->ind>ind;q=p,p=p->link);
	
	if(p!=NULL&&p->ind==ind)
	p->num+=num;
	else if(p==head)
	{
		r->link=p;
		return r;
	}
	else 
	{
		q->link=r;
		r->link=p;
	}
	return head;
}
int print(Nodeptr head)
{
	Nodeptr p;
	if(head==NULL)
	return 0; 
	for(p=head;p!=NULL;p=p->link)
	{
		printf("%d ",p->num);
		printf("%d ",p->ind);
	}
	return 1;
}
int main()
{
	Nodeptr lin=NULL,flag=NULL,p=NULL;
	int num,ind,tmp=2000000000;
	while((scanf("%d%d",&num,&ind))!=EOF)
	{
		if(tmp<=ind)
		{
			for(p=lin;p!=NULL;p=p->link)
			flag=insert(flag,(p->num)*num,(p->ind)+ind);
			break;
		}
		lin=insert(lin,num,ind);
		tmp=ind;
	}
	while((scanf("%d%d",&num,&ind))!=EOF)
	{
		Nodeptr q=NULL;
		for(q=lin;q!=NULL;q=q->link)
		flag=insert(flag, num*q->num,ind+q->ind);
	}
	print(flag);
	return 0;
 } 


