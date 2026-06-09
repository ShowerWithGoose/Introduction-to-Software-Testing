#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node
{
	int data;
	int height;
	struct node *left,*right;
} NODE,*PNODE;
void insert(PNODE *t,int a,int h);
void tra_qianxu(PNODE t)
{
	if(t!=NULL)
	{
		
	    tra_qianxu(t->left );
		if(t->left==NULL&&t->right==NULL)
		printf("%d %d\n",t->data,t->height);
	    tra_qianxu(t->right);
	}
} 
int main()
{
	int n,i,a;
	PNODE t=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		insert(&t,a,1);
	}
	tra_qianxu(t);
	return 0;
}
void insert(PNODE *t,int a,int h)
{
	if(*t==NULL)
	{
		*t=(PNODE)malloc(sizeof(PNODE));
		(*t)->left=(*t)->right=NULL;
		(*t)->height=h;
		(*t)->data=a;
	}
	    
	else
	{
		if(a<(*t)->data)
		{
			insert(&((*t)->left),a,h+1);
		}
		else 
		{
			insert(&((*t)->right),a,h+1);
		}
		
	}
}

