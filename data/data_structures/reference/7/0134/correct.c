#include<stdio.h>
#include<time.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define ll long long

typedef int Datatype;
struct node {
	Datatype data;
	int h;
	struct node *lchild, *rchild;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr  insertBST(BTNodeptr p, Datatype item,int deep);

void  inorder(BTNodeptr t) {
	if(t!=NULL) {
		inorder(t->lchild);
		if(t->lchild ==NULL&&t->rchild ==NULL)      /* 访问T指结点  */
		printf("%d %d\n",t->data ,t->h );
		inorder(t->rchild);
	}
}
int i, item,n;
int main() {
	
	BTNodeptr  root=NULL;
	scanf("%d",&n);
	for(i=0; i<n; i++) { //构造一个有10个元素的BST树
		scanf("%d", &item);
		root = insertBST(root, item,1);
	}
	inorder(root);
	return 0;
}
BTNodeptr  insertBST(BTNodeptr p, Datatype item,int deep) {
	if(p == NULL) {
		p = (BTNodeptr)malloc(sizeof(BTNode));
		p->data = item;
		p->h =deep;
		p->lchild = p->rchild = NULL;
	} else if( item < p->data)
		p->lchild = insertBST(p->lchild, item,deep+1);
	else if( item >= p->data)
		p->rchild = insertBST(p->rchild,item,deep+1);
	return p;
}

