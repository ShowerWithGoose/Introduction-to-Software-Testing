#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct bitree{
    int data;
    struct bitree *lchild,*rchild;
    int depth;
}BiTree;
BiTree *root=NULL; /* 根节点 */

BiTree* Insert(int x,BiTree* root,int depth);
void PrintTree(BiTree* root);

int main(){
    int n,x;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        root=Insert(x,root,1);
    }
    PrintTree(root);
    return 0;
}

BiTree* Insert(int x,BiTree* root,int depth){
    if(root==NULL){
        root=(BiTree*)malloc(sizeof(BiTree));
        root->data=x;
        root->lchild=root->rchild=NULL;
        root->depth=depth;
    }
    else{
        if(x<root->data){
            root->lchild=Insert(x,root->lchild,depth+1);
        }
        else if(x>=root->data){
            root->rchild=Insert(x,root->rchild,depth+1);
        }
    }
    return root;
}

void PrintTree(BiTree* root){
    BiTree *p=root; /* 在树的哪个位置 */
    if(p!=NULL){
        PrintTree(p->lchild);
        if(p->lchild==NULL&p->rchild==NULL) printf("%d %d\n",p->data,p->depth);
        PrintTree(p->rchild);
    }
}


