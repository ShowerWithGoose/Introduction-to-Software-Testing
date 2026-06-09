#include <stdio.h>
#include <stdlib.h>

typedef struct tree 
{
	int num;
	struct tree *l;
	struct tree *r;
}node;

node *input(node *root,int k);
void output(node *root,int heigh);

int main()
{
	int n = 0;
	int k = 0;
	node *root = NULL;
	scanf("%d", &n);
	for(int i = 0; i<n; i++) 
	{
		scanf("%d", &k);
		root = input(root,k);
	}
	output(root,1);
	return 0;	
} 

node *input(node *root,int k)
{
	if(root==NULL)
	{
		root = (node*)malloc(sizeof(node));
		root->num = k;
		root->l = NULL;
		root->r= NULL; 
	}
	else if(root->num>k)
	{
		root->l = input(root->l,k);
	}
	else if(root->num<=k)
	{
		root->r = input(root->r,k);
	}
	return root;
}

void output(node *root,int heigh)
{
	int k = heigh;
	k++;
	if (root->l!=NULL)
		output(root->l,k);
	if  (root->r!=NULL)
		output(root->r,k);
	if(root->l==NULL&&root->r==NULL)
		printf("%d %d\n", root->num, heigh);
}



