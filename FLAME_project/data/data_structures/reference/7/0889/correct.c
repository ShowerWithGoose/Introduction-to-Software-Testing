#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define M 200
typedef struct btnode{
	int data;
	struct btnode *llink,*rlink;
}btnode,*btree;
btree t=NULL;
void create(btree *p,int item)
{
	if((*p)==NULL)
	{
		(*p)=(btree)malloc(sizeof(btnode));
		(*p)->data=item;
		(*p)->llink=NULL;
		(*p)->rlink=NULL;
	}
	else
	{
		if(item<(*p)->data)
		{
			create(&((*p)->llink),item);
		}
		else
		{
			create(&((*p)->rlink),item);
		}
	}
}

void operate(btree p,int top)
{
	if(!p->llink&&!p->rlink)
	{
		printf("%d %d\n",p->data,top+2);
	}
	return ;
}

void postorder(btree t)
{
	btree p=t,stack[M]={0};
	int top=-1,stack2[M]={0};
	if(t!=NULL)
	{
		do{
			while(p!=NULL)
			{
				stack[++top]=p;
				stack2[top]=0;
				p=p->llink;
			}
			p=stack[top--];
			if(stack2[top+1]==0)
			{
				stack[++top]=p;
				stack2[top]=1;
				p=p->rlink;
			}
			else
			{
				operate(p,top);
				p=NULL;
			}
		}while(!(p==NULL&&top==-1));
	}
}
int main()
{
	int n,item;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&item);
		create(&t,item);
	}
	postorder(t);
 	return 0;
}


