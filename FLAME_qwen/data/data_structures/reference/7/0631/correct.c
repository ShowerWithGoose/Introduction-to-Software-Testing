#include<stdio.h>
#include<stdlib.h>
typedef struct Tree
{
	int data;
	struct Tree *lchild;
	struct Tree *rchild;
}tree,*ptree;
/*ptree initial(int num)
{
	ptree node=(ptree)malloc(sizeof(tree));
	if(node==NULL)
	{
		printf("wrong");
		return;
	}
	node->data=num;
	node->lchild=NULL;
	node->rchild=NULL;
	return node;
}*/
ptree insert(ptree p,int num)
{
	if(p==NULL)
	{
		p=(ptree)malloc(sizeof(tree));
		p->data=num;
		p->lchild=p->rchild=NULL;
	}
	else if(num<p->data)
	{
		p->lchild=insert(p->lchild,num);
	}
	else
	{
		p->rchild=insert(p->rchild,num);
	}
	return p;
}
void backprint(ptree p,int h)
{
	if(p->lchild!=NULL)
	{
		backprint(p->lchild,h+1);
	}
	if(p->rchild!=NULL)
	{
		backprint(p->rchild,h+1);
	}
	if(p->lchild==NULL&&p->rchild==NULL)
	{
		printf("%d %d\n",p->data,h);
	}
}
int main()
{
	int count;
	int num;
	int height=1;
	int i;
	ptree root=NULL;
	scanf("%d",&count);
	for(i=0;i<count;i++)
	{
		scanf("%d",&num);
		root=insert(root,num);
	}
	backprint(root,height);
	return 0;
}



