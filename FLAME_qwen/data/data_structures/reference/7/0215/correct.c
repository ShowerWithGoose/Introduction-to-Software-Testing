#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef struct btnode_{
	int data1,data2;
	struct btnode_ *lchild,*rchild,*parent;
}btnode;
btnode *treetop;
void creattree();
void inorder(btnode *ntr);

int main()  
{
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++) creattree();
  inorder(treetop); 
  return 0; 
} 

void creattree()
{
	int temp;
	btnode *p,*q;
	q=treetop;
	p=(btnode*)malloc(sizeof(btnode));
	scanf("%d",&p->data1);p->data2=1;
	p->lchild=NULL;p->rchild=NULL;p->parent=NULL;	
	if(treetop==NULL)
	{
	  treetop=p;
	  return ;	
	}
	while(q!=NULL)
	{
		(p->data2)++;
		p->parent=q;
		if((p->data1)<(q->data1)) q=q->lchild;
		  else q=q->rchild;
	}
	if((p->data1)<(p->parent->data1)) p->parent->lchild=p;
	  else  p->parent->rchild=p;	
}

void inorder(btnode* topntr)
{
	btnode *stack[1000],*p;
	int stacktop=-1;
	p=topntr;
	if(treetop!=NULL)
	 {
	 	do 
		 {
	 		for(;p!=NULL;p=p->lchild)
	 		{
	 			stack[++stacktop]=p;
			 }
			p=stack[stacktop--];
			{
				if((p->lchild==NULL)&&(p->rchild==NULL)) printf("%d %d\n",p->data1,p->data2);
			}
			p=p->rchild;
		 }while((p!=NULL)||(stacktop!=-1));
	 }
	
}

