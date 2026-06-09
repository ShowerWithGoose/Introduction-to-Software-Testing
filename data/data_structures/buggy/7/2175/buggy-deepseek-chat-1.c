#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<ctype.h>
#include <alloca.h> // @@ [alloca.h is not a standard header and may cause compilation errors; it should be removed or replaced with a standard header]
#define ma(a,b) (a)>(b)?(a):(b);
#define mi(a,b) (a)<(b)?(a):(b);

#define M 1005

typedef struct tree {
    char data; // @@ [data should be int to store integer values from input, not char]
    struct tree* lchild, *rchild;
} bn, *btree;
btree insert(int data, btree p) {
    if (p == NULL) {
        p = (btree)malloc(sizeof(bn));
        p->data = data; // @@ [data is char, but assigning int may cause truncation or type mismatch]
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
            printf("%d %d\n", t->data, dep); // @@ [t->data is char, but %d expects int; this will print ASCII value instead of the integer]
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