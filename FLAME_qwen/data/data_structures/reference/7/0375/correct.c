#include <stdio.h>
struct node{
	int num;
	int height;
	struct node* lchild, *rchild;
};
typedef struct node BTNode, *BTNodeptr;
BTNodeptr insertBST(BTNodeptr p, int num, int height){
	height++;
	if (p==NULL){
		p=(BTNodeptr*)malloc(sizeof (BTNode));
		p->num = num;
		p->height=height;
		p->lchild =p->rchild = NULL;
	}
	else if (num < p->num){
		p->lchild = insertBST(p->lchild, num, height);
	}
	else if (num >= p->num){
		p->rchild = insertBST(p->rchild, num, height);
	}
	
	return p;
}
int preorder(BTNodeptr p){
	
	if (p!=NULL){
		if (p->lchild == NULL && p->rchild == NULL){
			printf("%d %d\n", p->num, p->height);
		}
		preorder(p->lchild);
		preorder(p->rchild);
	}
}
int main(){
	int n;
	scanf("%d", &n);
	int i=0;
	int num=0;
	int height=0;
	BTNodeptr root=NULL;
	for (i=0; i<n; i++){
		scanf("%d", &num);
		root = insertBST(root, num, height);
	}
	preorder(root);
	return 0;
}

