#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

struct tree{
	int num;
	struct tree *left,*right;
};
struct tree *root=NULL;

struct tree* createtree(struct tree *p,int data)
{
	if(p==NULL)
	{
		p=(struct tree *)malloc(sizeof(struct tree));
		p->num=data;
		p->left=NULL;
		p->right=NULL;
	}
	else
	{
		if(p->num>data)
		p->left=createtree(p->left,data);
		if(p->num<=data)
		p->right=createtree(p->right,data);
	}
	return p;
}

void print(struct tree *p,int height)
{
	if(p->left==NULL&&p->right==NULL)
	{
		printf("%d %d\n",p->num,height);
		return;
	}
	if(p->left!=NULL)
	print(p->left,height+1);
	if(p->right!=NULL)
	print(p->right,height+1);
	if(p==NULL)
	return; 
}

int main()
{
//	root=(struct tree *)malloc(sizeof(struct tree));
	int n,i,data;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		root=createtree(root,data);//p是形参，若没有返回值的作用，root一直为NULL 
	}
	print(root,1);
	return 0;
}

