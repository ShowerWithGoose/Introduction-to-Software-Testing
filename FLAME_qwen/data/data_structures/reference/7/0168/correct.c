#include<stdio.h>
#include<string.h>
struct node
{
	int height;
	int num;
	struct node *lchild,*rchild;
};
typedef struct node BTNode,*BTNodeptr;
BTNodeptr first,p=NULL;
BTNodeptr insert(BTNodeptr p, int item, int high)
{
	high++;
	if(p==NULL)
	{
		p=(BTNodeptr)malloc(sizeof(BTNode));
		p->num=item;
		p->lchild=NULL;
		p->rchild=NULL;
		first =p;
		p->height=high;
	}
	else if(item<p->num)
	p->lchild=insert(p->lchild,item,high);
	else if(item>=p->num)
	p->rchild=insert(p->rchild,item,high);
	return p;
}
void print(BTNodeptr p)
{
	
	if(p)
	{
		if((p->lchild)==NULL&&(p->rchild)==NULL)
		{
			printf("%d %d\n", p->num, p->height);
		}
		print(p->lchild);
		print(p->rchild);
	}
}
int main()
{
	int n, temp,i=0,high=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&temp);
		high=0;
		p=insert(p,temp,high);
	}
	print(p);
}

