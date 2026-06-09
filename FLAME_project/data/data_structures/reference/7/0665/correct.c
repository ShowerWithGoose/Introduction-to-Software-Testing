#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct tnode
{
	int data;
	struct tnode *lchild,*rchild;
};
struct tnode *iniNode(struct tnode *root,int num)
{
	struct tnode *p;
	if(root==NULL)
	{
		p=(struct tnode*)malloc(sizeof(struct tnode));
		p->data=num;
		p->lchild=NULL;
		p->rchild=NULL;
		return p;
	}
	else if(num<root->data)
	{
		root->lchild=iniNode(root->lchild,num); 
	}
	else
		root->rchild=iniNode(root->rchild,num);
	return root;
}
void printNode(struct tnode *root,int height)
{
	if(root->lchild!=NULL)
		printNode(root->lchild,height+1);
	if(root->rchild!=NULL)
		printNode(root->rchild,height+1);
	if(root->lchild==NULL&&root->rchild==NULL)
		printf("%d %d\n",root->data,height);
}
int main()
{
	struct tnode* root=NULL;
	int n,num,height=1;
	scanf("%d",&n);
	while(n>0)
	{
		scanf("%d",&num);
		root=iniNode(root,num);
		n--;
	}
	printNode(root,height);
	return 0;
 } 

