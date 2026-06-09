#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int val;
    struct node *left;
    struct node *right; 
    int depth;
}Tree;
Tree *tree=NULL;
void println(Tree *t)
{
    if(t!=NULL){
        if(t->left==NULL&&t->right==NULL)
		printf("%d %d\n",t->val,t->depth);
		println(t->left);
        println(t->right);
    }
}
Tree *make(Tree *t,int val,int depth) 
{
	if(t==NULL)
	{
		t=(Tree *)malloc(sizeof(Tree));
		t->left=t->right=NULL;
		t->val=val;
		t->depth=depth;
		tree=t;
	}
	else if(val<t->val)
		t->left=make(t->left,val,depth+1);
	else if(val>=t->val)
		t->right=make(t->right,val,depth+1);
    return t;
}
int main(){	
    int i,m,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&m);
		tree=make(tree,m,1);
	}
	println(tree);
	return 0;
}



