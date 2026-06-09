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
} // @@ [The function does not return the node pointer `p` in all control paths. When `p` is not NULL, the function falls through without a return statement, leading to undefined behavior.]

void searchTree(struct tree* p){
    if(p->left == NULL && p->right == NULL){
        printf("%d %d\n",p->data,p->high);
    }
    else{
        if(p->left!=NULL) searchTree(p->left);
        if(p->right!=NULL) searchTree(p->right);
    }
} // @@ [The traversal order is not guaranteed to be left-to-right in terms of leaf appearance in the BST. However, more critically, the function does not handle the case when `p` is NULL, which can cause a segmentation fault if called on an empty tree or during recursive calls on missing children. But in this specific test case, the real issue stems from the missing return in `insertTree`, which corrupts the tree structure.]