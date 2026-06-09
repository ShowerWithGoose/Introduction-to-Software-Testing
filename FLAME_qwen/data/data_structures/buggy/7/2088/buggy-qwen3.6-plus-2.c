#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct treee {
    int num;
    struct treee *left, *right;
} tree;
tree *a = NULL, *a0 = a, *p; // @@ p is not explicitly initialized; although global variables are zero-initialized by default, explicit initialization to NULL is safer to prevent undefined behavior if accessed before assignment.

void schtree(tree *whr, int layr) {
    //printf("%d,%d\n", layr, whr->num);
    if (whr->left == NULL && whr->right == NULL) {
        printf("%d %d\n", whr->num, layr);
        return;
    }
    if (whr->left != NULL) {
        schtree(whr->left, layr + 1);
    }
    if (whr->right != NULL) {
        schtree(whr->right, layr + 1);
    }
}

int main() {
    int n, x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        a = a0;
        int ch = 0;
        while (a != NULL) {
            p = a;
            if (x < a->num) {
                a = a->left;
                ch = 1;
            } else {
                a = a->right;
                ch = 2;
            }
        }
        a = (tree *)malloc(sizeof(tree));
        if (i == 0) {
            a0 = a;
        }
        a->left = a->right = NULL;
        a->num = x;
        if (ch == 1) {
            p->left = a;
        } else if (ch == 2) {
            p->right = a;
        }
    }
    schtree(a0, 1); // @@ If n is 0, a0 remains NULL, causing a segmentation fault when accessing whr->left. Should add a check for n > 0 or a0 != NULL before calling.
    return 0;
}