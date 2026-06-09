#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>
int k;
struct node {
    int data;
    int flag;
    struct node *left, *right;
}*root,*p;
struct node *create(struct node *p,int k)
{
     if(p==NULL){
     	p=(struct node *)malloc(sizeof(struct node));
     	p->data=k;
     	p->left=NULL;
     	p->right=NULL;
     	p->flag=0;
	 }	
	 else if(k<p->data)
	 p->left=create(p->left,k);
	 else if(k>=p->data)
	  p->right=create(p->right,k);
	  return p;
}
void zhao(struct node *p,int h)
{
	if(p->left==NULL&&p->right==NULL&&p->flag==0)
	{
		printf("%d %d\n",p->data,h);
		p->flag=1;
	}
	else if(p->left!=NULL&&p->left->flag==0)
	{
		h++;
		return zhao(p->left,h);
	}
	else if(p->right!=NULL&&p->right->flag==0)
	{
		h++;
		return zhao(p->right,h);
	}
	else if(p->left!=NULL&&p->right!=NULL)
{
	if(p->left->flag==1&&p->right->flag==1)
	p->flag=1;
}
else if(p->left==NULL&&p->right!=NULL)
{
	if(p->left==NULL&&p->right->flag==1)
	p->flag=1;
}
else if(p->right==NULL&&p->left!=NULL)
{
	if(p->left->flag==1)
	p->flag=1;
}
//	else if((p->left->flag==1&&p->right->flag==1)||(p->left==NULL&&p->right->flag==1)||(p->left->flag==1&&p->right==NULL))
//	p->flag=1;
	return 0;
}
int main()
{
int n,i,s[2000],h;
scanf("%d",&n);
for(i=0;i<n;i++)
{
	scanf("%d",&s[i]);
	root=create(root,s[i]);
}
for(i=0;i<n;i++)
{
	h=1;
	zhao(root,h);
}
return 0;
}


