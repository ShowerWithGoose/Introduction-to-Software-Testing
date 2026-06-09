#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<time.h>
struct node {
	int data;
	int height;
	struct node *left, *right;
}; 
typedef struct node BSTNode;
typedef struct node* BSTNodeptr;
BSTNodeptr root=NULL;

BSTNodeptr insertBST(BSTNodeptr p,int item)//递归插入指定元素 
{
	if(p==NULL)
	{
		p=(BSTNodeptr)malloc(sizeof(BSTNode));
		p->data=item;
		p->left=p->right=NULL;
	}
	else if(item<p->data)
		p->left=insertBST(p->left,item);
	else if(item>=p->data)
		p->right=insertBST(p->right,item);
		return p;
}

void heightnode(BSTNodeptr p)
{
	if(p==root) p->height=1;
	if(p!=NULL)
	{
		if(p->left!=NULL)
		p->left->height = p->height+1;
		if(p->right!=NULL)
		p->right->height = p->height+1;
		
		heightnode(p->left);
		heightnode(p->right);
	}
}

void printTREE(BSTNodeptr p)
{
	if(p!=NULL){
		printTREE(p->left);
		if(p->left==NULL && p->right==NULL)
		{
			printf("%d %d\n",p->data,p->height);
		}
		printTREE(p->right);
	}	
}  
 
int main()
{
	int n,a;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		//printf("%d\n",a);
		root=insertBST(root,a);
	}
	
	heightnode(root);
	printTREE(root);
	
}




