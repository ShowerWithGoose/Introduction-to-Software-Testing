#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *left,*right;
}*head;
void insert(struct node *p,struct node* q)
{
	if(p->data<q->data)
	{
		if(q->left==NULL) q->left=p;
		else insert(p,q->left);
	}
	else 
	{
		if(q->right==NULL) q->right=p;
		else insert(p,q->right);
	}
}
void search(struct node* p,int H)
{
	if(p!=NULL)
	{
		search(p->left,H+1);
		if(p->left==NULL&&p->right==NULL) printf("%d %d\n",p->data,H);
		search(p->right,H+1);
	}
}
int main()
{
	int n,a,i;
	struct node *p;
	scanf("%d",&n);
	scanf("%d",&a);
	head=(struct node*)malloc(sizeof(struct node));
	head->data=a;head->left=NULL;head->right=NULL;
	for(i=2;i<=n;i++)
	{
		scanf("%d",&a);
		p=(struct node*)malloc(sizeof(struct node));
		p->data=a;p->left=NULL;p->right=NULL;
		insert(p,head);
	}
	search(head,1);
}

