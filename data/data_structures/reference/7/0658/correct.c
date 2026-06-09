#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Tree{
	int data;
	struct Tree *rch,*lch;
}BT;
BT *TreeInsert(BT *root,int data){
	BT *p;
	if(root==NULL){
		p=(BT*)malloc(sizeof(BT));
		p->data=data;
		p->lch=p->rch=NULL;
		return p;
	}
	else if(data<root->data) root->lch=TreeInsert(root->lch,data);
	else root->rch=TreeInsert(root->rch,data);
	return root;
}
void TreePostorder(BT *root,int height){
	if(root->lch!=NULL) TreePostorder(root->lch,height+1);
	if(root->rch!=NULL) TreePostorder(root->rch,height+1);
	if(root->lch==NULL&&root->rch==NULL) printf("%d %d\n",root->data,height);
	return;
}
int main(){
	int n;
	scanf("%d",&n);
	BT *root=NULL;
	int d;
	for(int i=1;i<=n;i++){
		scanf("%d",&d);
		root=TreeInsert(root,d);
	}
	TreePostorder(root,1);
	return 0;
}

