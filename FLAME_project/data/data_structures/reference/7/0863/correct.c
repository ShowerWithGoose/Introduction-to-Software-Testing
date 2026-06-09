#include<stdio.h>
#include<string.h>
#include<stdlib.h> 
#include <ctype.h>
typedef struct TreeNode *BinTree;
struct TreeNode{
	int Data;// 插入
	int deep;
	BinTree Left;
	BinTree Right;
};
int len;int deepth=0;
int max(int a,int b)
{
	return (a>=b)?a:b;
}
BinTree Insert(int X,BinTree BST){
	
	deepth++;
	if(!BST){  // 如果为空，初始化该结点 
		BST = (BinTree)malloc(sizeof(struct TreeNode));
		BST->Data = X;
		BST->deep =deepth;
		BST->Left = NULL;
		BST->Right = NULL;
	}else{ // 不为空 
		if(X < BST->Data)  // 如果小，挂在左边 
		{
			BST->Left = Insert(X,BST->Left);
		}	
		else if(X >= BST->Data)  // 如果大，挂在右边 
		{
			BST->Right = Insert(X,BST->Right);
		}

	}
	deepth--;
	return BST;
} 

void Leaf(BinTree BST)
{
	
	if(BST->Left)
	Leaf(BST->Left);
	if(BST->Left==NULL&&BST->Right==NULL)
	printf("%d %d\n",BST->Data,BST->deep);
	if(BST->Right)
	Leaf(BST->Right);
}
 int getHeight(BinTree tree)
{
    if(tree==NULL)return 0;
    return max(getHeight(tree->Left),getHeight(tree->Left))+1;
}
int main()
{
	BinTree BST = NULL;
	int n;
	scanf("%d",&n);
	int i=0;int a;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		BST=Insert(a,BST);
	}
	len=getHeight(BST);
	Leaf(BST);
}

