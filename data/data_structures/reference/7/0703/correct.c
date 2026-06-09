#include<stdio.h>
#include<stdlib.h>
struct tree{
	int val;
	struct tree* left;
	struct tree* right;
};
void pr(struct tree*,int);
int main(){
	struct tree *root=(struct tree*)malloc(sizeof(struct tree)),*p;
	int n,i,num;
	scanf("%d",&n);
	scanf("%d",&(root->val));
	root->left=root->right=NULL;
	for(i=1;i<n;i++){
		scanf("%d",&num);
		p=root;
		while(1){
			if(num>=p->val){
				if(p->right==NULL){
					p->right=(struct tree*)malloc(sizeof(struct tree));
					p=p->right;
					p->val=num;
					p->left=p->right=NULL;
					break;
				}
				p=p->right;
			}
			else{
				if(p->left==NULL){
					p->left=(struct tree*)malloc(sizeof(struct tree));
					p=p->left;
					p->val=num;
					p->left=p->right=NULL;
					break;
				}
				p=p->left;
			}
		}
	}
	pr(root,1);
	return 0;
}
void pr(struct tree* root,int deep){
	if(root->left!=NULL){
		pr(root->left,deep+1);
	}
	if(root->right!=NULL){
		pr(root->right,deep+1);
	}
	if(root->left==NULL&&root->right==NULL)printf("%d %d\n",root->val,deep);
	return;
}

