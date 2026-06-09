#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct tnode
{
	int data;
	struct tnode *lchild,*rchild;
};
struct tnode *iniNode(struct tnode *root,int a)
{
	struct tnode *p;
	if(root==NULL)
	{
		p=(struct tnode*)malloc(sizeof(struct tnode));
		p->data=a;
		p->lchild=NULL;
		p->rchild=NULL;
		return p;
	}
	else if(a<root->data)
	{
		root->lchild=iniNode(root->lchild,a); 
	}
	else
		root->rchild=iniNode(root->rchild,a);
	return root;
}
void printNode(struct tnode *root,int tall)
{
	if(root->lchild!=NULL)
		printNode(root->lchild,tall+1);
	if(root->rchild!=NULL)
		printNode(root->rchild,tall+1);
	if(root->lchild==NULL&&root->rchild==NULL)
		printf("%d %d\n",root->data,tall);
}
int main()
{
	struct tnode* root=NULL;
	int n,a,tall=1;
	scanf("%d",&n);
	while(n>0)
	{
		scanf("%d",&a);
		root=iniNode(root,a);
		n--;
	}
	printNode(root,tall);
	return 0;
 } 

