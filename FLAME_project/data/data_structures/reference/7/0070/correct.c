#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
typedef struct  node {
    int   data;
    int  high;
    struct  node   *left,  *right;
}ec;
ec *root;
ec *bt(ec *root,int a,int len );
void yezi(ec *root);

int main(){
    int n,i,a;
    scanf("%d",&n);
    ec *root=NULL;
    for(i=0;i<n;i++){
    	scanf("%d",&a);
    	int h=0;
    	root=bt(root,a,h);
	}
	yezi(root);
	return 0;
}

ec *bt(ec *root,int a,int len )
{
	len++;
	if(root==NULL){
		root=(ec*)malloc(sizeof(ec));
		root->data=a;
		root->left=NULL;
		root->right=NULL;
		root->high=len;
		
	}else if(root->data>a){
		root->left=bt(root->left,a,len);
		
	}else if(root->data<=a){
		root->right=bt(root->right,a,len);
	}
	return root;
}
void yezi(ec *root){
	if(root==NULL){
		return;
	}
	if(root!=NULL){
		if(root->left==NULL&&root->right==NULL){
			printf("%d %d\n",root->data,root->high);
			
		}
	
	}
		yezi(root->left);
	yezi(root->right);
}

