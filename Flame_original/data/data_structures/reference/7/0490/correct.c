#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	int data;
	int sec;
	struct node *lchild,*rchild;
}Tree;
Tree *one;
Tree *insertBST(Tree *p,int a,int s);
void print(Tree *p);
int main(){
	int n;
	scanf("%d",&n);
	int i,a;
	Tree *p=NULL;
	for(i=0;i<n;i++){
		scanf("%d",&a);
		int s=0;
		p=insertBST(p,a,s);
	}
	print(p);
	return 0;
} 
Tree *insertBST(Tree *p,int a,int s){
	s++;
	if(p==NULL){
		p=(Tree *)malloc(sizeof(Tree));
		p->data =a;
		p->lchild =p->rchild =NULL;
		one=p;
		p->sec =s;
	}
	else if(a<p->data ){
		p->lchild =insertBST(p->lchild ,a,s);
	}
	else if(a>=p->data ){
		p->rchild =insertBST(p->rchild ,a,s);
	}
	return p;
}
void print(Tree *p){
	if(p){
		if(!(p->lchild )&&!(p->rchild )){
			printf("%d %d\n",p->data ,p->sec );
		}
		print(p->lchild );
		print(p->rchild );
	}
}

