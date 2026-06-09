#include<malloc.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

struct Tree {
	int weight;
	struct Tree* left, * right;
};
struct Tree* node;
int depth = 1;

struct Tree* creat(int num) {
	struct Tree* p = (struct Tree*)malloc(sizeof(struct Tree));
	p->left = p->right = NULL;
	p->weight = num;
	return p;
}

struct Tree* insert(struct Tree* node, int num) {
	if (node == NULL) {
		node = creat(num);
	}
	else {
		if (num < node->weight) {
			node->left = insert(node->left, num);
		}
		else {
			node->right = insert(node->right, num);
		}
	}
	return node;
}

void dfs(struct Tree* node) {
	if (node->left == NULL && node->right == NULL) {
		printf("%d %d\n", node->weight, depth);
	}
	else {
		depth++;
		if (node->left != NULL) {
			dfs(node->left);
		}
		if (node->right != NULL) {
			dfs(node->right);
		}
		depth--;
	}
}

int main() {
	int n;
	scanf("%d", &n);
	int w;
	struct Tree* tree = NULL;
	while (n--) {
		scanf("%d", &w);
		tree = insert(tree, w);
	}
	dfs(tree);
	return 0;
}
