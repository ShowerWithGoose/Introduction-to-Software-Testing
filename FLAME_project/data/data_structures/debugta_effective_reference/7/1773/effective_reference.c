#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct tree
{
	int dat,deep;
	struct tree *lchild,*rchild;
}*root=NULL,*stack[36000];
int ans[36000][6],dat[36000],len=-1,top_ans=-1,top_stack=-1;
void visit(struct tree *T)
{
	ans[++top_ans][0]=T->dat;
	ans[top_ans][1]=T->deep;
}
struct tree*create(struct tree*T,int a,int b)//递归插入（过于耗时） 
{
	if(T==NULL)
	{
		T=(struct tree*)malloc(sizeof(struct tree));
		T->dat=a;T->lchild=NULL;T->rchild=NULL;T->deep=b;
	}
	else
	{
		if(a>=T->dat)
			T->rchild=create(T->rchild,a,b+1);
		else 
			T->lchild=create(T->lchild,a,b+1);
	}
	return T;//注意，就算是malloc了，分配的空间也是给T的，而不是root的！！！！！！（易错）
}
void inorder();
int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&dat[i]);
	for(i=0;i<n;i++)
		root=create(root,dat[i],1);
	inorder();
	for(i=0;i<=top_ans;i++)
		printf("%d %d\n",ans[i][0],ans[i][1]);
	return 0;
}
void inorder()
{
	struct tree*T=root;
	do
	{
		for(;T!=NULL;T=T->lchild)
			stack[++top_stack]=T;
		T=stack[top_stack--];
		if(T->rchild==NULL&&T->lchild==NULL)
			visit(T);
		T=T->rchild;
	}while(!(T==NULL&&top_stack==-1));
}



