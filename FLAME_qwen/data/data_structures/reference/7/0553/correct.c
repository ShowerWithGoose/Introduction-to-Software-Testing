#include<stdio.h>
#include<stdlib.h>
struct node{
	int dat;
	struct node* left;
	struct node* right;
	struct node* parent;
}*head;
int step=1;
struct node* build(int d,struct node* dad)
{
	struct node* p=(struct node*)malloc(sizeof(struct node));
	p->dat=d;
	p->left=NULL;
	p->right=NULL;
	p->parent=dad;
	return p;
	
}
void insert(struct node* p,int d)
{
	if(d<(p->dat))
	{
		if((p->left)==NULL)
			p->left=build(d,p);
		else
			insert(p->left,d);
	}
	else{
		if((p->right)==NULL)
			p->right=build(d,p);
		else
			insert(p->right,d);
	}
}
struct node* dfs(struct node* p)
{
	if(p->left==NULL&&p->right==NULL)
	{
		printf("%d %d\n",p->dat,step);
		return p->parent;
	}
	if(p->left!=NULL)
	{
		step++;
		dfs(p->left);
		step--;
	}
	if(p->right!=NULL)
	{
		step++;
		dfs(p->right);
		step--;
	}
	return p->parent;
}
int main()
{
	int n,i,n1;
	scanf("%d%d",&n,&n1);
	head=build(n1,NULL);
	for(i=2;i<=n;i++)
	{
		scanf("%d",&n1);
		insert(head,n1);
	}
	dfs(head);
	return 0;
}

