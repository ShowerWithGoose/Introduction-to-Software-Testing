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
    node* new = (node*)malloc(sizeof(node));
    new->data = x;
    new->lch = NULL;
    new->rch = NULL;
    return new;
}

node* add(node* root, int x) {
    if (root == NULL) {
        node* new = create(x);
        root = new;
        return root;
    }
    if (x < root->data) {
        root->lch = add(root->lch, x); // @@ [The recursive result is not assigned to root->lch, causing the left subtree not to be updated]
    }
    else {
        root->rch = add(root->rch, x); // @@ [The recursive result is not assigned to root->rch, causing the right subtree not to be updated]
    }
    return root;
}

void puthigh(node* root, int high) {
    if (root == NULL) return; // @@ [Missing null check before accessing root->lch and root->rch, which causes segmentation fault when root is NULL]
    if (NULL == root->lch && NULL == root->rch) {
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