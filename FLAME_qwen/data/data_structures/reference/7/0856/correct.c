#include <malloc.h>
#include <stdio.h>

struct num {
    int n;
    int height;
    struct num *lchild, *rchild;
} *root = NULL, *p, *q;

void sort() {
    p = root;
    while (1) {
        q->height++;
        if (q->n < p->n)
            if (p->lchild == NULL) {
                p->lchild = q;
                break;
            } else
                p = p->lchild;
        else {
            if (p->rchild == NULL) {
                p->rchild = q;
                break;
            } else
                p = p->rchild;
        }
    }
    return;
}

void initial() {
    q = (struct num *)malloc(sizeof(struct num));
    scanf("%d", &q->n);
    q->height = 1;
    q->lchild = q->rchild = NULL;
    if (root == NULL)
        root = q;
    else
        sort();
    return;
}

void preorder(struct num *p) {
    if (p == NULL)
        return;
    else if (p->lchild == NULL && p->rchild == NULL) {
        printf("%d %d\n", p->n, p->height);
        return;
    } else {
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) initial();
    preorder(root);
    return 0;
}


