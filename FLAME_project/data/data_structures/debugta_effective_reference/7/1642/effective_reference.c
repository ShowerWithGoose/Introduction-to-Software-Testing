#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
typedef struct node{
	int number;
	int depth;
	struct node *left;
	struct node *right;
}tree;
tree *root;
int n;
int i = 0;
int m;
int dep = 1;
void print(tree* t){
	printf("%d %d\n",t -> number,t -> depth);
}
void read(tree* t){
	if(t != NULL){
		read(t -> left);
		if(t->left == NULL&&t->right == NULL){
			print(t);
		}
		read(t -> right);
	}
}
tree* build(tree *t,int m,int dep);
int main(){
	root = NULL;
	scanf("%d",&n);
	while(i < n){
		scanf("%d",&m);
		root = build(root,m,dep);
		i++;
	}
	read(root);
	return 0;
}
tree* build(tree *t,int m,int dep){
	if(t == NULL){
		t = (tree*)malloc(sizeof(tree));
		t -> left = t -> right = NULL;
		t -> number = m;
		t -> depth = dep;
	}
	else if(m < t -> number){
		t -> left = build(t -> left,m,dep+1);
	}
	else if(m >= t -> number){
		t -> right = build(t -> right,m,dep+1);
	}
	return t;
}
