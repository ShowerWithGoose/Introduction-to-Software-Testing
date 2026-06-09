#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

typedef struct node {
    int data;
    int height;
    struct node *lchild, *rchild;
} Tree;


Tree *CreateNewTree(Tree *root, int value, int depth);
void PrintTree(Tree *root);
int main() {

    Tree* root = NULL;
    int n, i, value;
    scanf("%d", &n);
    for(i = 1; i <= n; i++) {
        scanf("%d", &value);
        int depth = 0;
        root = CreateNewTree(root, value, depth);
    }
    PrintTree(root);
    system("pause");
    return 0;
}


Tree* CreateNewTree(Tree* root, int value, int depth) {
    depth++;
    if(root == NULL) {
        root = (Tree*)malloc(sizeof(Tree));
        root->data = value;
        root->lchild = root->rchild = NULL;
        root->height = depth;
    } else if(value < root->data) {
        root->lchild = CreateNewTree(root->lchild, value, depth);
    } else if(value >= root->data){
        root->rchild = CreateNewTree(root->rchild, value, depth);
    }
    return root;
}

void PrintTree(Tree* root) {
    if(root) {
        if(root->lchild == NULL && root->rchild == NULL) {
            printf("%d %d\n", root->data, root->height);
        }
        PrintTree(root->lchild);
        PrintTree(root->rchild);
    }
}
