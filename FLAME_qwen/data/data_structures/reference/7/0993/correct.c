#include<stdio.h>           
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
struct node{
	struct node* left;
	struct node* right;
	int h;
	int key;
};
int max(int a,int b)
{
	return a > b? a:b;
}
struct node* creattree(struct node* root,int num)
{
	struct node* t;
	if(root==NULL){
		t = (struct node*)malloc(sizeof(struct node));
		t->left = NULL;
		t->right = NULL;
		t->key = num;
		root = t;
	}
	else if(root!=NULL){
		if(num < root->key){
			root->left = creattree(root->left,num);
		} 
		if(num >= root->key){
			root->right = creattree(root->right,num);
		}
	}
	
	return root;
}
void medsearch(struct node* root,int height){
	if(root->left!=NULL) medsearch(root->left,height+1);
	if(root->right==NULL&&root->left==NULL){
		printf("%d %d\n",root->key,height);
	}
	if(root->right!=NULL) medsearch(root->right,height+1);
}
int main()
{
	int num,n,i;
	struct node* root = NULL;
	scanf("%d",&n);
	for(i = 1;i <= n;i ++){
		scanf("%d",&num);
		root = creattree(root,num);
	}
	root->h = 1;
	medsearch(root,1);
	return 0;
}






