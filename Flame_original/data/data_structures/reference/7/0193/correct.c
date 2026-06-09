#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct TREE{
	int data;
	struct TREE *lchild;
	struct TREE *rchild;
}*BTREE,BTNode;

BTREE INSERTBST(BTREE T,int item); 
void putout(BTREE T);

int i=1;

int main()
{
	int N,num;
	BTREE root=NULL;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&num);
		root=INSERTBST(root,num);
	}
	putout(root);
	return 0;
 } 
 
BTREE INSERTBST(BTREE T,int item)
{
	if(T==NULL)
	{
		T=(BTREE)malloc(sizeof(BTNode));
		T->data=item;
		T->lchild=NULL;
		T->rchild=NULL;
	}
	else if(item<T->data)
	{
		T->lchild=INSERTBST(T->lchild,item);
	}
	else if(item>=T->data)
	{
		T->rchild=INSERTBST(T->rchild,item);
	}
	return T;
}

void putout(BTREE T)
{
	if(T==NULL)
	{
		return;
	}
	else
	{
	if(T->lchild==NULL&&T->rchild==NULL)
	{
		printf("%d %d\n",T->data,i);
	}
	i++;
	putout(T->lchild);
	putout(T->rchild);
	i--;
	}
}

