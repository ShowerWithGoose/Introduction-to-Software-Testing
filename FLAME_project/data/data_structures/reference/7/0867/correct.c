//
// Created by  on 2022-04-14.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int DTYPE;

typedef struct BSTNode{
    struct BSTNode *lChild,*rChild;
    DTYPE value;
}bnode,*ptrnode;

ptrnode addNode(ptrnode t,DTYPE val){
    if(t==NULL){
        t = malloc(sizeof(bnode));
        t->lChild = t->rChild = NULL;
        t->value = val;
    }else{
        if(val>=t->value){
            t->rChild = addNode(t->rChild,val);
        }else{
            t->lChild = addNode(t->lChild,val);
        }
    }
    return t;
}

void visit(ptrnode t,int layer){
    if(t==NULL){
        return;
    }
    if(t->lChild==NULL&&t->rChild==NULL){
        printf("%d %d\n",t->value,layer);
    }else{
        visit(t->lChild,layer+1);
        visit(t->rChild,layer+1);
    }
}

int main(){
    int N;
    scanf("%d",&N);
    ptrnode root = NULL;
    while(N--){
        DTYPE nVal;
        scanf("%d",&nVal);
        if(!root){
            root = addNode(root,nVal);
        }else{
            addNode(root,nVal);
        }
    }
    visit(root,1);
}


