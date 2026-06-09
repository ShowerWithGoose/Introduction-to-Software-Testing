#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int h;
struct node{
	int data;
	int h;
	struct node *lchild,*rchild;
};
typedef struct node BTnode,*BTnodeptr;
BTnodeptr root=NULL;
BTnodeptr Insert(int,BTnodeptr,int);
void Print(BTnodeptr);
int main()
{
	int n,i,item;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&item);
		h=1;
		root=Insert(item,root,h);
	}
	Print(root);
	return 0;
}
BTnodeptr Insert(int item,BTnodeptr p,int h)
{
	if(p==NULL){
		p=(BTnodeptr)malloc(sizeof(BTnode));
    	p->data=item;
	    p->lchild=NULL;
	    p->rchild=NULL;
	    p->h=h;
	}  
	else if(item<p->data){
		h++;
		p->lchild=Insert(item,p->lchild,h);
	}	
	else{
		h++;
		p->rchild=Insert(item,p->rchild,h);
	}
	return p;
}
void Print(BTnodeptr root)
{
	if(root){
		if(root->lchild==NULL&&root->rchild==NULL)
		    printf("%d %d\n",root->data,root->h);
    	Print(root->lchild);
    	Print(root->rchild);
	}
}

