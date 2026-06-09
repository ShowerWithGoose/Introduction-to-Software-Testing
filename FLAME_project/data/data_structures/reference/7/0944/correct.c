#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct tree{
	int num;
	int depth;
	struct tree *lchild;
	struct tree *rchild;
}*p,*q,*root=NULL;
typedef struct tree *Tree;
int i,n;
int tmp;
int m=1;
void print(Tree r); 
void create(Tree *p,int x,int depth);

int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&tmp);
		create(&root,tmp,m);
	}
	print(root);
	return 0;
}

void print(Tree r)
{
	if(r!=NULL){
		print(r->lchild);
		if(r->lchild==NULL&&r->rchild==NULL){
			printf("%d %d\n",r->num,r->depth);
		}
		print(r->rchild);
	}
}

void create(Tree *p,int x,int depth)
{
	if(*p==NULL){
		*p=(Tree)malloc(sizeof(struct tree));
		(*p)->lchild=(*p)->rchild=NULL;
		(*p)->num=x;
		(*p)->depth=depth;
	}
	else if(x<(*p)->num) create(&(*p)->lchild,x,depth+1);
	else if(x>=(*p)->num) create(&(*p)->rchild,x,depth+1);
}


