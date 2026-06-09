#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node{
	int date;
	struct node *left,*right;
}Lnode,*Btree;
int i=1;
Btree insert_Btree(int item,Btree root){
	if(root==NULL){
		root=(Btree)malloc(sizeof(Lnode));
		root->date=item;
		root->left=NULL;
		root->right=NULL;
	}
	else{
		if(item >= root->date){
			root->right=insert_Btree(item,root->right);
		}
		if(item < root->date){
			root->left=insert_Btree(item,root->left);
		}
	}
	return root;
}
void printf_Btree(Btree root){
	if(root==NULL){
		return;
	}
	else{
		if(root->left==NULL&&root->right==NULL){
			printf("%d %d\n",root->date,i);
		}
		i++;
		printf_Btree(root->left);
		printf_Btree(root->right);
		i--;
	}
}
int main()
{
	int j=1;
	Btree root=NULL;
	int n,item;
	scanf("%d",&n);
	for(j=0;j<n;j++){
		scanf("%d",&item);
		root=insert_Btree(item,root);
	}
	printf_Btree(root);
	return 0;
}



