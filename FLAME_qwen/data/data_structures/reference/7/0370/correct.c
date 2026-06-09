#include<stdio.h>
#include<stdlib.h>
struct node{
	int num;
	int h;
	struct node *left;
	struct node *right;
}*root=NULL;
int cnt;
struct node* insert(struct node*p, int n){
	if(p==NULL){
		cnt++;
		p=(struct node*)malloc(sizeof(struct node));
		p->num=n;
		p->h=cnt;
		p->left=p->right=NULL;
	}
	else if(n<p->num){
		cnt++;
		p->left=insert(p->left,n);
	}
	else if(n>=p->num){
		cnt++;
		p->right=insert(p->right,n);
	}
	return p;
}

void print(struct node *p){
	if(p!=NULL){
		print(p->left);
	if(p->left==NULL&&p->right==NULL){
		printf("%d %d\n",p->num,p->h);
	}
		print(p->right);
	}
	return;
}
int main(){
	int m,i,n;
	scanf("%d",&m);
	for(i=1;i<=m;i++){
		cnt=0;
		scanf("%d",&n);
		root=insert(root,n);
	}
	print(root);
	return 0;
}

