#include <stdlib.h>
#include <stdio.h>


typedef struct node{
    int data;
    struct node *lchild, *rchild;
}BTNode;

BTNode* insertBST(BTNode* T, int item);
void preBitree(BTNode* T);

int deep=1;

int main(){
    int n, item;
    int i;
    BTNode* root=NULL;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d", &item);
        root = insertBST(root, item);
    }
    //printf("%d %d\n", root->data, deep);
    preBitree(root);
    return 0;
}

BTNode* insertBST(BTNode* T, int item){
    if(T == NULL){
        T = (BTNode *)malloc(sizeof(BTNode));
        T->data = item;
        T->lchild = T->rchild = NULL;
    }
    else if(item < T->data){
        T->lchild = insertBST(T->lchild, item);
    }
    else if(item >= T->data){
       T->rchild = insertBST(T->rchild,item);	
	}
    return T;
}

void preBitree(BTNode* T){
    if(T==NULL){
        return;
    }
    else{
        if(T->lchild == NULL&&T->rchild == NULL){
        	printf("%d %d\n", T->data, deep);
        	return;
		}
		else{
			deep++;
	        preBitree(T->lchild);
	        preBitree(T->rchild);
	        deep--;
		}
    }
}





