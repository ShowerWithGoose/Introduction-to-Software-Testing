#include<stdio.h>
#include<string.h>
struct tree{
	int a;
	struct tree *left;
	struct tree *right;
	int depth;
}; 
typedef struct tree p,*tt;
int m,n,i,depth=1;
tt root=NULL;
void InsertBST(tt *t,int value,int depth);
void VISIT(tt p)
{
	printf("%d %d\n",p->a,p->depth);
}
void inorder(tt p)
{
    if(p!=NULL){
        inorder(p->left);
        if(p->left==NULL && p->right==NULL)	VISIT(p);     
        inorder(p->right);
    }
} 

int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		InsertBST(&root,m,1);
	}
	inorder(root);
	return 0;
}
void InsertBST(tt *t,int value,int depth) 
{
	if(*t==NULL)
	{
		*t=(tt)malloc(sizeof(tt));
		(*t)->left=(*t)->right=NULL;
		(*t)->a=value;
		(*t)->depth=depth;
	}
	else if(value<(*t)->a)
	{
		InsertBST(&((*t)->left),value,depth+1);
	} 
	else
	{
		InsertBST(&((*t)->right),value,depth+1);
	} 
}


