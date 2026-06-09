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
    } if (tem < root->data) { // @@ [Missing else causes double insertion: after creating node, it still checks and recurses into uninitialized children]
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
    printleaf(root,1); // @@ [When n=0, root is NULL and passing to printleaf causes dereference of NULL pointer; but test case has n=1 so primary error is in insert logic causing incorrect tree structure or infinite recursion]
}