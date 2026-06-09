#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 150
#include<stdio.h>
#include<stdlib.h>
typedef struct TREE {
	int data;
	int layer;
	struct TREE* lchild;
	struct TREE* rchild;
}Tree;
void TREE_BUILD(Tree* T, int data);
void VISIT(Tree* p);
void SEARCH(Tree* T);
int main() {
	Tree* T = NULL;
	int N = 0, data = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf(" %d", &data);
		Tree* p = NULL, * q = NULL;
		p = (Tree*)malloc(sizeof(Tree));
		if (p == NULL) {
			printf("error!\n");
			return 0;
		}
		p->data = data;
		p->lchild = p->rchild = NULL;
		if (T == NULL) {
			T = p;//若树为空，直接建树根
			T->layer = 1;
		}
		else {
			q = T;
			int lay = 1;//从根节点开始走
			while (1) {
				if (data < q->data) {//值比根节点值小，往左子树走
					if (q->lchild != NULL) {
						q = q->lchild;
						lay++;//下一层
					}
					else {
						q->lchild = p;
						lay++;//成为新一层
						q->lchild->layer = lay;
						break;//找到，插入并跳出循环
					}
				}
				else {//值比根节点大，往右子树走
					if (q->rchild != NULL) {
						q = q->rchild;
						lay++;//下一层
					}
					else {
						q->rchild = p;
						lay++;
						q->rchild->layer = lay;
						break;
					}
				}
			}
		}
	}//创建二叉排序树
	SEARCH(T);
	return 0;
}
void TREE_BUILD(Tree* T, int data) {
	Tree* p = NULL, * q = NULL;
	p = (Tree*)malloc(sizeof(Tree));
	if (p == NULL) {
		printf("error!\n");
		return;
	}
	p->data = data;
	p->lchild = p->rchild = NULL;
	if (T == NULL) {
		T = p;
		return;//若树为空，直接建树根
	}
	q = T;
	while (1) {
		if (data < q->data) {//值比根节点值小，往左子树走
			if (q->lchild != NULL) {
				q = q->lchild;
			}
			else {
				q->lchild = p;
				break;//找到，插入并跳出循环
			}
		}
		else {//值比根节点大，往右子树走
			if (q->rchild != NULL) {
				q = q->rchild;
			}
			else {
				q->rchild = p;
				break;
			}
		}
	}
}
void VISIT(Tree* p) {
	if (p->lchild == NULL && p->rchild == NULL) {
		printf("%d %d\n", p->data, p->layer);
	}
	else return;
}
void SEARCH(Tree* T) {
	Tree* stack[MAX];
	Tree* p = T;
	int top = -1;
	if (p == NULL) {
		printf("empty!\n");
		return;
	}
	else {
		do {
			while (p != NULL) {
				stack[++top] = p;
				p = p->lchild;
			}//跳出时此栈顶节点无左子树
			p = stack[top--];
			VISIT(p);
			p = p->rchild;
		} while (p != NULL || top != -1);
	}
}

