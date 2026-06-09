#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
struct node{
	int data;
	int num;
	struct node *left,*right;
}; 
typedef struct node *BTNodeptr;
typedef struct node BTNode;
BTNodeptr root=NULL;
BTNodeptr insertBST(BTNodeptr p,int item,int sum)
{
	sum++;
	if(p==NULL)
	{
		p=(BTNodeptr)malloc(sizeof(BTNode));
		p->num=sum;
		p->data=item;
		p->left=p->right=NULL;	
	}	
	else if(item<p->data)
		p->left=insertBST(p->left,item,sum);
	else
		p->right=insertBST(p->right,item,sum);
	return p;
} 
void inorder(BTNodeptr t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		if(t->left==NULL&&t->right==NULL)
			printf("%d %d\n",t->data,t->num);
		inorder(t->right);
	}
}
int main()
{
	
	int n,a,i,count=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		count=0;
		root=insertBST(root,a,count);
	}
	inorder(root);
	return 0;
}


