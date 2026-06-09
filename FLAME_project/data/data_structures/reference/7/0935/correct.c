#include <stdio.h>
#include <string.h>
#include <math.h>
#include<stdlib.h>

typedef struct tree{
	int a;
	struct tree *left;
	struct tree *right;
	int b;
}*tree2;
tree2 root=NULL;
void ji(tree2 *t,int m,int n);
void order(tree2 t){
	if(t!=NULL){
		order(t->left);
		if(t->left==NULL&&t->right==NULL)
		printf("%d %d\n",t->a,t->b);	
		order(t->right);
	}	
}
int main(){
	int n,i,m;
	scanf("%d",&n);
	
	for(i=0;i<n;i++){
		scanf("%d",&m);
		ji(&root,m,1);
	}
	order(root);
	return 0;
}
void ji(tree2 *t,int m,int n){
	if(*t==NULL){
		*t=malloc(sizeof(tree2));
		(*t)->left=(*t)->right=NULL;
		(*t)->a=m;
		(*t)->b=n;
	}
else if(m>=(*t)->a)
	{
		ji(&((*t)->right),m,n+1);
	} 
	else
	{
		ji(&((*t)->left),m,n+1);
	} 
}




