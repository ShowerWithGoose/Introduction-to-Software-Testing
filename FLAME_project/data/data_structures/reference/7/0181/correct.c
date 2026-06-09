#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct node{
	int data;
	struct node* lc;
	struct node* rc;
};
int n,i;
int dat;
struct node* insert(struct node* root,int dat){
	if(root==NULL){
		root=(struct node*)malloc(sizeof(struct node));
		root->data=dat;
		root->lc=root->rc=NULL;
	}else{
		if(dat>=root->data)
			root->rc=insert(root->rc,dat);
		else
			root->lc=insert(root->lc,dat);
	}
	
	return root;
}
void printt(struct node* root,int h){
	if(root==NULL)
		return;
	if(root->lc==NULL&&root->rc==NULL){
		printf("%d %d\n",root->data,h);
	}
	printt(root->lc,h+1);
	printt(root->rc,h+1);
}
int main(){
	
	struct node* root=NULL;
	
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&dat);
		root=insert(root,dat);
	}	
	printt(root,1);
	
	return 0;
}



