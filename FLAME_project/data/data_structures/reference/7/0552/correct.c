#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define LEN sizeof(SearchTree)
typedef struct TreeNode/*定义二叉查找树结点结构体*/
{
	int data;
	struct TreeNode *left;
	struct TreeNode *right;
}SearchTree;
SearchTree *roota;
SearchTree *MakeEmpty(SearchTree *T)/*初始化*/
{
	if(T!=NULL)
	{
		MakeEmpty(T->left);
		MakeEmpty(T->right);
		free(T);
	}	
	return NULL;
}
SearchTree *Insert(int x,SearchTree *T)/*插入*/
{
	if(T==NULL)/*找到了插入的位置*/
	{
		T=(SearchTree *)malloc(LEN);
		T->data=x;
		T->left=T->right=NULL;
	}
	else
	{
		if(x<T->data)
			T->left=Insert(x,T->left);
		else
			T->right=Insert(x,T->right);	
	}
	return T;
}
int Find(int x,SearchTree *T)/*求叶子结点的长度*/
{
	if(T==NULL)/*为空树*/
		return 0;
	if(x<T->data)/*进左子树*/
		return Find(x,T->left)+1;
	else
		return Find(x,T->right)+1;
}
void output(SearchTree *T)
{
	int len;
	if(T!=NULL)
	{
		if(T->left==NULL && T->right==NULL)/*为叶子结点*/
		{
		    len=Find(T->data,roota);
			printf("%d %d\n",T->data,len);
		}
		else
		{
			output(T->left);
			output(T->right);
		}
	}
}
int main()
{
	int n,i,x;
	SearchTree *root=NULL;
	MakeEmpty(root);
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		root=Insert(x,root);
	}
	roota=root;
	output(root);
	return 0 ;
}

