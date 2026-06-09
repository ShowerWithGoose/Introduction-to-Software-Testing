#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#define ll long long
struct TreeNode
{
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
	int depth;
};
struct TreeNode* root=NULL;

void insert(int num)
{
	struct TreeNode *p,*q;
	p=(struct TreeNode*) malloc(sizeof(struct TreeNode));
	p->val=num;
	p->left=NULL;
	p->right=NULL;
	if(root==NULL) 
	{
		root=p;
		p->depth=1;
	}
	else
	{
		q=root;
		while(1)
		{
			if(num<q->val)
			{
				if(q->left==NULL)
				{
					q->left=p;
					q->left->depth=(q->depth)+1;
					break;
				}
				else q=q->left;
			}
			else if(num>=q->val)
			{
				if(q->right==NULL)
				{
					q->right=p;
					q->right->depth=(q->depth)+1;
					break;
				}
				else q=q->right;
			} 
		}
	}
}

void inorder(struct TreeNode* t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		if(t->left==NULL&&t->right==NULL) printf("%d %d\n",t->val,t->depth);
		inorder(t->right);
	}
}

int main()
{
	int n,i,item;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&item);
		insert(item);
	}
	inorder(root);
	return 0;	
}

