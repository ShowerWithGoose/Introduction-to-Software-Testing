#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct tree{
    int high;
    int data;
    struct tree* left;
    struct tree* right;
};
struct tree* insertTree(struct tree* p,int item,int high);
void searchTree(struct tree* p);
int main()
{
    int n,i,item;
    struct tree* root = NULL; 
    scanf("%d",&n);
    for(i = 0;i < n;i++){
        scanf("%d",&item);
        root = insertTree(root,item,1);
    }
    //printf("%d %d",root->data,root->high);
    searchTree(root);
    return 0;
}

struct tree* insertTree(struct tree* p,int item,int high){
    if(p == NULL){
        p = (struct tree*)malloc(sizeof(struct tree));
        p->data = item;
        p->high = high;
        p->left = NULL;
        p->right = NULL;
    }
    else if(item < p->data){
        p->left = insertTree(p->left,item,high+1);
    }
    else{
        p->right = insertTree(p->right,item,high+1);
    }
} // @@ Missing return statement: after updating left or right, the function must return p to propagate the modified tree back to the caller. Without this, the return value is undefined, leading to compilation errors or undefined behavior.
void searchTree(struct tree* p){
    if(p->left == NULL && p->right == NULL){ // @@ No check for NULL pointer: if root is NULL (e.g., n=0), dereferencing p->left causes segmentation fault. The function should first test for NULL and return.
        printf("%d %d\n",p->data,p->high);
    }
    else{
        if(p->left!=NULL) searchTree(p->left);
        if(p->right!=NULL) searchTree(p->right);
    }
}