#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	int deep;
	struct node *left, *right;
}; 
struct node* insert(struct node* p, int item);
struct node* search(struct node* root);
int h;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n, i, item;
	struct node *root = NULL, *q = NULL;
	scanf("%d", &n);
	for(i = 0;i < n;i++){
		h = 0;
		scanf("%d", &item);
		root = insert(root, item);
	}
	search(root);
	return 0;
}

struct node* insert(struct node* p, int item){
	h++;
	if(p == NULL){
		p = (struct node*)malloc(sizeof(struct node));
		p->data = item;
		p->deep = h;
		p->left = NULL;
		p->right = NULL;
	}
	else if(item < p->data){
		p->left = insert(p->left, item);
	}
	else if(item >= p->data){
		p->right = insert(p->right, item);
	}
	return p;
}

struct node* search(struct node* root){
	struct node* r = root;
	if(r->left != NULL){
		search(r->left);
	}
	if(r->right != NULL){
		search(r->right);
	}
	if(r->left == NULL && r->right == NULL){
		printf("%d %d\n", r->data, r->deep);
	}
}

