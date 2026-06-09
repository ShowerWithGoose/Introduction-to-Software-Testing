#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct Tree{
	int num;
	struct Tree *llink;
	struct Tree *rlink;
};

void output(struct Tree *root,int deepth){
	if(root!=NULL){
		deepth++;
        if ((root->llink==NULL)&&(root->rlink==NULL)){
        	
            printf("%d %d\n",root->num,deepth);
        }
        output(root->llink,deepth);
        output(root->rlink,deepth);		
	}
}

struct Tree *update(struct Tree *root,int m){
	if(root==NULL){
		root=(struct Tree*)malloc(sizeof(struct Tree));
		root->num=m;
		root->llink=NULL;
		root->rlink=NULL;
	}
	else if(m<root->num){
		root->llink=update(root->llink,m);
	}
	else if(m>=root->num){
		root->rlink=update(root->rlink,m);
	}
	return root;
}

int main(){
	struct Tree *root=NULL;
	int n,k[123],i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&k[i]);
	}
	for(i=0;i<n;i++){
		root=update(root,k[i]);
	}
	int deepth=0;
	output(root,deepth);
	return 0;
}

