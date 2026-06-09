#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct binaryTreeNode{
	int element;
	int high;
	struct binaryTreeNode* LChild;
	struct binaryTreeNode* RChild;
}Node;

typedef struct binarySearchTree{
	struct binaryTreeNode* root;
	int size;
}BTree;

Node* createNode(int data){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->element = data;
	newNode->LChild = NULL;
	newNode->RChild = NULL;
	return newNode;
}

BTree* createbinarySearchTree(){
	BTree* tree = (BTree*)malloc(sizeof(BTree));
	tree->root = NULL;
	tree->size = 0;
	return tree;	 
} 

void insertNode(BTree* tree,int data){
	Node* MoveNode = tree->root;
	Node* MoveParentNode = NULL;
	int hi = 0;
	while(MoveNode != NULL){
		hi++;
		MoveParentNode = MoveNode;
		if(data < MoveNode->element){
			MoveNode = MoveNode->LChild;
		}
		else{
			MoveNode = MoveNode->RChild;
		}
	}
	Node* newNode = createNode(data);
	if(tree->root == NULL){
		tree->root = newNode;
		newNode->high = 1;
	}
	else{
		hi++;
		newNode->high = hi;
		if(data < MoveParentNode->element)
			MoveParentNode->LChild = newNode;
		else
			MoveParentNode->RChild = newNode;
	}
}

void arfOrder(Node* root){
	if(root != NULL){
		arfOrder(root->LChild);
		arfOrder(root->RChild);
		if(root->LChild == NULL&&root->RChild == NULL){
			printf("%d %d\n",root->element,root->high);
		}
	}
}

void printTree(BTree* tree){
	arfOrder(tree->root);
}

int main() {
	int n,num;
	scanf("%d",&n);
	BTree* tree = createbinarySearchTree();
	for(int i = 0;i < n;i++){
		scanf("%d",&num);
		insertNode(tree,num);
	}
	printTree(tree);
	return 0;
}

