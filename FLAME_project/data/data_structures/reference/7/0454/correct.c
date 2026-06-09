#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct treeNode{
    int val;
    struct treeNode* right;
    struct treeNode*  left;
};
struct treeNode *  treeInsert(struct treeNode*T,int val){
    if(T == NULL){
        T = malloc(sizeof(struct treeNode));
        T->left = T->right =NULL;T->val = val;
    }
    else if(val < T->val)
        T->left = treeInsert(T->left,val);
    else if(val >= T->val)
        T->right = treeInsert(T->right,val);
    return T;
}

void preOrder(struct treeNode*T,int depth){
    if(T == NULL)
    return;

    if(T->left == NULL && T->right == NULL)
    printf("%d %d\n",T->val,depth);

    if(T->left != NULL) preOrder(T->left,depth+1);
    if(T->right!= NULL) preOrder(T->right,depth+1);
}



int main(){
    int n;
    scanf("%d",&n);
    int ival;
    struct treeNode * T = NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&ival);
        T = treeInsert(T,ival);
    }
    
    preOrder(T,1);
    
    return 0;
}
