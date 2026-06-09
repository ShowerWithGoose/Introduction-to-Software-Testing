#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	int height;
	struct node *left,*right;
};
int m;
struct node *q;
void preorder(struct node *p){
	if(m<p->data&&p->left!=NULL)preorder(p->left);
	else if(m>=p->data&&p->right!=NULL)preorder(p->right); 
	else if(m<p->data&&p->left==NULL){
		p->left=q;
		q->height=p->height+1;
	}
	else if(m>=p->data&&p->right==NULL){
		p->right=q;
		q->height=p->height+1;
	}
}
void visit(struct node *p){
	if(p->left==NULL&&p->right==NULL)printf("%d %d\n",p->data,p->height);
	if(p->left!=NULL)visit(p->left);
	if(p->right!=NULL)visit(p->right);
}
int main(){
	int n;
	int i;
	struct node *root=NULL,*p;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&m);
		q=(struct node*)malloc(sizeof(struct node));
		q->left=NULL;
		q->right=NULL;
		q->data=m;
		if(root==NULL){
			root=q;
			root->height=1;
		}
		else{
			preorder(root);
		}
	}
	
	visit(root);
	return 0;	
}

