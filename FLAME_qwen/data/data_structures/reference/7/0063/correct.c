#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#define int eletype;

typedef struct node
{
	struct node *lchild;
//	eletype data;
	int data;
	int high;
	struct node *rchild;
}tree;

tree *new(tree *p,int temp,int depth)
{
	depth++;
	if(p==NULL)
	{
		p=(tree*)malloc(sizeof(tree));
		p->lchild=NULL;
		p->rchild=NULL;
		p->data=temp;
		p->high=depth;
	}
	else if(temp<p->data)
		p->lchild=new(p->lchild,temp,depth);
	else if(temp>=p->data)
		p->rchild=new(p->rchild,temp,depth);
	return p;     //嵌套时，最后一个return p连接新区域与树 
}

void print(tree* root)
{
	if(root==NULL)
		return;
	if(root->lchild==NULL&&root->rchild==NULL)
		printf("%d %d\n",root->data,root->high);
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
	int a,n,i,high=0;
//	char lj[5];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		high=0;
		root=new(root,a,high);
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

