#include<stdio.h>
#include<stdlib.h>

typedef struct str{
	int n;
	struct str* left;
	struct str* right;
}node,*pnode; 

pnode bgnln(int core)
{
	pnode H=(pnode)malloc(sizeof(node));
	H->n=core;
	H->left=NULL;
	H->right=NULL;
	return H;
}

void fup(pnode root,int a)
{
	if(root->n>a)
	{
		if(root->left==NULL)
		{
			root->left=(pnode)malloc(sizeof(node));
			root->left->n=a;
			root->left->left=root->left->right=NULL;
			return ;
		}
		else 
		{
			fup(root->left,a);
		}
	} 
	else
	{
		if(root->right==NULL)
		{
			root->right=(pnode)malloc(sizeof(node));
			root->right->n=a;
			root->right->left=root->right->right=NULL;
			return ;
		}
		else 
		{
			fup(root->right,a);
		}
	}
}

pnode p;

void find(pnode H,int depth)
{
	
	if(H->left!=NULL)
	{
		find(H->left,depth+1);
	 } 
	if(H->right!=NULL)
	{
		find(H->right,depth+1);
	}
	if(H->left==NULL&&H->right==NULL)
	{
	 	printf("%d %d\n",H->n,depth);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int core;
	scanf("%d",&core);
	pnode H=bgnln(core);
	for(int i=1;i<n;i++)
	{
		scanf("%d",&core);
		fup(H,core);
	}
	p=H;
	find(p,1);
	return 0;
}

