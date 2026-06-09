#include<stdio.h>
#include<stdlib.h>
int  n, i = 0, a; //在遍历树的过程中表示当前深度。
typedef struct bitnode {
	int data;
	struct bitnode* lchild;
	struct bitnode* rchild;
	int deepth;
} bitree; //储存结点信息，指向左右子树的指针，以及该结点深度。

bitree* newBTNode(int x) {
	bitree *_btnode;
	_btnode = (bitree*)malloc(sizeof(bitree));
	_btnode->data = x;
	_btnode->lchild = NULL;
	_btnode->rchild = NULL;

	return _btnode;  //返回的是地址
}


bitree* insert(bitree* root, int x, int deep) {
	if (root == NULL) {      //插入的操作先看着为查找操作，而插入的地点就是查找失败的地点
		root = newBTNode(x);
		root->deepth = deep;
	} else {
		if (x < root->data) {
			deep++;  //如果插入的值比当前根根结点的值要小，就往左子树上面去找
			root->lchild = insert(root->lchild, x, deep);

		} else {
			deep++;                        //反之，就往右子树上面去找
			root->rchild = insert(root->rchild, x, deep);
		}
	}

	return root;
}
/* create */
bitree* createBST(int n) {
	bitree* root = NULL;
	int i = 0;
	while (i < n) {
		scanf("%d", &a);
		root = insert(root, a, 1);
		i++;
	}
	return root;
}

void preordertraverse( bitree* t) {
	if (t) {
		if (!(t->lchild) && !(t->rchild))printf("%d %d\n", t->data, t->deepth);
		preordertraverse(t->lchild);
		preordertraverse(t->rchild);
	}
}//先序遍历二叉树。


int main() {
	bitree* t;
	scanf("%d", &n);
	t = createBST(n);
	preordertraverse(t);
	return 0;
}

