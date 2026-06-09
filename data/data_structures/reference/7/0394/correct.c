#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Tree{
	int num;
	struct tree* l;
	struct tree* r;
	int deep;
};
typedef struct Tree tree;
typedef struct Tree* treep;
treep create_tree(treep p,int a,int deep)
{
	
	if(p==NULL)
	{
		p=(treep)malloc(sizeof(tree));        //在这一步中 貌似我赋值之后 p还是NULL 那么下次递归的时候 他还会默认 这个树是空的 不会进行大小的比较  
		p->num=a;
		p->l=NULL;
		p->r=NULL;
		p->deep=deep;
	}
	else if(a<p->num)
	{
		deep++;
		p->l=create_tree(p->l,a,deep);
	}
	else if(a>=p->num)
	{
		deep++;
		p->r=create_tree(p->r,a,deep);
	}
	return p;
}
void visit_tree(treep p)
{
	if(p->l==NULL&&p->r==NULL)
	printf("%d %d\n",p->num,p->deep);
		if(p->l!=NULL)
		visit_tree(p->l);
		if(p->r!=NULL)
		visit_tree(p->r);
	
}

int main ()
{
	treep root=NULL,p=NULL;
	int n,a;
	scanf("%d",&n);
	int i,j,k;
	for(i=0;i<n;i++)
	{
		int deep=1;
		scanf("%d",&a);
		root=create_tree(root,a,deep);
	}
//	p=root;
//	for(;p->l!=NULL;p=p->l)
//	printf("%d\n",p->num);
	visit_tree(root);
	
		
	return 0;
 } 

