#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct points{
	int num;
	struct points *left;
	struct points *right;
	int n;
}point;

void creat(point* base,int number){
	if(base->num>number){
		if(base->left==NULL){
			base->left=(point *)malloc(sizeof(point));
			base->left->num=number;
			base->left->n=base->n+1;
			base->left->left=base->left->right=NULL;
		}
		else{
			creat(base->left,number);
		}
	}
	else {
		if(base->right==NULL){
			base->right=(point *)malloc(sizeof(point));
			base->right->num=number;
			base->right->n=base->n+1;
			base->right->left=base->right->right=NULL;
		}
		else{
			creat(base->right,number);
		}
	}
}

void print(point *node){
	if(node->left==NULL&&node->right==NULL)
		printf("%d %d\n",node->num,node->n);
	else{
		if(node->left!=NULL)
			print(node->left);
		if(node->right!=NULL)
			print(node->right);
	}
}

int main() {
	point *base, *item;
	int n,x;
	scanf("%d",&n);
	scanf("%d",&x);
	base=(point *)malloc(sizeof(point));
	base->num =x;
	base->n=1;
	base->right=base->left=NULL;
	item=base;
	for(n-=1;n>0;n--){
		scanf("%d",&x);
		creat(item,x);
	}
	print(base);	
	return 0;
}

