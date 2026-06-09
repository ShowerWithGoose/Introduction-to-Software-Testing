#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct node {
	int data;
	int height;
	struct node * left;
	struct node * right;
} Node;

typedef struct tree {
	Node * root;
} Tree;

void insert(Tree* tree, int value) {
	Node* node=(Node*)malloc(sizeof(Node));
	node->data = value;
	node->left = node->right = NULL;
	node->height=1;
	if (tree->root == NULL) {
		tree->root = node;
	} else {
		Node* N = tree->root;
		while (N != NULL) {
			node->height++;
			if(value < N->data) {
				if(N->left == NULL) {
					N->left = node;
					return;
				} else {
					N = N->left;
				}
			} else {
				if(N->right == NULL) {
					N->right = node;
					return;
				} else {
					N = N->right;
				}
			}
		}
	}
}

void traverse(Node* node) {
	if(node != NULL) {
		traverse(node->left);
		if(node->left==NULL&&node->right==NULL) {
			printf("%d %d\n",node->data,node->height);
		}
		traverse(node->right);
	}
}



int main() {
	Tree tree;
	tree.root=NULL;
	int N,data;
	scanf("%d",&N);
	int i;
	for(i=0; i<N; i++) {
		scanf("%d",&data);
		insert(&tree,data);
	}
	traverse(tree.root);
	return 0;
}



