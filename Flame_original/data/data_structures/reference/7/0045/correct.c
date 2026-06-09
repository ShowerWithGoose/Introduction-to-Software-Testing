#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
struct node{
	int data;
	int depth;
	struct node *left,*right;
};
typedef struct node *Nd;
typedef struct node nd;
Nd tree;

int t;

void Tre(Nd root){
	if(root->data>t)
	{
		if(root->left==NULL)
		{
			Nd trs;
			trs=(Nd)malloc(sizeof(nd));
			trs->data=t;
			trs->left=NULL;
			trs->right=NULL;
			trs->depth=root->depth+1;
			root->left=trs;
			return;
		}
		else root=root->left;
	}
	else
	{
		if(root->right==NULL)
		{
			Nd trs;
			trs=(Nd)malloc(sizeof(nd));
			trs->data=t;
			trs->left=NULL;
			trs->right=NULL;
			trs->depth=root->depth+1;
			root->right=trs;
			return;
		}
		else root=root->right;
	}
	Tre(root);
}
void bltre(Nd root){
	if(root!=NULL)
	{
		if(root->left==NULL&&root->right==NULL) printf("%d %d\n",root->data,root->depth);
		else
		{
			bltre(root->left);
			bltre(root->right);
		}
	}
	return;
}
int main()
{
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		if(i==0){
			tree=(Nd)malloc(sizeof(nd));
			tree->data=t;
			tree->left=NULL;
			tree->right=NULL;
			tree->depth=1;
		}
		else{
			Tre(tree);
		}
	}
	bltre(tree);
}



