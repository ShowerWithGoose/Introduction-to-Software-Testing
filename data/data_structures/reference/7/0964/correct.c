#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct pot{
	int num,height;
	struct pot *left,*rihgt;
}; 
struct pot* insert (struct pot *root,int n,int h)
{
	struct pot *p=root;
	if(n>=root->num)
	{
		if(root->rihgt==NULL)
		{
			root->rihgt=(struct pot *)malloc(sizeof(struct pot));
			root->rihgt->left=root->rihgt->rihgt=NULL;
			root->rihgt->height=h;
			root->rihgt->num=n;
			return root;
		}
		else
		{
			root->rihgt=insert(root->rihgt,n,root->rihgt->height+1);
			return root;
		}
	}
	if(n<root->num)
	{
		if(root->left==NULL)
		{
			root->left=(struct pot *)malloc(sizeof(struct pot));
			root->left->left=root->left->rihgt=NULL;
			root->left->height=h;
			root->left->num=n;
			return root;
		}
		else
		{
			root->left=insert(root->left,n,root->left->height+1);
			return root;
		}
	}
}
void hou(struct pot *root)
{
	if(root!=NULL)
	{
		hou(root->left);
		hou(root->rihgt);
		if(root->left==NULL&&root->rihgt==NULL)
		printf("%d %d\n",root->num,root->height);
	}
}
int main()
{
	struct pot *root=NULL;
	int num,i,j=0,n;
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		scanf("%d",&n);
		if(root==NULL)
		{
			root=(struct pot *)malloc(sizeof(struct pot));
			root->left=root->rihgt=NULL;
			root->height=1;
			root->num=n;
		}
		else
		{
			root=insert(root,n,root->height+1);
		}
	}
	hou(root);
	return 0;
}



