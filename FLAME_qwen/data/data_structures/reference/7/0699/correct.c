#include<stdio.h>
#include<stdlib.h>

struct twtree{
	int data;
	struct twtree *lchild,*rchild;
};

struct twtree *instree(struct twtree *root,int data)
{
	struct twtree*p;
	if(root==NULL)
	{
		p=(struct twtree*)malloc(sizeof(struct twtree));
		p->data=data;
		p->lchild=p->rchild=NULL;
		return p;
	}
	else if(data<root->data)
	{
		root->lchild=instree(root->lchild,data);
	}
	else root->rchild=instree(root->rchild,data);
	return root;
}//构造二叉树

void printbottom(struct twtree *root,int h)
{
	if(root->lchild!=NULL)
		printbottom(root->lchild,h+1);
	if(root->rchild!=NULL)
		printbottom(root->rchild,h+1);
	if(root->lchild==NULL&&root->rchild==NULL)
		printf("%d %d\n",root->data,h);
} //后续遍历，并且输出下层数据与高度

int main()
{
	struct twtree*root=NULL;
	int n,tmp,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		root=instree(root,tmp);	
	}
	
	printbottom(root,1);
	
	return 0;	
} 

