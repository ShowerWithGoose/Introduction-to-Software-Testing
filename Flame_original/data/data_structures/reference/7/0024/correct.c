#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
#include<ctype.h>

typedef struct TN{
    int val;
    struct TN *left, *right;
    int depth;
}Tree;

#define VISIT(A) printf("%d %d\n", A->val, A->depth)

/*Inorder2函数用来输出所有结点*/
Tree * InsertBST(Tree *T, int val, int depth);
void Inorder(Tree *T);
void Inorder2(Tree *T);

int main(){
    Tree *root = NULL;
    int val, n, depth = 1;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &val);
        root = InsertBST(root, val, depth);
        // printf("\n");
    }
    Inorder(root);

    return 0;
}

Tree * InsertBST(Tree *T, int val, int depth){
    if(T == NULL){
        T = (Tree*)malloc(sizeof(Tree));
        T->val = val;
        T->left = NULL;
        T->right = NULL;
        T->depth = depth;
        // VISIT(T);
    }
    else if(val < T->val){
        // VISIT(T);
        T->left = InsertBST(T->left, val, depth+1);
    }
    else if(val >= T->val){
        // VISIT(T);
        T->right = InsertBST(T->right, val, depth+1);
    }
    return T;
}

void Inorder(Tree *T){
    if(T != NULL){
        if(T->left == NULL && T->right == NULL)     VISIT(T);
        Inorder(T->left);
        Inorder(T->right);
    }
}

void Inorder2(Tree *T){
    if(T != NULL){
        VISIT(T);
        Inorder2(T->left);
        Inorder2(T->right);
    }
}
