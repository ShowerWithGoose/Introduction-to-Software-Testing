#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int num;
	struct node *lchild,*rchild;
}*Tree;
Tree insert(Tree L,int n)
{
	Tree p,q;
	p=(Tree)malloc(sizeof(struct node));
	p->num=n;
	p->lchild=NULL;
	p->rchild=NULL;
	if(L==NULL)
	{
		L=p;
		return L;
	}
	else
	{
		q=L;
		while(1)
		{
			if(n<q->num)
			{
				if(q->lchild==NULL)
				{
					q->lchild=p;
					break;
				}
				else
				q=q->lchild;
			}
			else
			{
				if(q->rchild==NULL)
				{
					q->rchild=p;
					break;
				}
				else
				q=q->rchild;
			}
		}
	}
	return L;
}
void sortTree(Tree root,int cnt)
{
	Tree  p;
	p=root;
	if(p==NULL)
	return;
	else
	{
		if(p->lchild==NULL&&root->rchild==NULL)
		printf("%d %d\n",p->num,cnt);
		sortTree(p->lchild,cnt+1);
		sortTree(p->rchild,cnt+1);
	}
}
int main()
{
	int n,i=0,num;
	Tree root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		root=insert(root,num);
	}
	sortTree(root,1);
	return 0;
 } 




