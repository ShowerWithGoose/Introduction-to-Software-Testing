#include<stdio.h>
#include<stdlib.h>
struct node{
	int val;
	struct node*ltree;
	struct node*rtree;
};
struct node* Insert(int num,struct node*tree)
{
	struct node*p;
	if(tree==NULL)
	{
		tree=(struct node*)malloc(sizeof(struct node));
		tree->val=num;
		tree->ltree=NULL;
		tree->rtree=NULL; 
	}
	else if(num<tree->val)
	{
		tree->ltree=Insert(num,tree->ltree);
	}
	else
	{
		tree->rtree=Insert(num,tree->rtree);
	}
	return tree;	
}
void InOrder(struct node*tree,int layer)//layer¼ÇÂ¼µÝ¹é²ãÊý 
{
	if(tree!=NULL)
	{
		InOrder(tree->ltree,layer+1);
	if(tree->ltree==NULL&&tree->rtree==NULL)
	{
		printf("%d %d\n",tree->val,layer); 
	}
		InOrder(tree->rtree,layer+1);
	}

}

int main()
{
	int i;
	int n;
	int num;
	scanf("%d",&n);
	struct node*root=NULL;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num);
		root=Insert(num,root);
	}
	InOrder(root,1);
	return 0;
}
/*
void InOrder(struct node*tree,int layer)//layer¼ÇÂ¼µÝ¹é²ãÊý 
{
	if(tree->ltree==NULL&&tree->rtree==NULL)
	{
		printf("%d %d\n",tree->val,layer); 
	}
	else
	{
	if(tree->ltree!=NULL)
		InOrder(tree->ltree,layer+1);
	if(tree->rtree!=NULL)
		InOrder(tree->rtree,layer+1);
		
	}
}
*/ 

