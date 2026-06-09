#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
typedef struct node{
	int value;
	int deep;
	struct node *left;
	struct node *right;
}tree;
tree *Tree;
int a;
int i = 0;
int tmp;
int l = 1;
void print(tree* t){
	printf("%d %d\n",t -> value,t -> deep);
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
tree* build(tree *t,int tmp,int l);
int main(){
	Tree = NULL;
	scanf("%d",&a);
	while(i < a){
		scanf("%d",&tmp);
		Tree = build(Tree,tmp,l);
		i++;
	}
	read(Tree);
	return 0;
}
tree* build(tree *t,int tmp,int l){
	if(t == NULL){
		t = (tree*)malloc(sizeof(tree));
		t -> left = t -> right = NULL;
		t -> value = tmp;
		t -> deep = l;
	}
	else if(tmp < t -> value){
		t -> left = build(t -> left,tmp,l+1);
	}
	else if(tmp >= t -> value){
		t -> right = build(t -> right,tmp,l+1);
	}
	return t;
}
