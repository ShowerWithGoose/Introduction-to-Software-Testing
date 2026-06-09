#include <stdio.h>
#include <stdlib.h>
struct node{
	int key;
	int num;
	struct node* lchild;
	struct node* rchild;
};
struct node* root;

struct node* createnode(int n,int num){
	struct node* p;
	p=(struct node*)malloc(sizeof(struct node));
	p->lchild=NULL;
	p->key=n;p->num=num;
	p->rchild=NULL;
	return p;
}

void bianli(struct node* root){

	if(root->lchild==NULL&&root->rchild==NULL){
		printf("%d %d\n",root->key,root->num);

	}
	
	if(root->lchild!=NULL) bianli(root->lchild);
	if(root->rchild!=NULL) bianli(root->rchild);
}

void insert(int key){
	if(root==NULL){
		root=createnode(key,1);
	}else{
		int cnt=1;
		struct node *cur;
		struct node *houcur;
		cur=root;
		int flag;
		while(cur!=NULL){
			if(key<cur->key){
				houcur=cur;
				cur=cur->lchild;flag=1;cnt++;
			}else{
				houcur=cur;
				cur=cur->rchild;flag=2;cnt++;
			}
		}
		cur=createnode(key,cnt);
		if(flag==1){
			houcur->lchild=cur;
		
		}else if(flag==2){
			houcur->rchild=cur;
		
		}
	}
}


int main(){
	int n,i;
	int keynum;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&keynum);
		insert(keynum);	
	}

	bianli(root);

	return 0;
}



