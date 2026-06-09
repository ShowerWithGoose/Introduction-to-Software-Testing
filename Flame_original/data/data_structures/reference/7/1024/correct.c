#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct shu{
	int data;
	int h;
	struct shu *mu;
	struct shu *left;
	struct shu *right; 
};
void cr(struct shu *d,int a){
	if(a>=d->data&&d->right==NULL){
		struct shu *temp;
		temp=(struct shu*)malloc(sizeof(struct shu));
		temp->mu=d;
		temp->left=NULL;
		temp->right=NULL;
		d->right=temp;
		temp->data=a;
		return ;
	}
	else if(a<d->data&&d->left==NULL){
		struct shu *temp;
		temp=(struct shu*)malloc(sizeof(struct shu));
		temp->mu=d;
		temp->left=NULL;
		temp->right=NULL;
		d->left=temp;
		temp->data=a;		
		return ;
	}
	else if(a<d->data&&d->left!=NULL){
		cr(d->left,a);
	}
	else if(a>=d->data&&d->right!=NULL){
		cr(d->right,a);
	}
}
void bh(struct shu *b,int k){
	if(b!=NULL){
		b->h=k+1;
	}
	if(b->left!=NULL){
		bh(b->left,k+1);
	}
	if(b->right!=NULL){
		bh(b->right,k+1);
	}
	if(b->left==NULL&&b->right==NULL){
		printf("%d %d\n",b->data,b->h);
		return;
	}
}
int main(){
struct shu{
	int data;
	int h;
	struct shu *mu;
	struct shu *left;
	struct shu *right; 
};
struct shu *head,*q,*p;
	int n=0,d=0,i=0;
	scanf("%d",&n);
	head =NULL;
	p=(struct shu*)malloc(sizeof(struct shu));
	p->left=NULL;
	p->right=NULL;
	if(head==NULL){
		head=p;
	}
	scanf("%d",&d);
	head->data=d;
	for(i=0;i<n-1;i++){
		scanf("%d",&d);
		q=head;
		cr(q,d);
	}
	bh(head,0);
}

