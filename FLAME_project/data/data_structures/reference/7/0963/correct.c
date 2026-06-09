#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	int date;
	int depth;
	struct node *left,*right;
}tree;
//int a[1000];
tree* create(tree *root,int buf,int d){
	if(root==NULL){
		root=(tree*)malloc(sizeof(tree));
		root->date=buf;
		root->depth=d;
		root->left=root->right=NULL;
		return root;
	}
	else{
		if(buf>=root->date){
			root->right=create(root->right,buf,d+1);
		}
		else if(buf<root->date){
			root->left=create(root->left,buf,d+1);
		}
	}
	return root;
}
void myprint(tree* t){
//	t->right->date
	if(t!=NULL){
		if(t->left==NULL&t->right==NULL)
			printf("%d %d\n",t->date,t->depth);
		myprint(t->left);
		myprint(t->right);
	}
}
int main(){
	int n,i,buf;
	tree *root;
	root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&buf);
		root=create(root,buf,1);
	}
	myprint(root);
	return 0;
}


