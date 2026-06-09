#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct node{
	int number;
	int high;
	struct node* lchild;
	struct node* rchild;
};
typedef struct node num;
typedef struct node* numptr;

//建立二叉排序树 
numptr insertTrie(numptr T, int x, int h)
{
	h++;
	if(T == NULL)
	{
		T = (numptr)malloc(sizeof(num));
		T->number = x;
		T->high = h;
		T->lchild = NULL;
		T->rchild = NULL;
	}
	else
	{
		if(x < T->number)
			T->lchild = insertTrie(T->lchild, x, h);
		else
			T->rchild = insertTrie(T->rchild, x, h); 
	}
	return T;
}

//访问函数 
void visit(numptr T)
{
	if(T->lchild == NULL && T->rchild == NULL)	//只输出叶结点 
		printf("%d %d\n", T->number, T->high);
}

//中序遍历
void inorder(numptr T)
{
	if(T != NULL)
	{
		inorder(T->lchild);	//遍历左子树 
		visit(T);//访问T所指结点 
		inorder(T->rchild);	//访问右子树 
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	int i, x, h;
	numptr T = NULL;
	for(i = 0; i < n; i++)
	{
		scanf("%d", &x);
		h = 0; 
		T = insertTrie(T, x, h);
	}
	inorder(T);
	return 0;
}


