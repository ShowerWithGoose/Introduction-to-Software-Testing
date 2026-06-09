#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct info{
	int data;
	struct info* lchild;
	struct info* rchild;
};
struct info* build(struct info* root,int data)
{
	struct info* p;
	if(root==NULL)
	{
		p=(struct info*)malloc(sizeof(struct info));
		p->data=data; p->lchild=p->rchild=NULL;
		return p;
	}
	else if(root->data>data)
		root->lchild=build(root->lchild,data);
	else if(root->data<=data)
		root->rchild=build(root->rchild,data);
	return root;
}
void printfleaf(struct info* root,int height)
{
	if(root->lchild!=NULL) printfleaf(root->lchild,height+1);
	if(root->rchild!=NULL) printfleaf(root->rchild,height+1);
	if(root->rchild==NULL && root->lchild==NULL)
	 	printf("%d %d\n",root->data,height);
}
int main()
{
	struct info* root=NULL;
	int n;
	scanf("%d",&n);
	int i=0,num;
	while(i<n)
	{
		scanf("%d",&num);
		root=build(root,num);
		i++;
	}
	printfleaf(root,1);
	return 0;
 } 

