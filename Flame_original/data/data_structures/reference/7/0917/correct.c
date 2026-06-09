#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
	int deep;
};
void search(struct node *t){
	if(t!=NULL){
		search(t->left);
		if(t->left==NULL&&t->right==NULL)
			printf("%d %d\n",t->data,t->deep);
	search(t->right);
	}
}
int main(){
	int i,n,a;
	struct node tree;
	struct node *p,*top,*find,*tmp;
	scanf("%d",&n);
	scanf("%d",&a);
	p=(struct node *)malloc(sizeof(struct node));
	top=p;
	p->data=a;
	p->left=NULL;
	p->right=NULL;
	p->deep=1;
	for(i=1;i<n;i++){
		scanf("%d",&a);
		find=top;
		while(1){
			if(a<find->data&&find->left!=NULL){
				find=find->left;
			}//◊Û≤‡’“
			else if(a>=find->data&&find->right!=NULL){
				find=find->right;
			}//”“≤‡’“
			else if(a<find->data&&find->left==NULL){
				tmp=(struct node *)malloc(sizeof(struct node));
				tmp->data=a;
				tmp->left=NULL;
				tmp->right=NULL;
				tmp->deep=find->deep+1;
				find->left=tmp;
				break;
			} //≤Â»Î◊Û≤‡
			else if(a>=find->data&&find->right==NULL){
				tmp=(struct node *)malloc(sizeof(struct node));
				tmp->data=a;
				tmp->left=NULL;
				tmp->right=NULL;
				tmp->deep=find->deep+1;
				find->right=tmp;
				break;
			} //≤Â»Î”“≤‡ 
		}
	}
	search(top);
	return 0;
}



