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
    return p; // @@ The function is declared to return a struct tree*, but the original code lacks a return statement, leading to undefined behavior when the returned pointer is used in main.
}

void searchTree(struct tree* p){
    if(p == NULL) return; // @@ The original code does not check if p is NULL before accessing its members. If the tree is empty or during recursion on non-existent children, this will cause a segmentation fault. Although the current logic tries to avoid calling on NULL, adding a guard is safer and standard practice, but strictly speaking, the immediate crash in the provided buggy output suggests the missing return in insertTree is the primary logical error causing corruption. However, looking at the specific failure "0 2" vs expected, the missing return causes `root` in main to potentially be garbage or unchanged incorrectly after the first insertion if the compiler optimizes poorly or stack is corrupted. But wait, if `insertTree` doesn't return `p`, `root = insertTree(...)` assigns undefined value. This is the critical error.
    if(p->left == NULL && p->right == NULL){
        printf("%d %d\n",p->data,p->high);
    }
    else{
        if(p->left!=NULL) searchTree(p->left);
        if(p->right!=NULL) searchTree(p->right);
    }
}