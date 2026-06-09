//
//  main.c
//  树叶节点遍历
//
//  Created by  on 2022/5/7.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
struct node{
    int num;
    struct node *lchild;
    struct node *rchild;
}*root;

void createTree(int newnum,struct node **begin){
    if(*begin==NULL){
        *begin=(struct node*)malloc(sizeof(struct node));
        (*begin)->num=newnum;
        (*begin)->lchild=NULL;
        (*begin)->rchild=NULL;
        return;
    }
    if(newnum<((*begin)->num))
        return createTree(newnum,&((*begin)->lchild));
    if(newnum>=((*begin)->num))
        return createTree(newnum,&((*begin)->rchild));
    if(newnum<((*begin)->num))
        return;
}

int depth=0;
void checkleaf(struct node *begin){
    depth++;
    if((begin->lchild)==NULL &&(begin->rchild)==NULL){
        printf("%d %d\n",begin->num,depth);
        depth--;
        return;
    }
    if((begin->lchild)!=NULL)
        checkleaf(begin->lchild);
    if((begin->rchild)!=NULL)
        checkleaf(begin->rchild);
    depth--;
    return;
}

int main(int argc, const char * argv[]) {
    int num=0;
    int all=0;
    root=(struct node*)malloc(sizeof(struct node));
    root->lchild=NULL;
    root->rchild=NULL;
    scanf("%d",&all);
    scanf("%d",&num);
    root->num=num;
    for(int i=0;i<all-1;i++){
        scanf("%d",&num);
        createTree(num, &root);
    }
    checkleaf(root);
    return 0;
}

