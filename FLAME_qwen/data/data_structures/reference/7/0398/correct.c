#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct tree
{
	int dat,deep;
	struct tree *lchild,*rchild;
}*root=NULL,*stack[36000];
int ans[36000][6],ru[36000],len=-1,top_ans=-1,top_stack=-1;
void visit(struct tree *T)
{
	ans[++top_ans][0]=T->dat;
	ans[top_ans][1]=T->deep;
}
struct tree*tree_f(struct tree*T,int a,int b)//递归插入（过于耗时） 
{
	if(T==NULL)
	{
		T=(struct tree*)malloc(sizeof(struct tree));
		T->dat=a;T->lchild=NULL;T->rchild=NULL;T->deep=b;
	}
	else
	{
		if(a>=T->dat)
			T->rchild=tree_f(T->rchild,a,b+1);
		else 
			T->lchild=tree_f(T->lchild,a,b+1);
	}
	return T;//注意，就算是malloc了，分配的空间也是给T的，而不是root的！！！！！！（易错）
}
void read_LDR();
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&ru[i]);
	for(i=0;i<n;i++)
		root=tree_f(root,ru[i],1);
	read_LDR();
	for(i=0;i<=top_ans;i++)
		printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}
void read_LDR()
{
	struct tree*p=root;
	do
	{
		for(;p!=NULL;p=p->lchild)
			stack[++top_stack]=p;
		p=stack[top_stack--];
		if(p->rchild==NULL&&p->lchild==NULL)
			visit(p);
		p=p->rchild;
	}while(!(p==NULL&&top_stack==-1));
}



