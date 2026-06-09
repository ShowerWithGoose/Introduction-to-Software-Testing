#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node
{
	int data;
	int height;
	struct node *left;
	struct node *right;
}Tree;
typedef struct tree
{
	Tree * root;
}creat;
void insert(creat* tree,int a)
{
	Tree* p=(Tree*)malloc(sizeof(Tree));
	p->data=a;
	p->height=1;
	p->left=p->right=NULL;
	if(tree->root==NULL)
	{
		tree->root=p;
	}
	else 
	{
		Tree* q=tree->root;
		while(q!=NULL)
		{
			p->height++;
			if(a<q->data)
			{
				if(q->left==NULL)
				{
					q->left=p;
					return;
				}
				else 
					q=q->left;
			}
			else
			{
				if(q->right==NULL)
				{
					q->right=p;
					return;
				}
				else 
					q=q->right;
			}
		}
	}
}
void print(Tree* p)
{
	if(p!=NULL)
	{
		print(p->left);
		if(p->left==NULL&&p->right==NULL)
			printf("%d %d\n",p->data,p->height);
		print(p->right);
	}
}
int main()
{
	int n,m;
	creat tr;tr.root=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		insert(&tr,m);
	}
	print(tr.root);
	return 0;
}
