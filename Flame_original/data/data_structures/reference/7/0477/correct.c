#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct BTREE{
	struct BTREE* left;
	struct BTREE* right;
	int data;
	int height;	
}bt;
typedef bt *pbt;
void insertBt(int a , pbt*p){
	int depth = 1;
	if(*p==NULL){
		*p = (bt*)malloc(sizeof(bt));
		(*p)->data = a;
		(*p)->height = 1;
		(*p)->left = NULL;
		(*p)->right = NULL;
	}
	else{
		pbt temp = *p;
		while(temp!=NULL){
			if(a>=temp->data){
				if(temp->right==NULL){
					depth++;
					temp->right = (bt*)malloc(sizeof(bt));
					temp=temp->right;
					temp->data = a;
					temp->height = depth;
					temp->left = NULL;
					temp->right = NULL;
					break;
				}
				else {
				temp=temp->right;
				depth++;
			}
			}
			else{
				if(temp->left==NULL){
					depth++;
					temp->left = (bt*)malloc(sizeof(bt));
					temp=temp->left;
					temp->data = a;
					temp->height = depth;
					temp->left = NULL;
					temp->right = NULL;
					break;
				}
				else {
				temp=temp->left;
				depth++;
			}
			}
		}

	}
}
void visitBt(bt* p){
	if(p!=NULL){
		visitBt(p->left);
		if(p->left==NULL&&p->right==NULL) printf("%d %d\n",p->data ,p->height);
		visitBt(p->right);	
	}
}
int main(){
	int n;
	bt*p = NULL;
	scanf("%d",&n);
	int temp = 0;
	for(int i =0;i<n;i++){
		scanf("%d",&temp);
		insertBt(temp,&p);
	}
	bt*q = NULL;
	visitBt(p);	
	return 0;
}


