#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct leaf
{
	int number;
	int line;
	struct leaf *left,*right,*root;
};
typedef struct leaf list;
typedef struct leaf *listp;

listp head=NULL,p=NULL,q=NULL;
list put[1000];
void find(listp);
void compare(listp);
int main ()
{
	int a,headtime=0,n,i;
	scanf("%d",&n); 
	for(i=0;i<n;i++)//构造树 
	{
		scanf("%d",&a);//暂存输入的数
	 
		p=(listp)malloc(sizeof(list));
		p->root=NULL;
		p->left=NULL;
		p->right=NULL;
		p->number=a; 
		p->line=1;
		if(head==NULL)
		{
			head=p;
		}
		else
		{
			compare(head);
			
		}
	}
	find(head);
	return 0;
}
void find(listp t)
{
	if(t->left!=NULL)
	{
		find(t->left);
	}
	if(t->right!=NULL)
	{
		find(t->right);
	}
	if(t->right==NULL&&t->left==NULL)
	{
		printf("%d %d\n",t->number,t->line);
		
	}
	return;
}
void compare(listp t)
{
	if(p->number<t->number)
	{
		p->line++;
		if(t->left==NULL)
		{
			t->left=p;
			p->root=t;
		}
		else
		{
			compare(t->left);
		}
	}
	if(p->number>=t->number)
	{
		p->line++;
		if(t->right==NULL)
		{
			t->right=p;
			p->root=t;
		}
		else
		{
			compare(t->right);
		}
	}
}


