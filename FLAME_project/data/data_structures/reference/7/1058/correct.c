#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define e 2.718281
#define pi 3.14159265

struct shu{
	int data,h,k;
	struct shu *left,*parent,*right;
}; 
typedef struct shu BTshu;
typedef struct shu* BTshuptr;
BTshuptr p;
void insort(BTshuptr t,int s){
	if(s<t->data){
		if(t->left==NULL){
			p=(BTshuptr)malloc(sizeof(BTshu));
			t->left=p;
			p->data=s;
			p->h=t->h+1;
			p->left=NULL;
			p->parent=t;
			p->right=NULL;
		}else{
			insort(t->left,s);
		}
	}else{
		if(t->right==NULL){
			p=(BTshuptr)malloc(sizeof(BTshu));
			t->right=p;
			p->data=s;
			p->h=t->h+1;
			p->left=NULL;
			p->parent=t;
			p->right=NULL;
		}else{
			insort(t->right,s);
		}
	}
}
void inorder(BTshuptr t)
{
	if(t!=NULL){
		inorder(t->left);
		if(t->left==NULL&&t->right==NULL){
			printf("%d %d\n",t->data,t->h);
		}
		inorder(t->right);
	}
 }
int main()
{
	
	int n,i,j,du;
	scanf("%d",&n);
	BTshuptr first=(BTshuptr)malloc(sizeof(BTshu));
	first->h=1;first->right=NULL;first->left=NULL;first->parent=NULL;first->k=0;
	for(i=0;i<n;i++)
	{
		scanf("%d",&du);
		if(first->k==0){
			first->data=du;
			first->k=1;
			continue;
		}else{
			insort(first,du);
		}
	}
	inorder(first);
	return 0;
}



