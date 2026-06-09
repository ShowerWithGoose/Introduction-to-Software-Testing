#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
int n,num[999],i,length;
typedef struct Node{
	int data;
	int degree;
	struct node *lchild;
	struct node *rchild;
}TREE,*pTREE;
pTREE t;
pTREE buildtree(pTREE T,int tem,int length)
{
	length++;
	if(T==NULL)
	{
		T=(pTREE)malloc(sizeof(TREE));
		T->data=tem;
		T->degree=length;
		T->lchild=T->rchild=NULL;
	}
	else if(tem<T->data)
	{
		T->lchild=buildtree(T->lchild,tem,length);
	}
	else if(tem>=T->data)
	{
		T->rchild=buildtree(T->rchild,tem,length);
	}
	return T;
}
void putout(pTREE T)
{
	if(T==NULL)
		return 0;
	if(T->lchild==NULL&&T->rchild==NULL)
		printf("%d %d\n",T->data,T->degree);
	putout(T->lchild);
	putout(T->rchild);
}
int seek(int x)
{
	return x;
}
int main()
{
	scanf("%d",&n);
	seek(n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num[i]);
		length=0;
		t=buildtree(t,num[i],length);
	}
	putout(t);
	return 0;
}


