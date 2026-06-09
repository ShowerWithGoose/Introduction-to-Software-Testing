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
BTNodeptr insertBST(BTNodeptr p,int item,int count)
{
	count++;
	if(p==NULL)
	{
		p=(BTNodeptr)malloc(sizeof(BTNode));
		p->num=count;
		p->data=item;
		p->left=p->right=NULL;	
	}	
	else if(item<p->data)
		p->left=insertBST(p->left,item,count);
	else
		p->right=insertBST(p->right,item,count);
	return p;
} 
void inorder(BTNodeptr p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		if(p->left==NULL&&p->right==NULL)
			printf("%d %d\n",p->data,p->num);
		inorder(p->right);
	}
}
int main()
{
	
	int n,item,i,count=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&item);
		count=0;
		root=insertBST(root,item,count);
	}
	inorder(root);
	return 0;
}


