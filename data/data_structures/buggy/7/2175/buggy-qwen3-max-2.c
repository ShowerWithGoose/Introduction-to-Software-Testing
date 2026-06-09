#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<ctype.h>
#include <alloca.h> // @@ [Including <alloca.h> is non-standard and unnecessary; may cause portability issues, but not the main error here.]
#define ma(a,b) (a)>(b)?(a):(b);
#define mi(a,b) (a)<(b)?(a):(b);

#define M 1005

typedef struct tree {
    char data; // @@ [The 'data' field is declared as 'char', but the problem involves integers. This causes incorrect storage and output of integer values as characters.]
    struct tree* lchild, *rchild;
} bn, *btree;
btree insert(int data, btree p) {
    if (p == NULL) {
        p = (btree)malloc(sizeof(bn)); // @@ [Correct size is used here (sizeof(bn)), unlike the reference program which incorrectly used sizeof(nodeptr). However, the 'data' type mismatch remains the critical issue.]
        p->data = data;
        p->lchild = p->rchild = NULL;
    } else if (data < p->data) {
        p->lchild = insert(data, p->lchild);
    } else {
        p->rchild = insert(data, p->rchild);
    }
    return p;
}
void preorder(btree t, int dep) {
    if (t != NULL) {
        preorder(t->lchild, dep + 1);
        if (t->lchild == NULL && t->rchild == NULL) {
            printf("%d %d\n", t->data, dep); // @@ [Printing 't->data' as %d is inconsistent with its declaration as 'char'. This leads to undefined behavior or incorrect output when integer values exceed char range.]
        }
        preorder(t->rchild, dep + 1);

    }
}
int main() {
    int n, a;
    scanf("%d", &n);
    btree p = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        p = insert(a, p);
    }
    preorder(p, 1);
    return 0;
}