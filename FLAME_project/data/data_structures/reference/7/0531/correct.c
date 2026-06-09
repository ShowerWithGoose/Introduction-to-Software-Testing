#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int tree[100000]={0};
typedef struct forest
	{
		int num;
		int deep; 
        struct forest *lchild;
		struct forest *rchild;
	
	} Tree;
void insert(int a,Tree*p)
{
	if(p->num==-10000000) 
	{   p->num=a;
		p->lchild=(Tree*)malloc(sizeof(p));
		p->rchild=(Tree*)malloc(sizeof(p));
		p->lchild->num=-10000000; 
		p->rchild->num=-10000000;
		p->lchild->deep=p->rchild->deep=p->deep+1;
        
        
	}
	else  
	{	
	
	if(p->num>a)
	insert(a,p->lchild);
	else
	insert(a,p->rchild);
	}
	
}
void output(Tree *p)
{
	if((p->lchild->num==-10000000)&&(p->rchild->num==-10000000))
	{

	printf("%d %d\n",p->num,p->deep);
}
	else
	{   
	   
	    if(p->lchild->num!=-10000000) 
		output(p->lchild);
		if(p->rchild->num!=-10000000) 
		output(p->rchild);
	
      

}
}
int main()
{
	int n;
	scanf("%d",&n);
	int i=0;
	for(i=0;i<n;i++)
	scanf("%d",&tree[i]);
	Tree *root,*p;
	root=(Tree*)malloc(sizeof(p));
	root->num=-10000000;
	root->deep=1;
	for(i=0;i<n;i++)
	insert(tree[i],root);
	output(root);
	return 0;
	
 } 

