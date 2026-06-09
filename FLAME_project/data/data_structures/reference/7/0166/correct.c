#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
typedef int Datatype;
struct node {
	Datatype data;
	Datatype m;
	struct node* lchild, * rchild;
};
typedef struct node BTNode, * BTNodeptr;
BTNodeptr Root = NULL;
void insertBST(Datatype item) {
	BTNodeptr p, q;
	p = (BTNodeptr)malloc(sizeof(BTNode));
	p->data = item;
	p->m = 1;
	p->lchild = NULL;
	p->rchild = NULL;
	if (Root == NULL)
		Root = p;
	else
	{
		q = Root;
		while (1) {
			if (item < q->data) {
				if (q->lchild == NULL) {
					q->lchild = p;
					p->m=q->m+1 ;
					break;
				}
				else q = q->lchild;
			}
			else if (item >= q->data) {
				if (q->rchild == NULL) {
					q->rchild = p;
					p->m = q->m + 1;
					break;
				}
				else
					q = q->rchild;
			}
			else
			{
				break;
			}
		}
	}
}
void inorder(BTNodeptr t) {
	if (t != NULL) {
		//puts("...");
		inorder(t->lchild);
		if (t->lchild==NULL&&t->rchild==NULL)
		{
			printf("%d %d\n", t->data, t->m);
		}
		inorder(t->rchild);
	}
}
int main() {
	int n, i, item;
	BTNodeptr root = NULL;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &item);
		//puts(".");
		insertBST(item);
	}
	inorder(Root);
	return 0;
}

