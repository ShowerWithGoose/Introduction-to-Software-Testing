#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	int hight;
	struct node *left,*right;
};
struct node* insertBst(struct node*p,int item);
void backBst(struct node* p);
int i,j=1,k;
int main(){
	int n;
	scanf("%d",&n);
	struct node* root=NULL,*prior;
	prior=root;
	int input;
	for(i=0;i<n;i++){
		scanf("%d",&input);
		root=insertBst(root,input);
	}
	backBst(root);
}
struct node* insertBst(struct node*p,int item){
	if(p==NULL){
		p=(struct node*)malloc(sizeof(struct node));
		p->data=item ;
		p->hight=1;
		p->left=p->right=NULL;
	}else if(item<p->data){
		p->left=insertBst(p->left,item);
		p->left->hight+=p->hight;
	}else if(item>=p->data){
		p->right=insertBst(p->right,item);
		p->right->hight+=p->hight;
	}
	return p;
}
void backBst(struct node* p){
	if(p==NULL){
		
	}else{
		if(p->left==NULL&&p->right==NULL){
			printf("%d %d\n",p->data,j);
		}
		j++;
		backBst(p->left);
		backBst(p->right);
		j--;
	}
}

