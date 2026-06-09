#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX_SIZE 512

typedef struct searchtree{
	int num;
	struct searchtree* left;
	struct searchtree* right;
} node, *nptr;
nptr root = NULL;

nptr Insert(int n, nptr p){
	if(p == NULL){
		p = (nptr)malloc(sizeof(node));
		p->num = n;
		p->right = NULL; p->left = NULL;
	}
	else {
		if(n < p->num)	p->left = Insert(n, p->left);
		else p->right = Insert(n, p->right);
	}
	return p;
}
void search(int depth, nptr p){
	if(p->left == NULL && p->right == NULL)
		printf("%d %d\n", p->num, depth);
	else {
		if(p->left != NULL) 
		search(depth + 1, p->left);
		if(p->right != NULL)
		search(depth + 1, p->right);
	}
}
void Ergodic(nptr p){
	if(p == NULL) return ;
	else{
		Ergodic(p->left);
		printf("%d-", p->num);
		Ergodic(p->right);
	}
}
int main(){
	int n; scanf("%d", &n);
	while(n--){
		int item;
		scanf("%d", &item);
		root = Insert(item, root);
	}
	//Ergodic(root);
	search(1, root);
	return 0;
} 



