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
		Node* node = tree->root;
		while (node != NULL) {
			node->height++;
			if(value < node->data) {
				if(node->left == NULL) {
					node->left = node;
					return;
				} else {
					node = node->left;
				}
			} else {
				if(node->right == NULL) {
					node->right = node;
					return;
				} else {
					node = node->right;
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
	int n,num;
	scanf("%d",&n);
	int i;
	for(i=0; i<n; i++) {
		scanf("%d",&num);
		insert(&tree,num);
	}
	traverse(tree.root);
	return 0;
}



