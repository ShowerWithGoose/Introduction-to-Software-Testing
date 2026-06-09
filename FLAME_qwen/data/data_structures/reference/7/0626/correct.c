#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int num;
	int cen;
	struct node *lchild,*rchild;
}tree,*TREE;
TREE sort(int k[],int);
TREE insert(TREE,int);
void read(TREE);

int main(){
	int a[100],n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	read(sort(a,n));
	return 0;
}

TREE sort(int k[],int n){
	TREE T=NULL;
	int i;
	for(i=0;i<n;i++)
		T=insert(T,k[i]);
	return T;
}

TREE insert(TREE T,int item){
	if(T==NULL){
		T=(TREE)malloc(sizeof(tree));
		T->num=item;
		T->cen=1;
		T->lchild=NULL;
		T->rchild=NULL;
	}
	else{
		if(item<T->num)
			T->lchild=insert(T->lchild,item);
		else
			T->rchild=insert(T->rchild,item);
	}
	return T;
}

void read(TREE T){
	if(T!=NULL){
		if(T->lchild!=NULL)
			T->lchild->cen += T->cen;
		if(T->rchild!=NULL)
			T->rchild->cen += T->cen;
		if(T->lchild==NULL&&T->rchild==NULL)
			printf("%d %d\n",T->num,T->cen);
	
		read(T->lchild);
		read(T->rchild);
	}
}

