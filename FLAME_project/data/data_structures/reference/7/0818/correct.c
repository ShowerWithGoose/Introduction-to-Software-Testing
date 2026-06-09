#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct tree{
	struct tree *left, *right;
	int num;
} bst;
int deep=0;
struct tree *bstinsert(struct tree *root, int temp);
void bstindex(struct tree *p);
int main(void)
{
	int i,j,temp,n;
	struct tree *root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		root=bstinsert(root,temp);
	}
	bstindex(root);
	return 0;
}

struct tree* bstinsert(struct tree *p, int temp)
{
	if(p==NULL)
	{
		p=(struct tree*)malloc(sizeof(struct tree));
		p->left=NULL;
		p->right=NULL;
		p->num=temp;
//		printf("%d\n",temp);
	}
	else if(temp<p->num)
	{
		p->left=bstinsert(p->left,temp);
	}
	else
		p->right=bstinsert(p->right,temp);

	return p;
} 

void bstindex(struct tree *p)
{
	deep++;
	if(p->left!=NULL)
		bstindex(p->left); 
	if(p->right!=NULL)
		bstindex(p->right); 
	if(p->left==NULL&&p->right==NULL) printf("%d %d\n",p->num,deep);
	deep--;	
}

