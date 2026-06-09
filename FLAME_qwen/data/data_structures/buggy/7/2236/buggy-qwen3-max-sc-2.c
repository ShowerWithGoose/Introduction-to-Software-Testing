#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
struct node {
    int data;
    struct node *left, *right;
};
struct node *insert(int tem, struct node* root) {
    if (root == NULL) {
        root = (struct node*)malloc(sizeof(struct node));
        root->data = tem;
        root->left = NULL;
        root->right = NULL;
    } if (tem < root->data) { // @@ [Missing 'else' before this 'if'; causes incorrect insertion logic when root is not NULL and tem >= root->data, leading to unintended double insertion or undefined behavior]
        root->left = insert(tem, root->left);
    } else {
        root->right = insert(tem, root->right);
    }
    return root;
};
void printleaf(struct node *p,int high) {
    if (p == NULL) return; // @@ [Missing null check at start of function; if root is NULL (empty tree), dereferencing p->left/right causes segmentation fault]
    if (p->left == NULL && p->right == NULL) {
        printf("%d %d\n", p->data,high);
        return;
    } if (p->left != NULL) {
        printleaf(p->left,high+1);
    } if (p->right != NULL) {
        printleaf(p->right,high+1);
    }
};
int main(){
    int n;
    int tem;
    struct node *root = NULL;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &tem);
        root = insert(tem, root);
    }
    printleaf(root,1);
}