#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *lchild;
    struct node *rchild;
};
struct node *first = NULL;
struct node *insert(struct node *p, int m);
void preorder(struct node *t, int h);

int main() {
    int n, m, h = 1;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &m);
        first = insert(first, m);
    }
    preorder(first, h);
    return 0;
}

struct node *insert(struct node *p, int m) {
    if (p == NULL) {
        p = (struct node *)malloc(sizeof(struct node));
        p->data = m;
        p->lchild = p->rchild = NULL;
    } else if (m < p->data ) {
        p->lchild = insert(p->lchild, m);
    } else if (m > p->data ) {
        p->rchild = insert(p->rchild, m);
    } else {
        ; // @@ [The problem requires right child to include values >= root, but this code ignores duplicates (does not insert when m == p->data), which may lead to missing nodes and incorrect leaf output.]
    }
    return p;
}

void preorder(struct node *t, int h) {
    if (t != NULL) {
        if ((t->lchild == NULL) && (t->rchild == NULL)) {
            printf("%d %d\n", t->data, h);
        }
        preorder(t->lchild, h + 1);
        preorder(t->rchild, h + 1);
    } // @@ [The traversal is preorder, but the problem requires left-to-right order of leaf nodes, which corresponds to inorder traversal. Using preorder may output leaves in wrong order.]
}