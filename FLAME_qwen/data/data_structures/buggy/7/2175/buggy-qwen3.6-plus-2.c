#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<ctype.h>
#include <alloca.h> // @@ Non-standard header that may cause compilation failure on some systems; also unused in the code.
#define ma(a,b) (a)>(b)?(a):(b); // @@ Trailing semicolon in macro definition is syntactically incorrect for expression macros and can cause compilation errors upon expansion; also unused.
#define mi(a,b) (a)<(b)?(a):(b); // @@ Trailing semicolon in macro definition is syntactically incorrect for expression macros and can cause compilation errors upon expansion; also unused.

#define M 1005

typedef struct tree {
    char data; // @@ Should be 'int data' to correctly store integer values as specified in the problem; using char may cause overflow and type mismatch warnings/errors.
    struct tree* lchild, *rchild;
} bn, *btree;
btree insert(int data, btree p) {
    if (p == NULL) {
        p = (btree)malloc(sizeof(bn));
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
            printf("%d %d\n", t->data, dep);
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