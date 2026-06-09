#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
	int data;
	int high;
	struct node *right,*left;
}; 
struct node *insert(struct node *p,int a,int l){
	l++;
	if(p==NULL){
		p=(struct node *)malloc(sizeof(struct node));
		p->data=a;
		p->high=l;
		p->left=NULL;
		p->right=NULL;
	}else if(a<p->data)
	p->left=insert(p->left,a,l);
	else if(a>=p->data)
	p->right=insert(p->right,a,l);
	return p;
}
void p(struct node *root){
	if(root){
		if(!(root->left)&&!(root->right)){
			printf("%d %d\n",root->data,root->high);
		}
		p(root->left);
		p(root->right);
	}
}
int main()
{
	int n,a,i,l=0;
	struct node *root=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		root=insert(root,a,l);
	}
	p(root);
 	return 0;
}


