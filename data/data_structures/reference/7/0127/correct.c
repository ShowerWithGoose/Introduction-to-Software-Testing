#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *lchild,*rchild;
};
typedef struct node BTnode,*BTnodeptr;
BTnodeptr compare(BTnodeptr T,int data);
void output(BTnodeptr T);
int depth=1;

int main()
{
	int n,input;
	scanf("%d",&n);
	int j;
	BTnodeptr root=NULL;
	for(j=0;j<n;j++)
	{
		scanf("%d",&input);
		root=compare(root,input);
	}
	output(root);
	return 0;
}
BTnodeptr compare(BTnodeptr T,int data)
{
	if(T==NULL)
	{
		T=(BTnodeptr)malloc(sizeof(BTnode));
		T->data=data;
		T->lchild=NULL;
		T->rchild=NULL;
	}
	else
	{
		if(T->data<=data)
		{
			T->rchild=compare(T->rchild,data);
		}
		else
		{
			T->lchild=compare(T->lchild,data);
		}
	}
	return T;
}
void output(BTnodeptr T)
{
	if(T==NULL)
	{
		return;
	}
	else
	{
		if(T->lchild==NULL&&T->rchild==NULL)
		{
			printf("%d %d\n",T->data,depth);
		}
		depth++;
		output(T->lchild);
		output(T->rchild);
		depth--;
	}
}




