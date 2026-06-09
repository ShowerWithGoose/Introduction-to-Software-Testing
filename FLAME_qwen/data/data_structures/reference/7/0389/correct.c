#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
struct node {
	int data;
	int depth;
	struct node *lchild,*rchild;
};
typedef struct node BTNode,*BTNodeptr;
void insertBST(BTNodeptr *p, int item,int depth);
int n,i,item,depth=1;
BTNodeptr root=NULL;

void order(BTNodeptr p) {
	if(p!=NULL) {
		order(p->lchild);
		if(p->lchild==NULL && p->rchild==NULL)
			printf("%d %d\n",p->data,p->depth);    // 打印出叶子结点
		order(p->rchild);
	}
}
int main() {
	scanf("%d",&n);
	for(i=0; i<n; i++) { //构造一个有n个元素的BST树
		scanf("%d", &item);
		insertBST(&root, item,1);//逐个插入 
	}
	order(root);
	return 0;
}

void insertBST(BTNodeptr *p, int item,int depth) {
	if(*p == NULL) {
		*p = (BTNodeptr)malloc(sizeof(BTNodeptr));
		(*p)->data = item;
		(*p)->lchild = (*p)->rchild = NULL;
		(*p)->depth=depth;
	} else if( item < (*p)->data) {
		insertBST(&((*p)->lchild),item,depth+1);
	} else if( item >= (*p)->data) {
		insertBST(&((*p)->rchild),item,depth+1);
	}
}



