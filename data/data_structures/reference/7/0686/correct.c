#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define M 100

typedef struct node{
    int val;
    struct node* lchild, *rchild;
}BST;

BST* initbst(){
    int n;
    BST* root = NULL, *p, *fron = NULL;
    scanf("%d", &n);
    for(int i = 0; i<n; i++){
        int num;
        p = root;
        scanf("%d", &num);
        while(p != NULL){
            if(num<(p->val)){
                fron = p;
                p = p->lchild;
            }
            else{
                fron = p;
                p = p->rchild;
            }
        }
        p = (BST*) malloc (sizeof(BST));
        p ->lchild = NULL;
        p ->rchild = NULL;
        p->val = num;
        if(root == NULL)
            root = p;
        else if(num<fron->val)
            fron->lchild = p;
        else if(num >= fron->val)
            fron->rchild = p;
    }
    return root;
}

void print(BST* root, int heigh){
    if(root->lchild!=NULL){
        print(root->lchild, heigh+1);
    }
    if(root->rchild!=NULL){
        print(root->rchild, heigh+1);
    }
    if(root->lchild == NULL && root->rchild == NULL){
        printf("%d %d\n", root->val, heigh);
    }
}

int main(){
    BST* root = initbst();
    print(root, 1);

    return 0;
}
