#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int date;
	int floor;
	struct node *left,*right;
}NODE,*NODEp;
void BST(NODEp *T,int value,int floor)
{
	if(*T==NULL)
		{
			*T=(NODEp)malloc(sizeof(NODEp));
			(*T)->left=(*T)->right=NULL;
			(*T)->date=value;
			(*T)->floor=floor;
		}
	else if(value<(*T)->date)
	{
		BST(&((*T)->left),value,floor+1);
	}
	else if(value>=(*T)->date)
	{
		BST(&((*T)->right),value,floor+1);
	}
} 
void visit(NODEp T)
{
	printf("%d %d\n",T->date,T->floor);
}
void inorder(NODEp T)
{
	if(T!=NULL)
	{
		inorder(T->left);
		if(T->left==NULL&&T->right==NULL)
		visit(T);
		inorder(T->right);
	}
}
int main()
{
	NODEp T,p,q;
	NODEp root=NULL;
	int num,n,depth=1,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num);
		BST(&root,num,1);
	}
	inorder(root);
	return 0;
}

