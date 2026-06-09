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
    if (p->left == NULL && p->right == NULL) {
        printf("%d %d\n", p->data,high);
        return;
    } if (p->left != NULL) { // @@ [Missing 'else' before this 'if'; though not strictly causing logical error here due to returns, it's inconsistent and may lead to confusion. However, the real issue is that if p is NULL, this function dereferences a null pointer. The function lacks a base case for p == NULL.]
        printleaf(p->left,high+1);
    } if (p->right != NULL) { // @@ [Same as above: no check for p == NULL at start of function; if called with NULL (e.g., empty tree), it crashes. Also, missing else leads to unnecessary checks but not primary bug.]
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
    printleaf(root,1); // @@ [If n == 0, root is NULL, and printleaf will dereference NULL, causing runtime crash. But more critically, the insert function has a logic flaw due to missing 'else', which may cause incorrect tree structure.]
}