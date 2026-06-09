#include<stdio.h>
#include<stdlib.h>
struct tnode{
	struct tnode *lchild,*rchild;
	int data;
};//树就是更复杂的表
//递归创建二叉树，数据储存
struct tnode*create(struct tnode*root,int a)
{
	if(root==NULL)
	{
		root=(struct tnode*)malloc(sizeof(struct tnode));
		root->data=a;
		root->lchild=NULL;
		root->rchild=NULL;
		return root;
		//最初的那个节点永远不变
	}
	else{
		if(a<root->data){
		//不要开空间！到时候自己会开！！！啊啊啊！
		root->lchild=create(root->lchild,a);}
		else
		{
		root->rchild=create(root->rchild,a);
		}//root是一直不变的，通过递归找存放位置。
		return root;
	}
}
int main()
{
	int n;
	int a;
	scanf("%d\n",&n);
	struct tnode *root=NULL;
	while(n--)
	{
		scanf("%d",&a);
		root=create(root,a);
	}
	int tall=1;
	shuchu(root,tall);
	return 0;
}
//只要输出叶节点就可以，而且是从左到右，可以后序遍历
void shuchu(struct tnode*root,int tall)
{
	if(root->lchild!=NULL)
	shuchu(root->lchild,(tall+1));//这里不要用加加！！！！！
	if(root->rchild!=NULL)
	shuchu(root->rchild,(tall+1));
  else if(root->rchild==NULL&&root->lchild==NULL)
	printf("%d %d\n",root->data,tall);
}

