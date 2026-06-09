#include<stdio.h>
#include<malloc.h>
typedef struct BSTree
{
	int data;
	int depth;
	struct BSTree* left;
	struct BSTree* right;
}BSTree;
void insert(BSTree* root,BSTree* node)
{
	BSTree *p=root;
	while(1)
	{
		if(node->data<p->data)
		{
			if(p->left==NULL)
			{
				p->left=node;
				break;
			}
			else
			{
				p=p->left;
				node->depth++;
			}
		}
		else
		{
			if(p->right==NULL)
			{
				p->right=node;
				break;
			}
			else
			{
				p=p->right;
				node->depth++;
			}
		}
	}
}
void findleaf(BSTree *root)
{
	BSTree *t=root;
	if(t)
	{
		if(t->left==NULL&&t->right==NULL)
		{
			printf("%d %d\n",t->data,t->depth+1);
		}
		findleaf(t->left);
		findleaf(t->right);
	}
}
int main()
{
	int n=0;
	scanf("%d",&n);
	BSTree *root=(BSTree*)malloc(sizeof(BSTree));
	root->left=NULL;
	root->right=NULL;
	scanf("%d",&root->data);
	for(int i=1;i<=n-1;i++)
	{
		BSTree *node=(BSTree*)malloc(sizeof(BSTree));
		scanf("%d",&node->data);
		node->depth=1;
		node->left=NULL;
		node->right=NULL;
		insert(root,node);
    } 
	findleaf(root);
	return 0;
}


