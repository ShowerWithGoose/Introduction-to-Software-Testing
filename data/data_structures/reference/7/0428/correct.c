#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	int height;
	int num;
	struct node* left;
	struct node* right;
}*m=NULL;
void insertBST(struct node*,int);
void preorder(struct node*);
int main()
{
	int n,i,a;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		insertBST(m,a);
	}
	preorder(m);
	return 0;
}
void insertBST(struct node*t,int a)
{
	int cnt=1;
	struct node*p,*q=t;
	if(t==NULL)
	{
		p=(struct node*)malloc(sizeof(struct node));
		p->num=a;
		p->height=1;
		p->left=NULL;
		p->right=NULL;
		m=p;
	}
	else
	{  while(1)
	{
		if(a<q->num)
	   {
	   	if(q->left==NULL)
	   	{
	   	p=(struct node*)malloc(sizeof(struct node));
		p->num=a;
		p->height=cnt+1;
		p->left=NULL;
		p->right=NULL;
		q->left=p;
		return;
		}
		else
		{
			q=q->left;
			cnt++;
		}
	   }
	   else
	   {
	   	if(q->right==NULL)
	   	{
	   	p=(struct node*)malloc(sizeof(struct node));
		p->num=a;
		p->height=cnt+1;
		p->left=NULL;
		p->right=NULL;
		q->right=p;
		return;
		}
		else
		{
			q=q->right;
			cnt++;
		}
	   }	
	}
	}	   
}
void preorder(struct node*t)
{   if(t==NULL)
return;
	if(t->left==NULL&&t->right==NULL)
	{
		printf("%d %d\n",t->num,t->height);
		return ;
	}
	preorder(t->left);
	preorder(t->right);
	
}

