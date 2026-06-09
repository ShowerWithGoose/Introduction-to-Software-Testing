#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct node
{
	int value;
	int depth;
	struct node *lson,*rson;
}tree[100000];
int n,i;
int a[100000];
void DFS(int value,struct node *father);
void print(struct node *no);

int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	struct node *root;
	root=(struct node*)malloc(sizeof(struct node));
	root->value=a[0];
	root->depth=1;
	root->lson=NULL;
	root->rson=NULL;
	for(i=1;i<n;i++)
	{
		DFS(a[i],root);
	}
	print(root);
	return 0;
}
void DFS(int value,struct node *father)
{
	if(value<father->value)
	{
		if(father->lson==NULL)
		{
			struct node *p;
			p=(struct node*)malloc(sizeof(struct node));
			p->value=value;
			p->lson=NULL;
			p->rson=NULL;
			p->depth=father->depth+1;
			father->lson=p;
			return;
		}
		else
		{
			DFS(a[i],father->lson);
		}
	}
	else
	{
		if(father->rson==NULL)
		{
			struct node *p;
			p=(struct node*)malloc(sizeof(struct node));
			p->value=value;
			p->lson=NULL;
			p->rson=NULL;
			p->depth=father->depth+1;
			father->rson=p;
			return;
		}
		else
		{
			DFS(a[i],father->rson);
		}
	}
}
void print(struct node *no)
{
	if(no->lson==NULL && no->rson==NULL)
	{
		printf("%d %d\n",no->value,no->depth);
	}
	else
	{
		if(no->lson!=NULL)
		{
			print(no->lson);
		}
		if(no->rson!=NULL)
		{
			print(no->rson);
		}
	} 
}

//(n+m-1)/m

