
#include <stdio.h>
#include <string.h> 
typedef int Datatype;
struct node
{
	Datatype data;
	struct node *lchild, *rchild;
};
typedef struct node BTNode;
typedef struct node *BTNodeptr;
int h=1;
BTNodeptr insertBST(BTNodeptr p, Datatype item)
{
	if(p==NULL)
	{
		p = (BTNodeptr)malloc(sizeof(BTNode));
		p->data=item;
		p->lchild = p->rchild=NULL;
	}
	else if(item< p->data)
		p->lchild = insertBST(p->lchild,item);
	else if(item>= p->data)
		p->rchild = insertBST(p->rchild,item);
	return p;
}

void print(BTNodeptr t)
{
	if(t==NULL)
		return ;
	else if(t!=NULL)
	{
		if((t->lchild==NULL)&&(t->rchild==NULL))
			printf("%d %d\n",t->data,h);
			h++;
		print(t->lchild);
		print(t->rchild);
		h--;
	}
}
int main()
{
	int n,num,i;
	BTNodeptr root =NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		root=insertBST(root,num);
	}
	print(root);
	return 0;
}




