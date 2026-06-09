#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
typedef struct node{
	int number;
	int deep;
	struct node *left;
	struct node *right;
}tree;
tree *root;
int n;
int i = 0;
int tmp;
int dep = 1;
void print(tree* t){
	printf("%d %d\n",t -> number,t -> deep);
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
tree* build(tree *t,int tmp,int dep);
int main(){
	root = NULL;
	scanf("%d",&n);
	while(i < n){
		scanf("%d",&tmp);
		root = build(root,tmp,dep);
		i++;
	}
	read(root);
	return 0;
}
tree* build(tree *t,int tmp,int dep){
	if(t == NULL){
		t = (tree*)malloc(sizeof(tree));
		t -> left = t -> right = NULL;
		t -> number = tmp;
		t -> deep = dep;
	}
	else if(tmp < t -> number){
		t -> left = build(t -> left,tmp,dep+1);
	}
	else if(tmp >= t -> number){
		t -> right = build(t -> right,tmp,dep+1);
	}
	return t;
}
