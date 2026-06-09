#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
struct tree{
	int data;
	struct tree *ltree;
	struct tree *rtree;
	int high;
};
typedef struct tree tree;
tree *build(tree *t,int tmp,int len)
{
	if(t==NULL)
	{
		t=(tree *)malloc(sizeof(tree));
		t->data=tmp;
		t->ltree=NULL;
		t->rtree=NULL;
		t->high=len;
	}
	else if(tmp<t->data)
		t->ltree=build(t->ltree,tmp,len+1);
	else if(tmp>=t->data)
		t->rtree=build(t->rtree,tmp,len+1);
		
	return t;
}
void print(tree *t)
{
	if(t!=NULL)
	{
		print(t->ltree);
		if(t->ltree==NULL&&t->rtree==NULL) 
		visit(t);
		print(t->rtree);
	}
}
void visit(tree *t)
{
	printf("%d %d\n",t->data,t->high);
}
int main()
{
	tree *root=NULL;
	int n,item;
	scanf("%d",&n);
	int i=0;
	int len=1;
	for(i=0;i<n;i++)
	{
		scanf("%d",&item);
		root=build(root,item,len);
	}
	print(root);
	return 0;
 } 

