#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct node{
	int data;
	int cnt;
	struct node *left,*right;
};
typedef struct node BTNode;
typedef struct node *BTNodeptr;
BTNodeptr root=NULL;
//void createTree(BTNodeptr p,int a)
//{
//	if(p==NULL)
//	{
//		p=(BTNodeptr)malloc(sizeof(BTNode));
//		p->data=a;
//		p->left=NULL;
//		p->right=NULL;
//	}
//	else if(a<p->data)
//	{
//		p=p->left;
//		createTree(p->left,a);
//	}
//	else if(a>p->data)
//	{
//		createTree(p->right,a);
//	}
//}
void createTree(BTNodeptr p,int a)
{
	int flor=1;
	while((p->left!=NULL&&a<p->data)||(a>=p->data&&p->right!=NULL))
	{
		if(a<p->data)
		{
			p=p->left;
			flor++;
		}
		else if(a>=p->data)
		{
			p=p->right;
			flor++;
		}
	}
	if(a<p->data)
	{
		BTNodeptr q;
		q=(BTNodeptr)malloc(sizeof(BTNode));
		q->data=a;
		q->cnt=flor+1;
		q->left=NULL;
		q->right=NULL;
		p->left=q;
		
	}
	else if(a>=p->data)
	{
		BTNodeptr q;
		q=(BTNodeptr)malloc(sizeof(BTNode));
		q->data=a;
		q->cnt=flor+1;
		q->left=NULL;
		q->right=NULL;
		p->right=q;
	}
}

void preorder(BTNodeptr t)
{
	
	if(t!=NULL)
	{
		if(t->left==NULL&&t->right==NULL)
		{
			printf("%d %d\n",t->data,t->cnt);
		}
		
		preorder(t->left);
		preorder(t->right);
	}
}
//int max(int x,int y)
//{
//	if(x>y)
//		return x;
//	else
//		return y;
//}
//int heightTree(BTNodeptr p)
//{
//	if(p==NULL)
//		return 0;
//	else
//		return 1+max(heightTree(p->left),heightTree(p->right));
//}//计算树的高度
// 

int main()
{
	int sum;
	int temp;
	
	scanf("%d",&sum);
	for(int i=0;i<sum;i++)
	{
		scanf("%d",&temp);
		
		if(i==0)
		{
			root=(BTNodeptr)malloc(sizeof(BTNode));
			root->data=temp;
			root->cnt=1;
			root->left=NULL;
			root->right=NULL;
		}
		else
		{
			createTree(root,temp);
		}
	}
	preorder(root);
	return 0;
}

