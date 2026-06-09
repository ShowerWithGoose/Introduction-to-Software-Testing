#include<stdio.h>
#include<stdlib.h>
struct node{
	int id;
	struct node *left,*right;
};
struct node *root=NULL,*p;
struct node *insert(struct node *t,int x);
void bianli(struct node *t,int x);
int main(){
	struct node *root=NULL;
	int n,i;
	scanf("%d",&n);
	int x;
	for(i=0;i<n;i++){
		scanf("%d",&x);
		root=insert(root,x);
	}
	bianli(root,1);
	return 0;
}
struct node *insert(struct node *t,int x){
	
	if(t==NULL){
		//struct node *p;
		t=(struct node *)malloc(sizeof(struct node));
		t->id=x;
		t->left=t->right=NULL;
	}else{
		if(x>=t->id){
			t->right=insert(t->right,x);
		}else{
			t->left=insert(t->left,x);
		}
	}
	return t;
}
/*struct node *insert(struct node *p,int item){
	if(p==NULL){
		p=(struct node *)malloc(sizeof(struct node));
		p->id=item;
		p->left=p->right=NULL;
	}
	else if(item<p->id){
		p->left=insert(p->left,item);
	}
	else if(item>=p->id){
		p->right=insert(p->right,item);
	}
	return p;
}*/
void bianli(struct node *t,int x){
	if(t->left==NULL&&t->right==NULL){
		printf("%d %d\n",t->id,x);
	}else{
		if(t->left!=NULL){
			bianli(t->left,x+1);
		}
		if(t->right!=NULL){
			bianli(t->right,x+1);
		}
	}
}

