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
    } if (p->left != NULL) { // @@ [Missing 'else' before this 'if'; though not strictly causing logical error here due to returns, it's inconsistent style and may mislead. However, the real issue is that if p is NULL, this function dereferences NULL. But note: main calls printleaf(root,1) only if root exists? Actually, if n=0, root is NULL and this crashes. But test case likely has n>=1. The bigger issue is in insert.]
        printleaf(p->left,high+1);
    } if (p->right != NULL) { // @@ [Same as above; but more critically, the function does not handle the case where p is NULL. If the tree is empty (n=0), main passes NULL to printleaf, which then accesses p->left/right → segmentation fault. However, problem states "sequence of integers", so n≥1 possibly. Still, robustness aside, the primary bug is in insert logic.]
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
    printleaf(root,1); // @@ [If n is 0, root is NULL and printleaf will crash by dereferencing NULL. But even for n≥1, the insert function has a logical flaw that may cause incorrect tree structure, leading to wrong leaf output.]
}