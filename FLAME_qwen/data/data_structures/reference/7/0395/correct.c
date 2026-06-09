#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
struct node{
	int num;
	struct node *lchild;
	struct node *rchild;
	int height;
	
};
typedef struct node btnode;
typedef struct node *btptr;

btptr root = NULL;
 void insert(int n);
  void preorder(btptr t);
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		int item;
		scanf("%d",&item);
		insert(item);
	
	}
		preorder(root);
	return 0;
 } 
 
 void insert(int n)
 {
 	btptr p,q;
 	p = (btptr)malloc(sizeof(btnode));
 	p->num = n;
 	p->lchild=NULL;
 	p->rchild = NULL;
 	p->height = 1;
 	if(root == NULL)
 	{
 		root = p;
 		return;
	 }
 	q = root;
 	while(1)
 	{
 		p->height ++;
 		if(n < q->num)
 		{
 			
 			if(q->lchild == NULL)
 			{
 				q->lchild = p;
 				break;
			 }
 			else
 			{
 				q = q->lchild;	
			 }
		 }
 		else if(n >= q->num)
 		{
 			if(q->rchild == NULL)
 			{
 				q->rchild = p;
 				break;
			 }
			 else
			 {
			 	q = q->rchild;
			 	
			 }
 			
		 }
	 }
 }
 
 void preorder(btptr t)
 {
 	btptr stack[100], p = t;
 	int top = -1;
 	if(t != NULL)
 	{
 		do{
 			for(;p!=NULL;p=p->lchild)
 				stack[++top] = p;
 			p = stack[top--];
 			if(p->lchild == NULL && p->rchild == NULL)
 			{
 				printf("%d %d\n",p->num,p->height);
			 }
			p = p->rchild;
		 }while(!(p == NULL && top == -1));
 		
	 }
 	
 }



