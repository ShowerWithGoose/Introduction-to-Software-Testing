#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#define llo long long
#define max(A,B) A>B?A:B
struct treenode{
	int num;
	int height;
	struct treenode *lchild,*rchild;
};

typedef struct treenode BTNode,*BTNodeptr;
BTNodeptr Root = NULL;
void insertBST(int item)
{
	BTNodeptr p,q;
	p=(BTNodeptr)malloc(sizeof(BTNode));
	p->num=item;
	p->lchild=NULL;
	p->rchild =NULL;
	static int cnt=0;
	if(Root==NULL)
	{
		Root=p;
		Root->height =1;
	}
	
	else
	{
		q=Root;
		cnt=0;
		while(1)
		{
			cnt++;
			if(item<q->num)
			{
				if(q->lchild==NULL)
				{
					q->lchild=p;
					p->height =cnt+1;
					break;
				}
				else
				q=q->lchild;
				
			}
			else if(item>=q->num)
			{
				if(q->rchild==NULL)
				{
					q->rchild=p;
					p->height =cnt+1;
					break;
					
				}
				else
				q=q->rchild;
			}
		}
	}
}
void visit(BTNodeptr t)
{
	if(t->lchild==NULL&&t->rchild==NULL)
	printf("%d %d\n",t->num,t->height);
}
void postorder(BTNodeptr t)
{
	if(t!=NULL)
	{
		postorder(t->lchild);
		postorder(t->rchild);
		visit(t);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int i=0,j=0,data;
	for(i=0;i<n;i++)
	{
		scanf("%d",&data);
		insertBST(data);
	}
	postorder(Root);
	
	
	
}


