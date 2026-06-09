//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define eps 1e-6
typedef struct node{
	int height,num;
	struct node *left,*right;
}node;

void preorder(node* t){
	if(t!=NULL){
		if(t->left==NULL&&t->right==NULL){
			printf("%d %d\n",t->num,t->height);
			return;
		}
		preorder(t->left);
		preorder(t->right);
	}
}

int main(){
	int n,i,numb;
	scanf("%d",&n);
	node* root=NULL;
	for(i=0;i<n;i++){
		scanf("%d",&numb);
		if(root==NULL){
			root=(node*)malloc(sizeof(node));
			root->height=1; root->num=numb;
			root->left=NULL; root->right=NULL;
		}else{
			
			node* temp=root;
			while(1){
				if(numb<temp->num){
					if(temp->left==NULL){
						node* p=(node*)malloc(sizeof(node));
						p->height=temp->height+1; p->num=numb;
						p->left=NULL; p->right=NULL;
						temp->left=p;
						break;
					}
					temp=temp->left;
				}else{
					if(temp->right==NULL){
						node* p=(node*)malloc(sizeof(node));
						p->height=temp->height+1; p->num=numb;
						p->left=NULL; p->right=NULL;
						temp->right=p;
						break;
					}
					temp=temp->right;
				}
			}
			
		}
		
	}
	preorder(root);
	
	
	return 0;
}



