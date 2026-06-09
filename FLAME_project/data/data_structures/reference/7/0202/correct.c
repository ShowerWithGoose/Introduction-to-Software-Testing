#include<stdio.h>
#include<stdlib.h>
typedef struct BST{
    int data;
    struct BST *left,*right;
}bst,*pbst;
pbst createBst(pbst root,int data){
    if(root==NULL){
        root=(pbst)malloc(sizeof(bst));
        root->data=data;
        root->left=NULL;
        root->right=NULL;
        return root;
    }
    else{
        if(data<root->data){
            root->left=createBst(root->left,data);
        }
        else{
            root->right=createBst(root->right,data);
        }
        return root;
    }
}
void print(pbst root,int height){
    if(root==NULL)return;
    if(root->left!=NULL)print(root->left,height+1);
    if(root->right!=NULL)print(root->right,height+1);
    if(root->left==NULL&&root->right==NULL){
        printf("%d %d\n",root->data,height);
        return;
    }
    
}

int main(){
    pbst root=NULL;
    int n;
    int data;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&data);
        root=createBst(root,data);
    }
    print(root,1);
    return 0;
}

