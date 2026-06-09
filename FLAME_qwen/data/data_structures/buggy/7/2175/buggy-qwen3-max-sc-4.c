#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include <math.h>
#include<ctype.h>
#include <alloca.h> // @@ [Including <alloca.h> is non-standard and unnecessary; may cause portability issues, but not the main error here]
#define ma(a,b) (a)>(b)?(a):(b);
#define mi(a,b) (a)<(b)?(a):(b);

#define M 1005

typedef struct tree {
    char data; // @@ [The 'data' field is declared as 'char', but the problem requires storing integers. This causes incorrect storage and output of integer values.]
    struct tree* lchild, *rchild;
} bn, *btree;
btree insert(int data, btree p) {
    if (p == NULL) {
        p = (btree)malloc(sizeof(bn)); // @@ [Correct size is used here (sizeof(bn)), so this line is okay. However, note that in the reference program, sizeof(nodeptr) was wrong — but that's not this code.]
        p->data = data; // @@ [Assigning int to char truncates values > 127 or < -128, leading to incorrect node values.]
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
            printf("%d %d\n", t->data, dep); // @@ [Printing t->data as %d while it's a char leads to sign-extension or garbage for values outside char range. Should be consistent with int storage.]
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