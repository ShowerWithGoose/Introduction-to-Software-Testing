#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct temp {
	int data;
	int height;
	struct temp * left;
	struct temp * right;
} Node;

typedef struct tree {
	Node * root;
} Tree;

void insert(Tree* tree, int value) {
	Node* temp=(Node*)malloc(sizeof(Node));
	temp->data = value;
	temp->left = temp->right = NULL;
	temp->height=1;
	if (tree->root == NULL) {
		tree->root = temp;
	} else {
		Node* p = tree->root;
		while (p != NULL) {
			temp->height++;
			if(value < p->data) {
				if(p->left == NULL) {
					p->left = temp;
					return;
				} else {
					p = p->left;
				}
			} else {
				if(p->right == NULL) {
					p->right = temp;
					return;
				} else {
					p = p->right;
				}
			}
		}
	}
}

void traverse(Node* temp) {
	if(temp != NULL) {
		traverse(temp->left);
		if(temp->left==NULL&&temp->right==NULL) {
			printf("%d %d\n",temp->data,temp->height);
		}
		traverse(temp->right);
	}
}



int main() {
	Tree tree;
	tree.root=NULL;
	int N,number;
	scanf("%d",&N);
	int i;
	for(i=0; i<N; i++) {
		scanf("%d",&number);
		insert(&tree,number);
	}
	traverse(tree.root);
	return 0;
}



