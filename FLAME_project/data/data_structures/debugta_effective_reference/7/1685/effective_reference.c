#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#define int eletype;

typedef struct node
{
	struct node *lchild;
//	eletype data;
	int data;
	int depth;
	struct node *rchild;
}tree;

tree *new(tree *root,int a,int depth)
{
	depth++;
	if(root==NULL)
	{
		root=(tree*)malloc(sizeof(tree));
		root->lchild=NULL;
		root->rchild=NULL;
		root->data=a;
		root->depth=depth;
	}
	else if(a<root->data)
		root->lchild=new(root->lchild,a,depth);
	else if(a>=root->data)
		root->rchild=new(root->rchild,a,depth);
	return root;     //嵌套时，最后一个return p连接新区域与树 
}

void print(tree* root)
{
	if(root==NULL)
		return;
	if(root->lchild==NULL&&root->rchild==NULL)
		printf("%d %d\n",root->data,root->depth);
	else 
	{
		print(root->lchild);
		print(root->rchild); 
	}
}
/*int GetLeafNodeNum(struct tree * root)
{
    if(root== NULL)
        return 0;
    if(root->lchild== NULL && root->rchild== NULL)
        return 1;
    return GetLeafNodeNum(root->lchild) + GetLeafNodeNum(root->rchild);
}*/


int main()
{
	tree *root=NULL;
	int a,n,i,depth=0;
//	char lj[5];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		depth=0;
		root=new(root,a,depth);
	}
	print(root);
/*	p=(tree*)malloc(sizeof(tree));
	p->data=a;
	p->high=1;
	root=p;
	for(i=1;i<n;i++)
	{
		scanf("%d",&a);
		q=(tree*)malloc(sizeof(tree));
		q->data=a;
		while(1)                                  //查找应该插入的位置 
		{
			if(q->data<p->data)
			{
				//p->lchild=q;
				if(p->lchild!=NULL)
					p=p->lchild;
				else
				{
					p->lchild=q;
					break;
				}
			}
			else if(q->data>=p->data)
			{
				//p->rchild=q;
				if(p->rchild!=NULL)
					p=p->rchild;
				else
				{
					p->rchild=q;
					break;
				}
			}
		}
		p=root;                  					//p指针回到初始位置 
	}*/
//	depth=GetLeafNodeNum(head);
//	printf("%d",depth);
/*	for(i=0;i<n;i++)
		printf("%d",a[i]);*/
//	printf("%d",root->rchild);
	return 0;
}

