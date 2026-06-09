#include <stdio.h>
#include <stdlib.h>
typedef struct BST
{
    int data;
    struct BST *left,*right;
}BST;
void BSTinsert(BST **,int);
void deleteBST(BST **);
void visitLeaves(BST **);
int main()
{
    BST *root=NULL;
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int curData;
        scanf("%d",&curData);
        BSTinsert(&root,curData);
    }
    visitLeaves(&root);
    deleteBST(&root);
    return 0;
}
void BSTinsert(BST **root,int data)
{
    if((*root)==NULL){
        BST *p=malloc(sizeof(BST));
        *root=p;
        p->data=data;
        p->left=NULL;
        p->right=NULL;
    }else{
        if((*root)->data>data){
            BSTinsert(&((*root)->left),data);
        }else{
            BSTinsert(&((*root)->right),data);
        }
    }
}
void deleteBST(BST **root)
{
    if((*root)->left==NULL&&(*root)->right==NULL){
        free(*root);
    }else{
        if((*root)->left!=NULL)deleteBST(&((*root)->left));
        if((*root)->right!=NULL)deleteBST(&((*root)->right));
    }
}
int layer=1;
void visitLeaves(BST **root)
{
    if((*root)!=NULL){
        if((*root)->left==NULL&&(*root)->right==NULL){
            printf("%d %d\n",(*root)->data,layer);
        }
        layer++;
        visitLeaves(&((*root)->left));
        layer++;
        visitLeaves(&((*root)->right));
    }
    layer--;
}
