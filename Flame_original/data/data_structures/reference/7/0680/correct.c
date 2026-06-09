#include<stdio.h>
#include<string.h>
struct node{
	int data;
	struct node*lchild;
	struct node*rchild;
};
struct node *ins(struct node*root,int data){
	struct node*p;
	if(root==NULL){
		p=(struct node*)malloc(sizeof(struct node));
		p->data=data;
		p->lchild=p->rchild=NULL;
		return p;
	}
	else{
		if(root->data>data){
			root->lchild=ins(root->lchild,data);
		}
		else{
			root->rchild=ins(root->rchild,data);
		}
		return root;
	}
}
void print(struct node*root,int hight){
	if(root->lchild!=NULL){
		print(root->lchild,hight+1);
	}
	if(root->rchild!=NULL){
		print(root->rchild,hight+1);
	}
	if(root->lchild==NULL&&root->rchild==NULL){
		printf("%d %d\n",root->data,hight);
	}
}
int main()
{
	struct node*root=NULL;
	int n,data,i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&data);
		root=ins(root,data);
	}
	print(root,1);
	return 0;
}

