#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node {
    int val;
    int deep;
    struct Node *lchild, *rchild;
} *tree;

tree root = NULL;

tree createTree(int a) {
    tree p = NULL, q = NULL, r = NULL;
    r = (tree) malloc(sizeof(struct Node));
    r->val = a;
    r->rchild = NULL;
    r->lchild = NULL;
    r->deep = 1;
    if ( root == NULL) root = r;
    else {
        p = root;
        while ( p != NULL) {
            r->deep++;
            q = p;
            if ( a < p->val ) {
                p = p->lchild;
            } else {
                p = p->rchild;
            }
        }
        r->deep--;
        r->deep++;
        p = r;
        if ( a < q->val ) {
            q->lchild = p;
        } else {
            q->rchild = p;
        }
    }

    return root;
}

void printLeaf(tree p) {
    if ( p->lchild != NULL)
        printLeaf(p->lchild);
    if ( p->rchild != NULL)
        printLeaf(p->rchild);
    if ( p->lchild == NULL && p->rchild == NULL)
        printf("%d %d\n", p->val,p->deep);
}


int main() {
    int i, j, k, n, t;

    scanf("%d", &n);

    for ( i = 0; i < n; i++ ) {
        scanf("%d", &k);
        root = createTree(k);
    }
    printLeaf(root);

    return 0;
}


