#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
typedef struct node{
	int num,height;
	struct node *left,*right;
}Bst;
Bst *create(Bst *p,int num,int height)
{
	if(p==NULL)
	{
		p=(Bst*)malloc(sizeof(Bst));
		p->num=num;
		p->height=height;
		p->left=p->right=NULL;
	}
	else if(num<p->num)
		p->left=create(p->left,num,height+1);
	else
		p->right=create(p->right,num,height+1);
	return p;
}
void inorder(Bst *p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		inorder(p->right);
		if(p->left==NULL&&p->right==NULL)
			printf("%d %d\n",p->num,p->height);
	}
}
int main()
{
	int N,num;
	Bst *root=NULL;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&num);
		root=create(root,num,1);
	}
	inorder(root);
	return 0;
}

