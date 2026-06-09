#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))

typedef struct bstnode {
    int data;
    struct bstnode* lch;
    struct bstnode* rch;
}node;

node* create(int x) {
    node* new = (node*)malloc(sizeof(node)); // @@ 'new' is a reserved keyword in C++, which may cause compilation errors if the environment uses a C++ compiler; rename to 'newNode' or similar.
    new->data = x;
    new->lch = NULL;
    new->rch = NULL;
    return new;
}

node* add(node* root, int x) {
    if (root == NULL) {
        node* new = create(x); // @@ 'new' is a reserved keyword in C++, which may cause compilation errors; rename to 'newNode'.
        root = new;
        return root;
    }
    if (x < root->data) {
        return add(root->lch, x); // @@ Logical error: The return value of the recursive call is not assigned to root->lch, so the left child pointer is never updated, breaking the BST structure.
    }
    else {
        return add(root->rch, x); // @@ Logical error: The return value of the recursive call is not assigned to root->rch, so the right child pointer is never updated, breaking the BST structure.
    }
    return root;
}

void puthigh(node* root, int high) {
    if (NULL == root->lch && NULL == root->rch) { // @@ Potential null pointer dereference if root is NULL (e.g., when n=0); should verify root != NULL before accessing its members.
        printf("%d %d\n", root->data, high);
        return;
    }
    if (root->lch!=NULL) {
        puthigh(root->lch, high + 1);
    }
    if (root->rch!=NULL) {
        puthigh(root->rch, high + 1);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int newdata, i = 0;
    node* root = NULL;
    for (i = 0; i < n; i++) {
        scanf("%d", &newdata);
        root = add(root, newdata);
    }
    int height = 1;
    puthigh(root, height);
}