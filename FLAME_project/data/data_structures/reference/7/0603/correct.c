#include<stdio.h>
#include<malloc.h>
int deep=1;
typedef struct tree{
		int data,lflag,rflag;
		struct tree *child1,*child2;
	}Tree,*treelink;

void insert(treelink p,treelink root)
{
	if(p->data<root->data)
	{
		if(root->lflag){root->lflag=0;root->child1=p;}
		else {insert(p,root->child1);}
	}
	else
	{
		if(root->rflag){root->rflag=0;root->child2=p;}
		else {insert(p,root->child2);}
	}
}

void search(treelink root)
{
	int deepn;
	deepn=deep;
	if(root->lflag==0){deep++;search(root->child1);}
	if(root->rflag==0){deep++;search(root->child2);}
	if(root->lflag&&root->rflag)printf("%d %d\n",root->data,deepn);deep--;
}
int main()
{
	
	
	int m;
	scanf("%d",&m);m--;
	treelink p=NULL;
	treelink root=(treelink)malloc(sizeof(Tree));
	root->lflag=1;root->rflag=1;root->child1=NULL;root->child2=NULL;	
	scanf("%d",&root->data);
	int n;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&n);
		p=(treelink)malloc(sizeof(Tree));
		p->lflag=1;p->rflag=1;p->child1=NULL;p->child2=NULL;
		p->data=n;
		insert(p,root);
	} 
	search(root);
	return 0;
} 

