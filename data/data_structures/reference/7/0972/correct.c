#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
#include<stdbool.h>
typedef struct TreeNode{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    int deep;
}Tree,*Treep;
int m,n,i,deep=1;
Treep root=NULL;
void VISIT(Treep t){
    printf("%d %d\n",t->val,t->deep);
}
void inorder(Treep t){
    if(t!=NULL){
        inorder(t->left);
        if(t->right==NULL&&t->left==NULL) VISIT(t);
        inorder(t->right);
    }
}
void insert(Treep *t,int num,int deep);
int main(){
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&m);
        insert(&root,m,1);
    }
    inorder(root);
    return 0;
}
void insert(Treep *t,int num,int deep){
    if(*t==NULL){
        *t=(Treep)malloc(sizeof(Treep));
        (*t)->left=(*t)->right=NULL;
        (*t)->val=num;
        (*t)->deep=deep;
    }
    else if(num<(*t)->val){
        insert(&((*t)->left),num,deep+1);
    }
    else{
        insert(&((*t)->right),num,deep+1);
    }
}
