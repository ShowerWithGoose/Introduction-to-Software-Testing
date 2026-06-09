#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
struct tree{
	int data;
	int level;
	struct tree *left,*right;
};
struct tree * insertBst(struct tree *p,int i,int item){
	if(p==NULL){
		p=(struct tree *)malloc(sizeof(struct tree));
		p->data=item;
		p->level=i;
		p->left=NULL,p->right=NULL;
	}
	else{
		if(item<p->data){
			p->left=insertBst(p->left,i+1,item);
		}
		else{
			p->right=insertBst(p->right,i+1,item);
		}
	}
	return p;
};
void postorder(struct tree *t){
	if(t!=NULL){
		postorder(t->left);
		postorder(t->right);
		if(t->left==NULL&&t->right==NULL){
			printf("%d %d\n",t->data,t->level);
		}
	}
}
int main(){
	int n,i,num;
	scanf("%d",&n);
	struct tree *root=NULL;
	for(i=0;i<n;i++){
		scanf("%d",&num);
		root=insertBst(root,1,num);
	}
	if(root==NULL){
		printf("ERROR");
	}
	postorder(root);
	return 0;
} 

