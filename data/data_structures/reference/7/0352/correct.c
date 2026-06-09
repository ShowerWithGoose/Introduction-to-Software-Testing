#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>
typedef struct shu
{
	int num;
	int ceng;
	struct shu *left;
	struct shu *right;
}tree;
tree *creat(int num0)
{
	tree *node=(tree *)malloc(sizeof(tree *));
	node->num=num0;
	node->left=NULL;
	node->right=NULL;
	return node;
}
void insert(tree *tem,tree *gen)
{
	if(tem->num>=gen->num&&(gen->right==NULL))
	{
		tem->right=gen->right;
		gen->right=tem;
	}
	else if(tem->num<gen->num&&(gen->left==NULL))
	{
		tem->left=gen->left;
		gen->left=tem;
	}
	else if(tem->num>=gen->num)
	{
		insert(tem,gen->right);
	}
	else
		insert(tem,gen->left);
	
}
void visit(tree *gen,int ceng)
{
	ceng++;
	if(gen->left)
		visit(gen->left,ceng);
	if(gen->right)
		visit(gen->right,ceng);
	if(gen->left==NULL&&gen->right==NULL)
		printf("%d %d\n",gen->num,ceng);
}
int main()
{
	int i,n;
	scanf("%d",&n);
	int m;
	scanf("%d",&m);
	tree *root=creat(m);
	for(i=1;i<n;i++)
	{
		scanf("%d",&m);
		tree *t=creat(m);
		insert(t,root);
	}
	visit(root,0);
	return 0;
}


