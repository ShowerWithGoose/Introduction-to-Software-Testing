#include <stdio.h>
#include <stdlib.h>
#define Datatype int

typedef struct node{
    Datatype data;
    struct node *lchild, *rchild;
    int depth;
}BTNode,*BTREE;

BTREE SORTTREE(Datatype K[],int n);
void INSERTBST(BTREE *T,Datatype item,int depth);
void Leaves(BTREE T);

int main()
{
    int total=0;
    scanf("%d",&total);

    int num[100]={};
    int i=0;
    for(i=0;i<total;i++){
        scanf("%d",&num[i]);
    }

    BTREE T=SORTTREE(num,total);

    Leaves(T);

    return 0;
}

BTREE SORTTREE(Datatype K[],int n)
{
    BTREE T=NULL;
    int i;
    if(n>0)
    for(i=0;i<n;i++)
        INSERTBST(&T,K[i],1);
    return T;
}

void INSERTBST(BTREE *T,Datatype item,int depth)
{
    if((*T)==NULL)
    {
        (*T)=(BTREE)malloc(sizeof(BTNode));
        (*T)->data=item;
        (*T)->depth=depth;
        (*T)->lchild=NULL;
        (*T)->rchild=NULL;
    }
    else if(item<((*T)->data))
        INSERTBST(&((*T)->lchild),item,depth+1);
    else
        INSERTBST(&((*T)->rchild),item,depth+1);
}

void Leaves(BTREE T)
{
	if(T!=NULL){
		if(T->lchild==NULL && T->rchild==NULL)
			printf("%d %d\n",T->data,T->depth);
		Leaves(T->lchild);
		Leaves(T->rchild);
	}
}







