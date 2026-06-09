#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *Cleft,*Cright;
	int depth;
};
typedef struct node BTNode;
typedef struct node* BTNodeptr;
void ToLeaf(BTNodeptr t)
{
	if(t!=NULL)
	{
	if(t->Cleft==NULL&&t->Cright==NULL)
	printf("%d %d\n",t->data,t->depth);
	ToLeaf(t->Cleft);
	ToLeaf(t->Cright);
	}
}
int main()
{
	BTNodeptr tree=NULL,origin=NULL,pnew=NULL;
	int i=0,num,n,d=1,mark;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
	scanf("%d",&num);
	if(tree==NULL)
	{
		origin= (BTNodeptr)malloc(sizeof(BTNode));
		origin->data=num;
		origin->Cleft=NULL;
		origin->Cright=NULL;
		origin->depth=d;
		pnew=tree=origin;
		continue;
	}
	while(tree!=NULL)
	{
		if(num<tree->data)   //小于向左 
		{
		  pnew=tree;
		  tree=tree->Cleft;
		  mark=0;
		}
		else if(num>=tree->data) //大于向右 
		{
		  pnew=tree;
		  tree=tree->Cright;
		  mark=1;
		}
		d++;//深度+1 
	 } 
	tree=(BTNodeptr)malloc(sizeof(BTNode));
	tree->data=num;
	tree->Cleft=NULL;
	tree->Cright=NULL;
	tree->depth=d;
	if(mark==1)  pnew->Cright=tree;
	else pnew->Cleft=tree;
	d=1;
	pnew=tree=origin;
    }
    ToLeaf(tree);
    return 0;
}

