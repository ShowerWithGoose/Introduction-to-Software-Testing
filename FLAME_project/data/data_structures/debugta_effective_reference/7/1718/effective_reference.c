#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	int num;
	struct node *lchild;
	struct node *rchild;
}node;
node *head=NULL,*q;
void findc(int m)
{
	node *p;
	p=(node *)malloc(sizeof(node));
	p->num=m;
	p->lchild=NULL;
	p->rchild=NULL;
	q=head;
	while(1)
	{
		if(p->num<q->num)
		{if(q->lchild!=NULL)
		q=q->lchild;
		else 
		{
		q->lchild=p;
		break;}
		}
		else 
		{if(q->rchild!=NULL)
		q=q->rchild;
		else 
		{
		q->rchild=p;
		break;}
		}
	}
}
void perorder(node *t,int h)
 {
 	h++;
 	if(t!=NULL)
 	{
 		if(t->lchild==NULL&&t->rchild==NULL)
 		printf("%d %d\n",t->num,h);
 		perorder(t->lchild,h);
 		
 		perorder(t->rchild,h);
 	
	 }
 }
 void f(node *t)
 {
 	if(t!=NULL){
             f(t->lchild);
             f(t->rchild);
             free(t);      
      }
 }
 
int main()
{
int n;
int h=0;
scanf("%d",&n);
int i,m;
for(i=0;i<n;i++)
{
	scanf("%d",&m);
	if(head==NULL)
	{
	node *p=(node *)malloc(sizeof(node));
	p->num=m;
	p->lchild=NULL;
	p->rchild=NULL;
	head=p;
	}
	else
	{
		findc(m);
	}
}
q=head;
while(q!=NULL)
{
q=q->lchild;
}
perorder(head,h);
f(head);
return 0;
}


