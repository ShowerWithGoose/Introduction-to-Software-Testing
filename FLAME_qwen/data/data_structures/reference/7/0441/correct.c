#include <stdio.h>
#include <stdlib.h>

int index;

struct node
{
	int value;
	int depth;
	struct node *lchild, *rchild;
};
typedef struct node BTNode, *BTNodeptr;

BTNodeptr root = NULL;

BTNodeptr insert(BTNodeptr p, int item)
{
	if(p == NULL){
		p = (BTNodeptr)malloc(sizeof(BTNode));
		p->value = item;
		index ++;
		p->depth = index;
		p->lchild = p->rchild = NULL;
		index = 0;
	}
	else if(p->value > item){
		index ++;
		p->lchild = insert(p->lchild, item);
		//index ++;
	}
	else if(item >= p->value){
		index ++;
		p->rchild = insert(p->rchild, item);
		//index ++;
	}
	return p;
}

void preorder(BTNodeptr p)
{
	if(p != NULL){
			if(p->lchild == NULL && p->rchild == NULL){
				//printf("%d ", p->value);
				printf("%d %d\n", p->value, p->depth);
			}
			preorder(p->lchild);
			preorder(p->rchild);
	}

}

int main ()
{
	int n;
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i ++){
		int x;
		scanf("%d", &x);
		root = insert(root, x);
	}
	//printf("%d %d", root->lchild->rchild->value, root->rchild->rchild->rchild->value);
	preorder(root);
	return 0;
}

