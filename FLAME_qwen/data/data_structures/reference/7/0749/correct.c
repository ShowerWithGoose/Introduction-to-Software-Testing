#include<stdio.h>
#include<stdlib.h>
typedef struct treenode
{
	int data;
	struct node *right;
	struct node *left;
}*Tree;
Tree insert(Tree L,int a)
{
	Tree p=(Tree)malloc(sizeof(struct treenode));
	p->data=a;
	p->left=p->right=NULL;
	if(L==NULL)
	{
		L=p;
		return L;
	}
	if(a<L->data)
	{
		L->left=insert(L->left,a);
	}
	else
	L->right=insert(L->right,a);
	
	return L;
}
void preorder(Tree L,int h)
{
	Tree p=L;
	if(p==NULL) return;
	if(p->left==NULL&&p->right==NULL)
	printf("%d %d\n",p->data,h);
	if(p->left!=NULL)
		preorder(p->left,h+1);
	if(p->right!=NULL)
		preorder(p->right,h+1);
	return;
}
int main()
{
	int n,a;
	Tree head=NULL;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		head=insert(head,a);
	}
	preorder(head,1);
	return 0;
}

