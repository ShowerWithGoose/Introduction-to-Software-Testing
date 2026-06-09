#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

typedef struct TreeNode {

    int val;

    struct TreeNode *left;

    struct TreeNode *right;

    int depth;
}Tree;

Tree *first;

void visit(Tree *t);

void visit(Tree *t){

	printf("%d %d\n",t->val,t->depth);
}

void inorder(Tree *t);

void inorder(Tree *t){

    if(t!=NULL){

        inorder(t->left);

        if(t->left==NULL&&t->right==NULL) visit(t);

        inorder(t->right);
    }
}

Tree *InsertBST(Tree *t,int value,int depth);

Tree *InsertBST(Tree *t,int value,int depth){

	if(t==NULL){

        t=(Tree *)malloc(sizeof(Tree));

        t->left=t->right=NULL;

        t->val=value;

		t->depth=depth;

		first=t;
	}

	else if(value<t->val){

		t->left=InsertBST(t->left,value,depth+1);
	}

	else{

		t->right=InsertBST(t->right,value,depth+1);
	}

	return t;
}

int main(){

    int m,i,n;

    Tree *root=NULL;

	scanf("%d",&n);

	for(i=0;i<n;i++){

		scanf("%d",&m);

		root=InsertBST(root,m,1);
	}

	inorder(root);

	return 0;
}





