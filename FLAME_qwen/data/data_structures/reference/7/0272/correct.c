#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int num;
	struct node *lchild,*rchild;
}BTNode,*BTNodeptr;
BTNodeptr head;
BTNodeptr insertBST(BTNodeptr p,int item)
{
	if(p==NULL)
	{
		p=(BTNodeptr)malloc(sizeof(BTNode));
		p->num=item;
		p->lchild=p->rchild=NULL;
	}
	else if(item<p->num)
	{
		p->lchild=insertBST(p->lchild,item);
	}
	else if(item>=p->num)
	{
		p->rchild=insertBST(p->rchild,item); 
	}
	return p;
	 
}
int height(BTNodeptr p, BTNodeptr root)
{
	if(p==root)
	return 1;
	else if(p->num<root->num)
	{
		return height(p,root->lchild)+1;
	}
	else if(p->num>=root->num)
	{
		return height(p,root->rchild)+1;
	}
}
void mview(BTNodeptr p)
{
	if(p!=NULL)
	{
		mview(p->lchild);
		if(p->lchild ==NULL&&p->rchild==NULL)
		{
			printf("%d ",p->num);
		printf("%d\n",height(p,head));
		}
		mview(p->rchild);
	}
	
}
int main()
{
	BTNodeptr root=NULL;
	int n,i,tmp;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&tmp);
		root=insertBST(root,tmp);
	}
	head=root;
	mview(root);
	return 0;
 } 



