/*
 * @Author:
 * @Date: 2022-04-28 19:40:16
 * 
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

#define BSTNodeValType int

typedef struct BSTNode{
    BSTNodeValType val;
    struct BSTNode *lc,*rc;
}BSTNode;

void insertBST(BSTNode **no,BSTNodeValType aVal){
    if(*no==NULL){
        *no=(BSTNode *)malloc(sizeof(BSTNode));
        (*no)->val=aVal;
        (*no)->lc=(*no)->rc=NULL;
        return;
    }
    if(aVal<(*no)->val) insertBST(&((*no)->lc),aVal);
    else insertBST(&((*no)->rc),aVal);
}


void dfsBST(BSTNode *no,int depth){
    if(no->lc==NULL&&no->lc==no->rc){
        printf("%d %d\n",no->val,depth);
        return;
    }
    if(no->lc) dfsBST(no->lc,depth+1);
    if(no->rc) dfsBST(no->rc,depth+1);
}

BSTNode *root=NULL;

int main(int argc, char const *argv[]){
    int n;
    scanf("%d",&n);
    for(int i=1,tmp;i<=n;i++){
        scanf("%d",&tmp);
        insertBST(&root,tmp);
    }
    dfsBST(root,1);
    return 0;
}
