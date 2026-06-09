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
    } else if (m > p->data ) { // @@ [Error: condition should be '>='. When m equals p->data, the node should be inserted to the right child, but it is ignored here.]
        p->rchild = insert(p->rchild, m);
    } else {
        ;
    }
    return p;
}

void preorder(struct node *t, int h) {
    if (t != NULL) {
        if ((t->lchild == NULL) && (t->rchild == NULL)) { // @@ [Error: Leaf printing is performed before traversing left subtree. To output leaves in left-to-right order, the print should occur after the left subtree traversal and before the right subtree traversal (in-order).]
            printf("%d %d\n", t->data, h);
        }
        preorder(t->lchild, h + 1);
        preorder(t->rchild, h + 1);
    }

}