#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct node {
	int data;
	int high;
	struct node *lchild,*rchild;
};
typedef struct node *BTNodeptr;
typedef struct node BTNode;

BTNodeptr  root=NULL;
int hight;
BTNodeptr  insertBST(BTNodeptr p, int item);
void treePrint(BTNodeptr p);
int main() {
	int i, n, item;
	scanf("%d",&n);
	for(i=0; i<n; i++) { //构造一个有10个元素的BST树
		scanf("%d", &item);
		root = insertBST(root, item);
		hight=0;
	}
	treePrint(root);
	return 0;
}

BTNodeptr  insertBST(BTNodeptr p, int item) {
	hight++;
	if(p == NULL) {
		p = (BTNodeptr)malloc(sizeof(BTNode));
		p->data = item;
		p->high=hight;
		p->lchild = p->rchild = NULL;
	} 
	else if( item < p->data)
		p->lchild = insertBST(p->lchild, item);
	else if( item >= p->data)
		p->rchild = insertBST(p->rchild,item);
	return p;
}
void treePrint(BTNodeptr p){
	if(p!=NULL){
		treePrint(p->lchild);
		if(p->lchild==NULL&&p->rchild==NULL)
			printf("%d %d\n",p->data,p->high);
		treePrint(p->rchild); 
	}
}

