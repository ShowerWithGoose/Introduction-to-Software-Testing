#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
	int x;
	struct node* llink;
	struct node* rlink;
}tnode,* tnodeptr;

tnodeptr Build(tnodeptr root,int x)
{
	if(root==NULL)
	{
		tnodeptr p=(tnodeptr)malloc(sizeof(tnode));
		p->x=x;
		p->llink=NULL;
		p->rlink=NULL;
		return p;
	}else{
		if(x<root->x)
		{
			root->llink=Build(root->llink,x);
		}else{
			root->rlink=Build(root->rlink,x);
		}
		return root;
	}
}

void dfs(tnodeptr root,int height)
{
	int flag=0;
	if(root->llink!=NULL)
	{
		dfs(root->llink,height+1);
		flag=1;
	}
	if(root->rlink!=NULL)
	{
		dfs(root->rlink,height+1);
		flag=1;
	}
	if(!flag)
	{
		printf("%d %d\n",root->x,height);
	}
}

int main()
{
	tnodeptr root=NULL;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		root=Build(root,x);
	}
	dfs(root,1);
	return 0;	
}

