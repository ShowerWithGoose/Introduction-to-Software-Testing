#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

struct TreeNode {
    int number;
    int depth;
    struct TreeNode *left;
    struct TreeNode *right;
};
typedef struct TreeNode Tree;
typedef struct TreeNode *Treeptr;

void Insert(int a, Treeptr *t, int depth);
void Inorder(Treeptr t);
Treeptr root = NULL;
int main() {
    int n;
    scanf("%d", &n);
    int a;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a);
        Insert(a, &root, 1); // @@ [Passing 'root' instead of '&root' causes the tree not to be built because the address of root is not passed, so modifications inside Insert don't affect the global root]
    }
    Inorder(root);
    return 0;
}

void Insert(int a, Treeptr *t, int m) {
    if (*t == NULL) {
        *t = (Treeptr)malloc(sizeof(struct TreeNode)); // @@ [Using 'sizeof(Treeptr)' allocates only pointer size (e.g., 8 bytes), not the full struct size, leading to undefined behavior; should be 'sizeof(struct TreeNode)']
        (*t)->left = NULL;
        (*t)->right = NULL;
        (*t)->number = a;
        (*t)->depth = m;
    } else if (a < (*t)->number) {
        Insert(a, &((*t)->left), m + 1);
    } else {
        Insert(a, &((*t)->right), m + 1);
    }
    return; // @@ [Function declared as void but has 'return t;' which is invalid; this line should just be 'return;' or omitted]
}

void Inorder(Treeptr t) {
    if (t != NULL) {
        Inorder(t->left); // @@ [Inorder traversal should visit left, then process node, then right. But leaf check is done before traversing children, and also the traversal order here is not standard inorder; more critically, the problem requires left-to-right leaf output which matches inorder, but current code checks leaf before recursing left, which is incorrect placement]
        if ((t->left == NULL) && (t->right == NULL)) {
            printf("%d %d\n", t->number, t->depth);
        }
        Inorder(t->right);
    }
}