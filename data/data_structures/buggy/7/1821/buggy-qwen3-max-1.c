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
        Insert(a, &root, 1); // @@ [Passing 'root' instead of '&root' causes the tree not to be built correctly because the address of root is needed to modify it]
    }
    Inorder(root);
    return 0;
}

void Insert(int a, Treeptr *t, int m) {
    if (*t == NULL) {
        *t = (Treeptr)malloc(sizeof(struct TreeNode)); // @@ [Using 'sizeof(Treeptr)' allocates only pointer size, not the full struct size, leading to undefined behavior]
        (*t)->left = NULL;
        (*t)->right = NULL;
        (*t)->number = a;
        (*t)->depth = m;
    } else if (a < (*t)->number) {
        Insert(a, &((*t)->left), m + 1);
    } else {
        Insert(a, &((*t)->right), m + 1);
    }
    return; // @@ [Function declared as void but returns 't'; this line should be removed or changed to just 'return;' without value]
}

void Inorder(Treeptr t) {
    if (t != NULL) {
        Inorder(t->left); // @@ [Inorder traversal should visit left, then node, then right. Current code checks leaf before traversing children, and also visits right after left without processing node in between — but more critically, the order of checking leaf and recursing is wrong for inorder]
        if ((t->left == NULL) && (t->right == NULL)) {
            printf("%d %d\n", t->number, t->depth);
        }
        Inorder(t->right);
    }
}