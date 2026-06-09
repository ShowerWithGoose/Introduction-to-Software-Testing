/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node *insertTree(struct node *t,int num);
void print(struct node *t,int layer);
 
typedef struct node
{
	int data;
	struct node *lchild,*rchild;
}Tree,*PTree;

int layer,i,num[1000],n;

int main()
{
	PTree tree=NULL;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		tree=insertTree(tree,num[i]);
	}
	print(tree,1);
	return 0;
 } 
 
struct node *insertTree(struct node *t,int num)
{
	struct node * p;
 	if(t==NULL)
 	{
 		p=(PTree)malloc(sizeof(Tree));
		p->data=num;
		//printf("%d\n",p->data);
		p->lchild=NULL;
		p->rchild=NULL;
		return p;
	}
	else
	{
		if(num<t->data)
		{
			t->lchild=insertTree(t->lchild,num);
		}
		else
		{
			t->rchild=insertTree(t->rchild,num);
		}
		return t;
	}
 }
 
 void print(struct node *t,int layer)
 {
	if(t->lchild!=NULL)
	{
		print(t->lchild,layer+1);
	}
	if(t->rchild!=NULL)
	{
		print(t->rchild,layer+1);
	}
	if(t->lchild==NULL&&t->rchild==NULL)
	{
		printf("%d %d\n",t->data,layer);
	}
}

