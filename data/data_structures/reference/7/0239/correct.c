#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
typedef int datatype;
struct node{
	datatype data;
	struct node *lchild,*rchild;
};
typedef struct node BTNode,*BTNodeptr;
BTNodeptr insertBST(BTNodeptr p,datatype item);
void print(BTNodeptr p);
int d=1;
int main()
{
	int n, i,item;
	scanf("%d",&n);
	BTNodeptr root=NULL;
	for(i=0;i<n;i++)
	{
		scanf("%d",&item);
		root=insertBST(root,item);
	}
	print(root);
	return 0;
}
BTNodeptr insertBST(BTNodeptr p,datatype item)
{
	if(p==NULL)
	{
		p=(BTNodeptr)malloc(sizeof(BTNode));
		p->data=item;
		p->lchild=p->rchild=NULL;
	}
	else if(item<p->data)
	p->lchild=insertBST(p->lchild,item);
	else //if(item>p->data)
	p->rchild=insertBST(p->rchild,item);
	return p;
}
void print(BTNodeptr p)
{
	if(p==NULL)
	return ;
	else
	{
		if(p->lchild==NULL&&p->rchild==NULL)
		{
			printf("%d %d\n",p->data,d);
			
		}
		d++;
		print(p->lchild);
		print(p->rchild);
		d--;
	}
}




