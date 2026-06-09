#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
typedef struct TREE {
    int number;
    struct TREE *left;
    struct TREE *right;
    int lenth;
}Tree,*Treee;
int lenth=1;
Treee root=NULL;
int i;
int m,n;
void print(Treee x)
{
	printf("%d %d\n",x->number,x->lenth);
}
void sort(Treee x)
{
    if(x!=NULL){
        sort(x->left);
        if(x->left==NULL && x->right==NULL)	print(x);
        sort(x->right);
    }
}
void TT(Treee *x,int t,int lenth)
{
	if(*x==NULL)
	{
		*x=(Treee)malloc(sizeof(Treee));
		(*x)->left=(*x)->right=NULL;
		(*x)->number=t;
		(*x)->lenth=lenth;
	}
	else if(t<(*x)->number)
	{
		TT(&((*x)->left),t,lenth+1);
	} 
	else
	{
		TT(&((*x)->right),t,lenth+1);
	} 
}
int main()
{	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		TT(&root,m,1);
	}
	sort(root);
	return 0;
}


