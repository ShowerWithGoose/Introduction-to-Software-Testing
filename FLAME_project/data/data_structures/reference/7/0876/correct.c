#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1000

struct node{
	int data;
	int layer;
	struct node *lchild, *rchild;
};

struct node* insertBST(struct node* p, int item, int layer);
struct node* preorder(struct node * p);

int main()
{
	int n; 
	int a[MAXSIZE];
	int i, j, k;
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
	struct node *root =NULL;
	for(i=0; i<n; i++)
	{

		root = insertBST(root, a[i], 1);
	}

	preorder( root);
	return 0;
}

struct node* insertBST(struct node* p, int item, int layer)
{

	if(p == NULL)
	{
		p = (struct node*)malloc(sizeof(struct node));
		p->data=item;
		p->lchild=NULL;
		p->rchild=NULL;
		p->layer= layer;
	}
	else if(item < p->data){
		p->lchild=insertBST(p->lchild, item,layer+1);
	}
	else if(item>=p->data)
	{
		p->rchild=insertBST(p->rchild, item, layer+1);
	}
	return p;
}
struct node* preorder(struct node * p)
{
	if(p!=0)
	{
		if(p->lchild == NULL&&p->rchild == NULL)
		{
			printf("%d %d\n", p->data, p->layer);
		}
		preorder(p->lchild);
		preorder(p->rchild);
	}
	return 0;
}










