#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>//快排 
#define eps 1e-8
#define pi 3.14
#define eof EOF
struct node
{
	int value;
	struct node *left,*right;	
	int depth;
};
struct node *root=NULL;

void VISIT(struct node*t);
void  perorder(struct node*t);
struct node* creat_tree(struct node*t,int val,int dep);

int main()
{
	int n,i;
	int tempvalue=0;
	scanf("%d",&n) ;
	for(i=0;i<n;i++)
	{
		scanf("%d",&tempvalue);
		root=creat_tree(root,tempvalue,1);
	}
	perorder(root);
}

struct node* creat_tree(struct node* t,int val,int dep)
{
	if(t==NULL)
	{
		t=(struct node*)malloc(sizeof(struct node));
		t->left=NULL;
		t->right=NULL;
		t->value=val;
		t->depth=dep;
	}
	else if(val<t->value)
	{
		t->left=creat_tree(t->left,val,dep+1);
	}
	else
	{
		t->right=creat_tree(t->right,val,dep+1);
	}
	return t;
}
void  perorder(struct node*t)
{
      if(t!=NULL){
			perorder(t->left);     		
            if(t->left==NULL&&t->right==NULL) 
			VISIT(t);       /* 访问t指向结点  */
            perorder(t->right);
       }
}
void VISIT(struct node*t)
{
	printf("%d %d\n",t->value,t->depth);
}




