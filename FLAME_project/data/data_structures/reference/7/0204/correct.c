#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 1024
struct search_tree{
	int data;
    struct search_tree *lchild,*rchild;
};
struct search_tree *build_tree(struct search_tree *root,int n);
void print_tree(struct search_tree *q,int n)
{
	if(q!=NULL)
	{
	    if(q->lchild==NULL&&q->rchild==NULL)
	    {
		    printf("%d %d\n",q->data,n);
	    }
	    else 
	    {
	        n++;
			print_tree(q->lchild,n);
	        print_tree(q->rchild,n);
	    }
    }
}
int main()
{
	int n,i,num,j=1;
	struct search_tree *root;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&num);
		root=build_tree(root,num);
	}
	print_tree(root,j);
	return 0;
}
struct search_tree *build_tree(struct search_tree *p,int n)
{
	if(p==NULL)
	{
		p=(struct search_tree *)malloc(sizeof(struct search_tree));
		p->data=n;
		p->lchild=NULL;
		p->rchild=NULL;
	}
	else if(n<p->data)
		p->lchild=build_tree(p->lchild,n);
	else if(n>=p->data)
	    p->rchild=build_tree(p->rchild,n);
	return p;
}


