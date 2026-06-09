#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>

struct TREE{
	int num;
	int depth;
	struct TREE *left,*right;
};

struct TREE *root=NULL,*tree;

struct TREE* Find(int node){
	struct TREE *find=root;
	while(find->left!=NULL||find->right!=NULL){
		if(node<find->num){
			if(find->left!=NULL){
				find=find->left;
			}
			else{
				break;
			}
		}
		else{
			if(find->right!=NULL){
				find=find->right;
			}
			else{
				break;
			}
		}
	}
	return find;
};

void Preorder(struct TREE *t){
	if(t!=NULL){
		if(t->left==NULL&&t->right==NULL){
			printf("%d %d\n",t->num,t->depth);
		}
		Preorder(t->left);
		Preorder(t->right);
	}	
}

int main()
{
	int n;
	int tem;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&tem);
		tree=(struct TREE*)malloc(sizeof(struct TREE));
		tree->num=tem;
		tree->left=tree->right=NULL;
		if(root==NULL){
			root=tree;
			root->depth=1;
		}
		else{
			struct TREE* parent=Find(tem);
			if(tem<parent->num){
				parent->left=tree;
				tree->depth=parent->depth+1;
			}
			else{
				parent->right=tree;
				tree->depth=parent->depth+1;
			}
		}
	}
	Preorder(root);
	return 0;
}

