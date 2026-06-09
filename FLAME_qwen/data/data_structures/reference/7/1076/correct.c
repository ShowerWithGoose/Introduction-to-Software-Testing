#include<stdio.h>
#include<malloc.h>
struct node
{
	int num;
	struct node* lchild;
	struct node* rchild;
};
struct node* root=NULL;
int a;
int n;
void adNode(struct node**ptr,int nu)
{
	if(*ptr==NULL)
	{
		(*ptr)=(struct node*)malloc(sizeof (struct node));
		(*ptr)->num=nu;
		(*ptr)->lchild=NULL;
		(*ptr)->rchild=NULL;
	}
	else
	{
		if((*ptr)->num<=nu)
		{
			adNode(&((*ptr)->rchild),nu);
		}
		else if((*ptr)->num>nu)
		{
			adNode(&((*ptr)->lchild),nu);
		}
	}
}
int deep=1;
void putNum(struct node* ptr,int deep)
{
	if(ptr==NULL) return;
	if(ptr->lchild==NULL&&ptr->rchild==NULL)
	{
		printf("%d %d\n",ptr->num,deep);
		return;
	}
	putNum(ptr->lchild,deep+1);
	putNum(ptr->rchild,deep+1);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		adNode(&root,a);
	}
	putNum(root,deep);
	return 0;
}


