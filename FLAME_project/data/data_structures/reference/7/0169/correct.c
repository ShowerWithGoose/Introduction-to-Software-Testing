#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int datatype;
typedef struct node
{
	datatype data;//模板 
	datatype h;
	datatype cnt;
	struct node *lchild, *rchild;
} *BTREE, BTNode;//建立指针和结构体类型 

BTREE root = NULL;

void INSTREE(BTREE r, BTREE p)//插入一个节点 
{
	if (r == NULL)
	{
		root = p;
		return;//指针赋值 
	}
	
	/*
	if (p->data == r->data)
	{
		r->cnt++;
		free(p);
	} else //注意大于等于的条件 
	*/
	
	if(p->data < r->data)
	{
		if (r->lchild == NULL)
		{
			r->lchild = p;
			p->h = r->h + 1;
			return;
		}
		INSTREE(r->lchild, p);
	}
	else
	{
		if (r->rchild == NULL)
		{
			r->rchild = p;
			p->h = r->h + 1;
			return;
		}
		INSTREE(r->rchild, p);
	}	
}

void TRANSTREE(BTREE r)//遍历 
{
	
	if (r->lchild == NULL && r->rchild == NULL)
	{
		printf("%d %d\n", r->data, r->h); 
		return;
	}
	else if(r->lchild == NULL)
	{
		TRANSTREE(r->rchild);
	}
	else if(r->rchild == NULL)
	{
		TRANSTREE(r->lchild);
	}
	else
	{
		TRANSTREE(r->lchild);
		TRANSTREE(r->rchild);
	}//四种情况必有一种 
}

int main()
{
	BTREE p = NULL, q = NULL, r = NULL;
	int n, i, num;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d", &num);
		p = (BTREE)malloc(sizeof(BTNode));
		p->data = num;
		p->cnt = 1;
		p->h = 1;
		p->lchild = NULL;
		p->rchild = NULL;//初始化
		INSTREE(root, p);//可能有问题 
	}
	if (root != NULL)
	{
		TRANSTREE(root);
	}
	return 0;
}

