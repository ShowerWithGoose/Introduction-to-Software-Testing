#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<malloc.h>
#define ll long long
#define MAXSIZE 1000
typedef int ElemType ;
typedef struct node
{
	ElemType data,depth;
	struct node *right,*left;
}BTNode,*BTNodeptr;
BTNodeptr insertBST(int item,BTNodeptr t)
{
	if(t!=NULL)
	{
		if(item<t->data)
		{
			t->left=insertBST(item,t->left);	
		}
		else 
		{
			t->right=insertBST(item,t->right);
		}
	}
	else
	{
		BTNodeptr p=(BTNodeptr)malloc(sizeof(BTNode));
		p->data=item;p->depth=1;p->left=NULL;p->right=NULL;
		return p;
	}
	return t;
}
void preorder(BTNodeptr t)
{
	if(t->left==NULL&&t->right==NULL)printf("%d %d\n",t->data,t->depth);
	else
	{
		if(t->left!=NULL)
		{
			(t->left)->depth=t->depth+1;preorder(t->left);
		}
		if(t->right!=NULL)
		{
		(t->right)->depth=t->depth+1;preorder(t->right);	
		}
	}
	return ;
}
int main()
{
	int n,i,item;
	BTNodeptr root=NULL;
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&item);
		root=insertBST(item,root);
	}
	preorder(root);
	return 0;
}


