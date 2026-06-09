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
        Insert(a, &root, 1); // @@ [Passing 'root' instead of '&root' causes the tree not to be built correctly because the function expects a pointer to a pointer]
    }
    Inorder(root);
    return 0;
}

void Insert(int a, Treeptr *t, int m) {
    if (*t == NULL) {
        *t = (Treeptr)malloc(sizeof(struct TreeNode)); // @@ [Using sizeof(Treeptr) only allocates size of a pointer, not the full struct, leading to undefined behavior]
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
        Inorder(t->left); // @@ [Inorder traversal should visit left, then process node, then right. Current code checks leaf condition before traversing left, and also does not follow correct inorder sequence for leaf output]
        if ((t->left == NULL) && (t->right == NULL)) {
            printf("%d %d\n", t->number, t->depth);
        }
        Inorder(t->right);
    }
}