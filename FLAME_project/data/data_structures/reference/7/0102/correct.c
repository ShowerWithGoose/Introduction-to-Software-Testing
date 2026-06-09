#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct node{
	int data;
	struct node * lchild,* rchild;
}* btree,btnode;
int n,a[10005];	
btree T=NULL;
void addtree(btree * T,int a);
void read()
{
	int i;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		addtree(&T,a[i]);
	}
}
void addtree(btree * T,int a)
{
	if ((*T)==NULL)
	{
		(*T)=(btree)malloc(sizeof(btnode));
		(*T)->data=a;
		(*T)->lchild=NULL;
		(*T)->rchild=NULL;
	}
	else if (a<(*T)->data)
	{
		addtree(&((*T)->lchild),a);
	}
	else
	{
		addtree(&((*T)->rchild),a);
	}
}
void searching(btree * T,int depth)
{
	btree p=*T;
	if (!(p->lchild==NULL&&p->rchild==NULL))
	{
		if (p->lchild!=NULL)
		{
			searching(&(p->lchild),depth+1);
		}
		if (p->rchild!=NULL)
		{
			searching(&(p->rchild),depth+1);
		}
	}
	else
	{
		printf("%d %d\n",p->data,depth);
		return;
	}
}
int main()
{
	read();
	searching(&T,1);
}

