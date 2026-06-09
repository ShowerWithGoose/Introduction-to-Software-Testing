#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	int data;
	int num;
	struct node *lchild;
	struct node *rchild;
}tree,*trees;
trees create(trees r,int a,int b);
void pri(trees t);
int main()
{
	int i;
	int n;
	int j;
	int temp;
	trees q=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	scanf("%d",&temp);
    	j=0;
    	q=create(q,temp,j);
	}
	pri(q);
	return 0;
}

trees create(trees r,int a,int b)
{
	b++;
	if(r==NULL)
	{
		trees head=(trees)malloc(sizeof(tree));
		head->lchild=NULL;
		head->rchild=NULL;
		head->data=a;
		head->num=b;
		r=head;
	}
	else if(a<r->data)
	{
		r->lchild=create(r->lchild,a,b);
	}
	else if(a>=r->data)
	{
		r->rchild=create(r->rchild,a,b);
	}
	return r;
}

void pri(trees t)
{
	if(t->lchild!=NULL)
	{
		pri(t->lchild);
	}
	if(t->lchild==NULL&&t->rchild==NULL)
	{
		printf("%d %d\n",t->data,t->num);
	}
	if(t->rchild!=NULL)
	{
		pri(t->rchild);
	}
}

