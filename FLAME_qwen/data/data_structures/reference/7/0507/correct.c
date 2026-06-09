#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX 1000

typedef struct Tree{
	int elem;
	struct Tree *left,*right;
}tree;

int n, num[MAX], i; 
tree* p;

void build_tree(tree* p,int num);
void write_leaves();

int main(){
	scanf("%d",&n);
	for (i = 0; i < n; i++)
		scanf("%d",&num[i]);
	p = (tree*)malloc(sizeof(tree));
	p->left = NULL;
	p->right = NULL;
	p->elem = num[0];
	for (i = 1; i < n; i++)
		build_tree(p,num[i]);
	write_leaves(p, 1);
	return 0;
}

void build_tree(tree* p,int num){
	if(p->elem > num){
		if(p->left == NULL){
			tree* temp = (tree*)malloc(sizeof(tree));
			p->left = temp;
			temp->elem = num;
			temp->left = NULL;
			temp->right = NULL;
			return ;
		}
		else
			build_tree(p->left, num);
	}
	else if(p->elem <= num){
		if(p->right == NULL){
			tree* temp = (tree*)malloc(sizeof(tree));
			p->right = temp;
			temp->elem = num;
			temp->left = NULL;
			temp->right = NULL;
			return ;
		}
		else 
			build_tree(p->right, num);
	}
} 


void write_leaves(tree* p,int layer){
	tree* temp = p;
	if(p->left == NULL&& p->right == NULL){
		printf("%d %d\n",p->elem,layer);
		return ;
	}
	if(p->left != NULL)
		write_leaves(p->left, layer + 1);
	if(p->right != NULL)
		write_leaves(p->right, layer + 1);
	return ;
}

