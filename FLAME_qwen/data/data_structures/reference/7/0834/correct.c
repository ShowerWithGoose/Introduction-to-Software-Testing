#include<stdio.h>
#include<stdlib.h>
struct node{
	int num;
	struct node *lchild,*rchild;
};
int deep=0;
struct node* insert(struct node *p,int m);
void find(struct node *p);
int main()
{
	int n,m;
	struct node *root=NULL;	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&m);
		root=insert(root,m);
	}
	find(root);
	return 0;
}
struct node* insert(struct node *p,int m){
	if(p==NULL){
		p=(struct node *)malloc(sizeof(struct node));
		p->lchild=p->rchild=NULL;
		p->num=m;
	}
	else if(m<p->num)
	p->lchild=insert(p->lchild,m);
	else if(m>=p->num)
	p->rchild=insert(p->rchild,m);
	return p; 
}
void find(struct node *p){
	if(p!=NULL){
		deep++;
		find(p->lchild);
		if(p->lchild==NULL&&p->rchild==NULL)
		printf("%d %d\n",p->num,deep);
		find(p->rchild);	
		deep--;
	}
}

