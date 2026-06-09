#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
#include<math.h>
struct node{
	int data;
	int h;
	struct node *left,*right,*parent;
};
typedef struct node btnode;
typedef struct node *btnodeptr;
btnodeptr q;
int flag=0;
btnodeptr insert(btnodeptr p,int a){
	if(p==NULL){
		flag++;
		p=(btnodeptr)malloc(sizeof(btnode));
		p->data=a;
		if(flag==1) p->h=1;
		p->left=p->right=p->parent=NULL;
	} 
	else if(a<p->data){
		q=insert(p->left,a);
	    p->left=q;
	    q->parent=p;
	    q->h=p->h+1;
}
	else if(a>=p->data){
		q=insert(p->right,a);
	    p->right=q;
	    q->parent=p;
	    q->h=p->h+1;
}
	return p;
}
void bianli(btnodeptr t){
	if(t!=NULL){
		if(t->left==NULL&&t->right==NULL) printf("%d %d\n",t->data,t->h);
		bianli(t->left);
		bianli(t->right);
	}
}
int main(){
	int i,N,a;
	scanf("%d",&N);
	btnodeptr root=NULL;
	for(i=0;i<N;i++){
		scanf("%d",&a);
		root=insert(root,a);
	}
	bianli(root);
	return 0;
} 



