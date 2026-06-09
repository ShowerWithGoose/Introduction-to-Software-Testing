#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node{
	int data;
	struct node *lchild,*rchild;
}BTNode,*BTREE;
BTREE T=NULL;
int n;
int k;
int ans=1;
void insert(BTREE *T,int k){
	if((*T)==NULL){
	(*T)=(BTREE)malloc(sizeof(BTNode));
	(*T)->data=k;
	(*T)->lchild=NULL;
	(*T)->rchild=NULL;
    }
    else if(k<(*T)->data)
    	insert(&(*T)->lchild,k);
    else insert(&(*T)->rchild,k);
    
    
}
void print(BTREE T)
{
    if (T!=NULL)
    {
        if (T->lchild==NULL && T->rchild==NULL)
        {
            printf("%d %d\n", T->data, ans);
        }
        ans++;
        print(T->lchild);
        print(T->rchild);
        ans--;
    }
    else return;
}

int main(){
	
	scanf("%d",&n);

	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		insert(&T,k);
	}
  
	print(T);
	return 0;
}
