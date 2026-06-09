#include<stdio.h>
struct tr{
	int data;
	int depth;
	struct tr *lchild,*rchild;
}*tree=NULL,*p;

void Build(struct tr *t)
{
	if(p->data<t->data)
	{
		if(t->lchild==NULL)
		{
			t->lchild=p;
			p->depth++;
			return;
		}
		else
		{
			p->depth++;
			Build(t->lchild);
		}
	}
	else
	{
		if(t->rchild==NULL)
		{
			t->rchild=p;
			p->depth++;
			return;
		}
		else
		{
			p->depth++;
			Build(t->rchild);
		}
	}
}

void Check(struct tr *t)
{
	if(t!=NULL)
	{
		if(t->lchild==NULL&&t->rchild==NULL)
		{
			printf("%d %d\n",t->data,t->depth+1);
		}
		Check(t->lchild);
		Check(t->rchild);
	}
}

void Delete(struct tr *t)
{
	if(t!=NULL)
	{
		Delete(t->lchild);
		Delete(t->rchild);
		free(t);
		t=NULL;
	}
}

int main()
{
	int n,i,num;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num);
		p=(struct tr *)malloc(sizeof(struct tr));
		p->data=num;
		p->lchild=NULL;
		p->rchild=NULL;
		if(tree==NULL)
		{
			tree=p;
		}
		else
		{
			Build(tree);
		}
	}
	Check(tree);
	Delete(tree);
	return 0;
}

