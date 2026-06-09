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
    return p; // @@ [The function insertTree is missing a return statement in non-void function; when p != NULL, it doesn't return anything, leading to undefined behavior.]
}

void searchTree(struct tree* p){
    if(p == NULL) return; // @@ [The function searchTree dereferences p without checking if it's NULL first, which can cause a segmentation fault when called on an empty tree or null child.]
    if(p->left == NULL && p->right == NULL){
        printf("%d %d\n",p->data,p->high);
    }
    else{
        if(p->left!=NULL) searchTree(p->left);
        if(p->right!=NULL) searchTree(p->right);
    }
}