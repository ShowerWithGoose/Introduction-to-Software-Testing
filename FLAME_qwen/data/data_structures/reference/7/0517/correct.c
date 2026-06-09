#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
int h[BUFSIZ] = {0};
int nn = 1;
typedef struct tree
{
	int n;
	int h0;
	struct tree *left, *right;
}TREE, *Trees;

static Trees searching(Trees *root, int del)
{
	Trees s, p = *root;
	int n1 = 1;
	while(p){
		n1++;
		s = p;
	    p = (del < p->n)?(p->left):(p->right);
	}
	s->h0 = n1;
	return s;
}
void insert(Trees *root, int del)
{
	Trees s, p;
	s = malloc(sizeof(struct tree));
	s->n = del;
	s->left = NULL;
	s->right = NULL;
	if(*root == NULL){
		s->h0 = 1;
		*root = s;
	}
	else{
		p = searching(root, del);
		if(del < p->n){
			p->left = s;
		}
		else{
			p->right = s;
		}
		s->h0 = (p->h0) ++;
	}
}
void print(Trees *root)
{
	if((*root) == NULL){
		return;
	}
	if((*root)->left == NULL && (*root)->right == NULL){
		printf("%d %d\n", (*root)->n, (*root)->h0);
	}
	else{
		print(&(*root)->left);
		print(&(*root)->right);
	}
}
int main()
{
	int n0;
	int i, j, del;
	Trees root = NULL;
	scanf("%d", &n0);
	for(i = 0; i < n0; i++){
		scanf("%d", &del);
		insert(&root, del);
	}
	print(&root);
	return 0;
}



