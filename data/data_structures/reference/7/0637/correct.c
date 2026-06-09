#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
typedef struct a{
	int num;
	struct a* left;
	struct a* right;
}node, *link;
link creat_a_tree(link root, int putin);
void print_leaf(link root, int hight);
int main(){
	int n, i, putin;
	link root = NULL, p = NULL;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &putin);
		root = creat_a_tree(root, putin);
	}
	print_leaf(root, 1);
	return 0;
}

link creat_a_tree(link root, int putin){
	link p;
	if (root == NULL){
		p = (link)malloc(sizeof(node));
		p->num = putin; p->left = p->right = NULL;
		return p;
	}
	else{
		if (putin < root->num)  root->left = creat_a_tree(root->left, putin);
		else  root->right = creat_a_tree(root->right, putin);
	}
	return root;
}

void print_leaf(link root, int hight){
	if (root->left == NULL && root->right == NULL)  printf("%d %d\n", root->num, hight);
	else{
		if (root->left != NULL)  print_leaf(root->left, hight + 1);
		if (root->right != NULL)  print_leaf(root->right, hight + 1);
	}
}


