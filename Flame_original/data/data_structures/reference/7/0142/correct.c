#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct node {
	int data;
	int height;
	struct node* left;
	struct node* right;
} Node;

typedef struct {
	Node* root;
} Tree;

void insert(Tree* tree,int value) {
	Node* node=malloc(sizeof(Node));
	node->data=value;
	           node->height=1;
	node->left=NULL;
	node->right=NULL;
	if(tree->root==NULL) {
		tree->root=node;
	} else {
		Node* temp=tree->root;
		while(temp!=NULL) {
			if(value<temp->data) {
				if(temp->left==NULL) {
					temp->left=node;
					node->height++;
					return;
				} else {
					temp=temp->left;
				}
			} else {
				if(temp->right==NULL) {
					temp->right=node;
					node->height++;
					return;
				} else {
					temp=temp->right;
				}
			}
			node->height++;
		}
	}
}
void postorder(Node* node){
	if(node!=NULL){
		postorder(node->left);
		postorder(node->right);
		if(node->left==NULL&&node->right==NULL)
		printf("%d %d\n",node->data,node->height);
	}
}
int main() {
	int n,i,num;
	Tree tree;
	tree.root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num);
		insert(&tree,num);
	}
	postorder(tree.root);
}

