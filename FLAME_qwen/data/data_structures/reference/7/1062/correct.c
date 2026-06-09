#include <ctype.h>
#include <iso646.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1024
struct node_tag{
	int num;
	int height;
	struct node_tag *left;
	struct node_tag *right;
}; 
typedef struct node_tag node;
node *root=NULL;
void  insertBST(int c);
node *inorder(node *t);
int main()
{
	int c,i;
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&c);
		insertBST(c);
	}
	inorder(root);
    return 0;
}
void insertBST(int c){
	node *p;
	node *q;
	p=(node*)malloc(sizeof(node));
	p->num=c;
	p->left=NULL;
	p->right=NULL;
	p->height=1;
	if(root==NULL){
		root=p;
	}
	else{
		q=root;
		while(1){
			if(c<q->num){
				if(q->left==NULL){
					p->height=q->height+1;
					q->left=p;
					break;
				}
				else{
					q=q->left;
				}
			}
			else{
				if(q->right==NULL){
					p->height=q->height+1;
					q->right=p;
					break;	
				}
				else{
					q=q->right;
				}
			}
		}
	}
}
node *inorder(node *t){
	if(t!=NULL){
		inorder(t->left);
		if(t->left==NULL&&t->right==NULL){
			printf("%d %d\n",t->num,t->height);
		}
		inorder(t->right);
	}
}

