#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int data;
	struct node*llink,*rlink;
}BTnode,*BTnodeptr;
BTnodeptr root;
BTnodeptr insert (BTnodeptr p,int data)  //创建二叉查找树 
{
	if(p==NULL)
	{
		p=(BTnodeptr)malloc(sizeof(BTnode));
		p->data=data;
		p->llink=p->rlink=NULL;
	}
	else if(data<p->data)
	{
		p->llink=insert(p->llink,data);
	}
	else if(data>=p->data)
	{
		p->rlink=insert(p->rlink,data);
	}
	return p;
}
void preorder(BTnodeptr p,int i)   //遍历，i表示层数 
{
	if(p!=NULL)
	{
		if(p->rlink==NULL&&p->llink==NULL)
		{
			printf("%d ",p->data);
			printf("%d\n",i);
		}
		i++;
		preorder(p->llink,i);
		preorder(p->rlink,i);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int i=1;
	int item;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&item);
		root=insert(root,item);
	}
	preorder(root,1);
	return 0;
}

