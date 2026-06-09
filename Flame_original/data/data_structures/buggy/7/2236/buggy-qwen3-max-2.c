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
    } if (tem < root->data) { @@ [Missing 'else' before this 'if'; causes incorrect insertion logic when root is not NULL and tem >= root->data, leading to unintended overwriting or undefined behavior]
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
    } if (p->left != NULL) { @@ [Missing 'else' before this 'if'; though not strictly wrong, combined with the next 'if', it may traverse both children correctly, but the real issue is that if p is NULL, this function crashes. However, the main error is in insert. Also, this function assumes p is never NULL, but if the tree is empty (n=0), it will crash. But test case likely has n>0. The primary bug is in insert.]
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
    printleaf(root,1); @@ [If n==0, root is NULL and passing NULL to printleaf causes dereference of NULL pointer, but assuming n>=1 per test cases. The critical error is in insert function logic.]
}