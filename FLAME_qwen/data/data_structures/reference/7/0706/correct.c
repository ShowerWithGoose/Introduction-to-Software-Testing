#include<stdio.h>
#include<stdlib.h>
struct BstNode{
	int data;
	struct BstNode *lchild,*rchild;
}; 
struct BstNode *insertroot(struct BstNode *root,int data)
{
	struct BstNode *p;
	if(root==NULL)
	{
		p=(struct BstNode*)malloc(sizeof(struct BstNode));
		p->data=data;
		p->lchild=NULL;
		p->rchild=NULL;
		return p;
	}
	else if(data<root->data)
	root->lchild=insertroot(root->lchild,data);
	else if(data>=root->data)
	root->rchild=insertroot(root->rchild,data);
	return root;
}
void printleaf(struct BstNode *root,int height)
{
	if(root->lchild!=NULL)
	printleaf(root->lchild,height+1);
	if(root->rchild!=NULL)
	printleaf(root->rchild,height+1);
	if(root->lchild==NULL&&root->rchild==NULL)
	printf("%d %d\n\n",root->data,height);
}
int main()
{
	struct BstNode *root;
	root=NULL;
	int n,data,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		root=insertroot(root,data);
	}
	printleaf(root,1);
	return 0;
} 

