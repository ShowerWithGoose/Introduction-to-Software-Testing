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
    return p; // @@ [The function does not return a value in all control paths. When the node is not NULL, after recursive calls, it must return 'p'. Missing return causes undefined behavior.]
}

void searchTree(struct tree* p){
    if(p == NULL) return; // @@ [If p is NULL, accessing p->left or p->right leads to segmentation fault. The function lacks a base case check for NULL input.]
    if(p->left == NULL && p->right == NULL){
        printf("%d %d\n",p->data,p->high);
    }
    else{
        if(p->left!=NULL) searchTree(p->left);
        if(p->right!=NULL) searchTree(p->right);
    }
}