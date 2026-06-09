#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct tree{
	int num;
	struct tree *left,*right;
	int order;
	int trans;
};
void putTree(struct tree* root){
	if(root==NULL) return;
	if(root->left==NULL&&root->right==NULL){
		printf("%d %d\n",root->num,root->order);
		return ;
	}
	putTree(root->left);
	putTree(root->right);
}

int main (){
	int n,i,a,j;
	scanf("%d",&n);
	struct tree *root,*ptr;
	root=(struct tree*)malloc(sizeof(struct tree));
	ptr=root;
	root->left=NULL;
	root->right=NULL;
	root->num=0;
	root->trans=0;
	int ob;
	for(i=0;i<n;i++){
		scanf("%d",&a);
		ob=1;
		j=1;
		while(ob&&ptr->trans!=0){
			j++;
			if(a<ptr->num){
				if(ptr->left==NULL){
					ptr->left=(struct tree*)malloc(sizeof(struct tree));
					ptr->left->left=NULL;
					ptr->left->right=NULL;
					ob=0;
				
				}
				ptr=ptr->left;
			}
			else {
				if(ptr->right==NULL){
					ptr->right=(struct tree*)malloc(sizeof(struct tree));
					ptr->right->left=NULL;
					ptr->right->right=NULL;
					ob=0;
					
				}
				ptr=ptr->right; 
			}
		}
		ptr->num=a;
		ptr->order=j;
		ptr->trans=1;
		ptr=root;
	}
	putTree(root);
	
	return 0;
}

