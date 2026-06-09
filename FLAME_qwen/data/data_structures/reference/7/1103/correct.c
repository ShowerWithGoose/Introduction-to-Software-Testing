#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
struct tree{
	int num,depth;
	struct tree *left,*right;
}*tp=NULL,*root;
int depth=1,i,n;
struct tree*creat(){
	struct tree*root=(struct tree*)malloc(sizeof(struct tree));
	root->left=NULL;
	root->right=NULL;
	root->depth=1;
	root->num=0;
	return root;
}

void insert(int a){
	if(tp==NULL){
		tp=root;
		tp->num=a;
	}
	else{
		if(tp->num>a){
			if(tp->left==NULL){
				tp->left=(struct tree*)malloc(sizeof(struct tree));
				tp=tp->left;
				depth++; 
				tp->num=a;
				tp->depth=depth;
				tp->left=NULL;
				tp->right=NULL;	
			}
			else {
				depth++;
				tp=tp->left;
				insert(a);
			}
		}
		else{
			if(tp->right==NULL){
				tp->right=(struct tree*)malloc(sizeof(struct tree));
				depth++;
				tp=tp->right;
				tp->num=a;
				tp->depth=depth;
				tp->left=NULL;
				tp->right=NULL;
			}
			else {
				depth++;
				tp=tp->right;
				insert(a);
			}
		}
	}
}

void search(struct tree *a){
	if(a!=NULL){
		if(a->left==NULL&&a->right==NULL) printf("%d %d\n",a->num,a->depth);;
		search(a->left);
		search(a->right);
	}
	
}

int main(){
	int a;
	scanf("%d",&n);
	root=creat();
	
	for(i=0;i<n;i++){
		scanf("%d",&a);
		
		insert(a);
		tp=root;
		depth=1;
	}
	search(root);
	return 0;
} 



