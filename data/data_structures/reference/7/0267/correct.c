#include<stdio.h>
#include<stdlib.h>
typedef struct _bst{
	int data;
	int height;
	struct _bst *left,*right;
} BST, *PBST;
int count=1;
PBST insertbt(PBST p,int dat){
	if(p==NULL){
	p=(PBST)malloc(sizeof(BST));	
	p->data=dat;
	p->height=count;
	count=1;
	p->left=p->right=NULL;
	}
	else if(dat<p->data){
		count++;
		p->left=insertbt(p->left,dat);
	}
	else{
		count++;
		p->right=insertbt(p->right,dat);
	}
	return p;
}
void printtree(PBST p){
	if(p!=NULL){
		printtree(p->left);
		if(p->left==NULL&&p->right==NULL)
			printf("%d %d\n",p->data,p->height);
		printtree(p->right);
	}
}
int main()
{
	int n,i,da;
	PBST tr=NULL;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&da);
		tr=insertbt(tr,da);
	}
	printtree(tr);
	return 0;
}

