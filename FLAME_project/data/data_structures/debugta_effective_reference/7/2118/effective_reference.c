#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define ArrayNum(x) (sizeof(x)/sizeof(x[0]))
struct node{
	struct node *l,*r;
	int num;
};
typedef struct node tree;
typedef struct node *treeptr;
treeptr root=NULL,p=NULL;
int tmp;
void insert(treeptr root){
	if(tmp<root->num){
		if(root->l==NULL){
			p=(treeptr)malloc(sizeof(tree));
			p->l=NULL;
			p->r=NULL;
			p->num=tmp;
			root->l=p;
		}else{
			insert(root->l);
		}
	}else{
		if(root->r==NULL){
			p=(treeptr)malloc(sizeof(tree));
			p->l=NULL;
			p->r=NULL;
			p->num=tmp;
			root->r=p;
		}else{
			insert(root->r);
		}
	}
}
void search(treeptr root,int h){
	if(root!=NULL){
		search(root->l,h+1);
		search(root->r,h+1);
		if(root->l==NULL&&root->r==NULL)
			printf("%d %d\n",root->num,h);
	}
}
int main(){
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		if(root==NULL){
			root=(treeptr)malloc(sizeof(tree));
			root->l=NULL;
			root->r=NULL;
			scanf("%d",&tmp);
			root->num=tmp;
		}else{
			scanf("%d",&tmp);
			insert(root);
		}
	}
	search(root,1);
	return 0;
}


