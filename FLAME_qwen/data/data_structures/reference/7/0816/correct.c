#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
struct node
{
	int num;
	int depth;
	struct node *right;
	struct node *left;
};
struct node *BTNodeptr;
struct node* insertBST(struct node* p,int item,int depth)
{
	if(p==NULL){
		p=(struct node*)malloc(sizeof(struct node*));
		p->num=item;
		p->depth=depth;
		p->left=p->right=NULL;
	}
	else if(item<p->num)
	{
		p->left=insertBST(p->left,item,depth+1);
	}
	else if(item>=p->num )
	{
		p->right=insertBST(p->right,item,depth+1);
	}
	return p;
}
void inorder(struct node*t)
{
	if(t!=NULL){
		inorder(t->left);
		if(t->left==NULL&&t->right==NULL)
		printf("%d %d\n",t->num,t->depth);
		inorder(t->right);
	}
}
int main()
{
	int n,item;
	scanf("%d",&n);
	BTNodeptr=NULL;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&item);
		BTNodeptr=insertBST(BTNodeptr,item,1);
	}
	inorder(BTNodeptr);
	return 0;
}



