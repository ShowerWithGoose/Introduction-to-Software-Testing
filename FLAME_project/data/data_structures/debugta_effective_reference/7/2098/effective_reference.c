#include<stdio.h>
#include<stdlib.h>
struct node
{
	int num;
	struct node *left,*right;
};
typedef struct node BTNode,*BTNodeptr;
BTNodeptr insert(BTNodeptr p,int n)
{
	if(p==NULL)
	{
		p=(BTNodeptr)malloc(sizeof(BTNode));
		p->num=n;
		p->left=p->right=NULL;
	}
	else if(n<p->num)
	{
		p->left=insert(p->left,n);
	}
	else
	{
		p->right=insert(p->right,n);
	}
	return p;
}
void printleaf(BTNodeptr root,int h)
{
	if(root!=NULL)
	{
		if(root->left==NULL&&root->right==NULL)
		{
			printf("%d %d\n",root->num,h);
		}
		else
		{
			BTNodeptr p=root;
			printleaf(p->left,h+1);
			printleaf(p->right,h+1);
		} 	
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int tmp;
	BTNodeptr root=NULL;
	while(n--)
	{
		scanf("%d",&tmp);
		root=insert(root,tmp);
	}
	printleaf(root,1);
	return 0;
}


