#include <stdio.h>
#include <stdlib.h>
struct node {
    int num;
    struct node  *lchild, *rchild;
} *tree;
struct node* insert(struct node * p, int i);
void dps (struct node *p, int high);
int main() {
    int n;
    int a[1000];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        tree = insert(tree, a[i]);
    }
    dps (tree, 1);
    system("pause");
    return 0;
}

struct node* insert(struct node *p, int i) {
    struct node *q;
    if (p == NULL) {
        p = (struct node*)malloc(sizeof (struct node));
        p->num = i;
        p->lchild = NULL;p->rchild = NULL;
        return p;
    } else {
        if (i < p->num) {
            if (p->lchild == NULL) {
                q = (struct node *)malloc(sizeof (struct node));
                p->lchild = q;
                q->num = i;q->lchild = NULL;q->rchild=NULL;
            } else {
                insert(p->lchild, i);
            }
        } else {
            if (p->rchild ==NULL) {
                q = (struct node *)malloc(sizeof (struct node));
                p->rchild = q;
                q->num=i;q->lchild=NULL;q->rchild=NULL;
            } else {
                insert(p->rchild, i);
            }
        }
    }
    return tree;
}

void dps(struct node *p, int high) {
    if (p == NULL)
        return;
    if (p->rchild == NULL && p->lchild == NULL) {
        printf("%d %d\n", p->num, high);
    } else {
        dps(p->lchild, high + 1);
        dps(p->rchild, high + 1);
    }
}

