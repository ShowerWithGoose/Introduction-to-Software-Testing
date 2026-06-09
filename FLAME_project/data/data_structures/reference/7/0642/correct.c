#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node,*ptrnode;
ptrnode build_tree(int num,ptrnode tmp){
	if(tmp == NULL){
		tmp = (ptrnode)malloc(sizeof(node));
		tmp->data = num;
		tmp->left = NULL;
		tmp->right = NULL;
		return tmp;
	}
	else if(tmp->data > num){
		tmp->left = build_tree(num,tmp->left);
	}
	else if(tmp->data <= num){
		tmp->right = build_tree(num,tmp->right);
	}
	return tmp;
}
void find(ptrnode tmp,int floot){
	if(tmp->left == tmp->right &&tmp->left == NULL){
		printf("%d %d\n",tmp->data,floot);
		return ;
	}
	if(tmp->left!=NULL){
		find(tmp->left,floot+1);
	}
	if(tmp->right!=NULL){
		find(tmp->right,floot+1);
	}
}
int main(){
	int n,i,floot = 1,num;
	ptrnode head = NULL;
	scanf("%d",&n);
	for(i = 0;i < n;i++){
		scanf("%d",&num);
		head = build_tree(num,head);
	}
	find(head,floot);
	return 0;
}

