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
		Node* temp = tree->root;
		while (temp != NULL) {
			node->height++;
			if(value < temp->data) {
				if(temp->left == NULL) {
					temp->left = node;
					return;
				} else {
					temp = temp->left;
				}
			} else {
				if(temp->right == NULL) {
					temp->right = node;
					return;
				} else {
					temp = temp->right;
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
	int N,num;
	scanf("%d",&N);
	int i;
	for(i=0; i<N; i++) {
		scanf("%d",&num);
		insert(&tree,num);
	}
	traverse(tree.root);
	return 0;
}



