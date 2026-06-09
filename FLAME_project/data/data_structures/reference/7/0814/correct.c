#include <stdio.h>
#include <stdlib.h>
typedef struct tree{
	int item;
	struct tree *left,*right;
}btnode;
typedef struct tree* btnodptr;
btnodptr root=NULL;
btnodptr insert(btnodptr p,int elem)
{
	if(p==NULL)
	{
		p=(btnodptr)malloc(sizeof(btnode));
		p->item=elem;
		p->left=p->right=NULL;
	}
	else if(elem<p->item)
		p->left=insert(p->left,elem);
	else
		p->right=insert(p->right,elem);
	return p;
}
void preorder(btnodptr p,int h)
{
	if(p->left==NULL&&p->right==NULL)
	{
		printf("%d %d\n",p->item,h);
	}
	else
	{
		if(p->left!=NULL) preorder(p->left,h+1);
		if(p->right!=NULL) preorder(p->right,h+1);
	}
}
int main()
{
	int n,elem;
	scanf("%d",&n);
	int i=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&elem);
		root=insert(root,elem);
	}
//	printf("%d\n",root->item);
	preorder(root,1);
	return 0;
}

