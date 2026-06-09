#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
typedef int Datatype;
typedef struct node{
	Datatype data;
	struct node *lchild, *rchild;
}BTNode, *BTNodeptr;
BTNodeptr insertBST(BTNodeptr p, Datatype item)
{
	if(p == NULL)
	{
		p = (BTNodeptr)malloc(sizeof(BTNode));
		p->data = item;
		p->lchild = p->rchild = NULL;
	}
	else if(item < p->data)
		p->lchild = insertBST(p->lchild, item);
	else if(item >= p->data)
		p->rchild = insertBST(p->rchild, item);
	//else//树中存在该元素 
		//do something
	return p;
}//将item插入根指针为root的二叉排序树中 
void print_BST(BTNodeptr root, int height)
{
	if(root == NULL)return;
	if(root->lchild != NULL) print_BST(root->lchild, height + 1);
	if(root->lchild == NULL && root->rchild == NULL)
	{
		printf("%d %d\n", root->data, height);
		return;
	}
	if(root->rchild != NULL) print_BST(root->rchild, height + 1);
}//从左到右打印叶结点及其高度 
int main()
{
	int i,item,n;
	BTNodeptr root = NULL;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
	{
		scanf("%d", &item);
		root = insertBST(root, item);
	}
	print_BST(root, 1);
	return 0;
 } 

