#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    int depth;
    struct node *left,*right;
}BTnode,*BTnodeptr;
BTnodeptr root=NULL;
BTnodeptr insert(BTnodeptr T,int item,int depth){
    if(T==NULL){
        T=(BTnodeptr)malloc(sizeof(BTnode));
        T->data=item;
        T->depth=depth;
        T->left=NULL;
        T->right=NULL;
    }
    else if(item<T->data){
        T->left=insert(T->left,item,depth+1);
    }
    else{
        T->right=insert(T->right,item,depth+1);
    }
    return T;
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
    int n,item;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&item);
        root=insert(root,item,1);
    }
    inorder(root);
    return 0;
}
