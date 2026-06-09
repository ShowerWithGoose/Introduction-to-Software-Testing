#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct treenode{
	int data;
	struct treenode* lchid;
	struct treenode* rchid;
};
typedef struct treenode* Treenode;
Treenode comp(Treenode head,int n); 
void insert(Treenode head,int i);
//Treenode comp(Treenode head,int n); 
//void insert(Treenode head);
//void visit(Treenode head,int i);
int main ()
{
	Treenode p;
	p=NULL;
	int n,i,a[100],m;
	scanf("%d\n",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		m=a[i];
		p=comp(p,m);
	}
	insert(p,1);
	
	
	return 0;
 } 
Treenode comp(Treenode head,int n)
{
	//head=(Treenode)malloc(sizeof(struct treenode));
	if(head==NULL)
	{
		head=(Treenode)malloc(sizeof(struct treenode));
		head->data=n;
		head->lchid=NULL;
		head->rchid=NULL;
	}
	else
	{
		if(n<head->data)
		    head->lchid=comp(head->lchid,n);
		else
		{ 
		    head->rchid=comp(head->rchid,n);	
		}
	}
	return head;
}
void insert(Treenode head,int i)
{
	if(head->lchid==NULL&&head->rchid==NULL)
	printf("%d %d\n",head->data,i);
	else
	{
	   if(head->lchid!=NULL)
	   insert(head->lchid,i+1);
	   if(head->rchid!=NULL)
	   insert(head->rchid,i+1);	
	} 
}
/*void insert(Treenode head)
{
	if(head->lchid==NULL&&head->rchid==NULL)
	printf("%d\n",head->data);
	else
	{
	   if(head->lchid!=NULL)
	   insert(head->lchid);
	   if(head->rchid!=NULL)
	   insert(head->rchid);	
	} 
}*/



