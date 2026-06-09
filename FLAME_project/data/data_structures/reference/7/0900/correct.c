#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
	int data;
	struct node* lchild, *rchild;
};
typedef struct node btnode, *btnodeptr;
btnodeptr head = NULL;
int mark = 0;
btnodeptr insert(btnodeptr p, int item){
	if(p == NULL&&mark == 0){
		p = (btnodeptr)malloc(sizeof(btnode));
		p->data = item;
		p->lchild = NULL;
		p->rchild = NULL;
		head = p;
		mark = 1;
	}else
	if(p == NULL&&mark == 1)
	{
		p = (btnodeptr)malloc(sizeof(btnode));
		p->data = item;
		p->lchild = NULL;
		p->rchild = NULL;
	}else
	if(item < p->data)
	{
		p->lchild = insert(p->lchild, item);
	}else
	if(item >= p->data)
	{
		p->rchild = insert(p->rchild, item);
	}else
	{
		return p;
	}
		return p;
	
}
btnodeptr getleaves(btnodeptr q, int h)
{	
	if(q->lchild){
		getleaves(q->lchild, h+1);
	}
	if(q->lchild == NULL && q->rchild == NULL)
	{
		printf("%d %d\n", q->data, h);
	}
	if(q->rchild)
	{
		getleaves(q->rchild, h+1);
	}
	return q;
}
int main()
{	
	btnodeptr root = NULL;
	int n, i, item;;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &item);
		root = insert(root, item);
	}
	getleaves(head, 1);
	return 0;
}



