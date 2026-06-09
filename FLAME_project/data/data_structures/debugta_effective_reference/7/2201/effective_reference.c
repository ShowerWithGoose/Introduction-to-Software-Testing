#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    int depth;
    struct node *left,*right;
}BTnode,*BTnodeptr;
BTnodeptr T=NULL;
BTnodeptr insert(BTnodeptr root,int num,int depth){
    if(root==NULL){
        root=(BTnodeptr)malloc(sizeof(BTnode));
        root->data=num;
        root->depth=depth;
        root->left=NULL;
        root->right=NULL;
    }
    else if(num<root->data){
        root->left=insert(root->left,num,depth+1);
    }
    else{
        root->right=insert(root->right,num,depth+1);
    }
    return root;
}
void visit(BTnodeptr t){
    printf("%d %d\n",t->data,t->depth);
}
void inorder(BTnodeptr t){
    if(t!=NULL){
        inorder(t->left);
        if(t->left==NULL&&t->right==NULL)visit(t);
        inorder(t->right);
    }
}
int main(){
    int n,num;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&num);
        T=insert(T,num,1);
    }
    inorder(T);
    return 0;
}
