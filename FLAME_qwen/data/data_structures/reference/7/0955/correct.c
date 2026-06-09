#include<stdio.h> 
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
		int x;
		int h;
		struct trees *left,*right;
	}T;
	typedef struct node btn;
	typedef struct node *btnr;
	btnr tree(btnr root,int temp,int len);
void f(btnr root);
int main(){
	int n;
	int item;
	btnr root=NULL;
	btnr p;
	scanf("%d",&n);
	p=root;
	for(int i=0;i<n;i++){
		scanf("%d",&item);
		int l=0;
		root=tree(root,item,l);
		
	}
	f(root);
	return 0;
	} 
btnr tree(btnr root,int temp,int len){
	len++;
	if(root==NULL){
		root=(btnr)malloc(sizeof(btn));
		root->right=NULL;
		root->left=NULL;
		root->x=temp;
		root->h=len;
	}
	else if(temp<root->x)
	root->left =tree(root->left,temp,len);
	else if(temp>=root->x)
	root->right =tree(root->right,temp,len);
	return root;
}
void f(btnr q){
	if(q!=NULL){
		if(q->left==NULL&&q->right==NULL)
		{printf("%d %d\n",q->x,q->h);
		}
		f(q->left);
		f(q->right);
	}
}


