#pragma warning(disable : 4996)
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct Tree {
	int depth;
	int iData;
	struct Tree* pLeft;
	struct Tree* pRight;
};

struct Tree* Insert(struct Tree* tree, int data, int depth);
void Look(struct Tree* tree);

int main(void) {

	int num = 0;
	scanf("%d", &num);
	struct Tree* root = NULL;
	int depth = 1;
	for (int i = 0; i < num; i++) {
		int data = 0;
		scanf("%d", &data);
		root = Insert(root, data, depth);
	}
	Look(root);
}

struct Tree* Insert(struct Tree* tree, int data, int depth) {
	struct Tree* pTemp = (struct Tree*)malloc(sizeof(struct Tree));
	pTemp->pLeft = NULL;
	pTemp->pRight = NULL;
	pTemp->iData = data;
	pTemp->depth = depth;
	depth++;
	if (tree == NULL)
		tree = pTemp;
	else if (data >= tree->iData)
		tree->pRight = Insert(tree->pRight, data, depth);
	else if (data < tree->iData) 
		tree->pLeft = Insert(tree->pLeft, data, depth);
	return tree;
}

void Look(struct Tree* tree) {
	if (tree == NULL)
		return;
	else {
		if (tree->pLeft == NULL && tree->pRight == NULL)
			printf("%d %d\n", tree->iData, tree->depth);
		Look(tree->pLeft);
		Look(tree->pRight);
	}
}
