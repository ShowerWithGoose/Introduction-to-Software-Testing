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
        Insert(a, &root, 1); // @@ [Passing 'root' instead of '&root' causes the tree not to be built correctly because the function expects a pointer to a pointer to modify the root]
    }
    Inorder(root);
    return 0;
}

void Insert(int a, Treeptr *t, int m) {
    if (*t == NULL) {
        *t = (Treeptr)malloc(sizeof(struct TreeNode)); // @@ [Using 'sizeof(Treeptr)' allocates only the size of a pointer, not the full struct, leading to undefined behavior; should be 'sizeof(struct TreeNode)']
        (*t)->left = NULL;
        (*t)->right = NULL;
        (*t)->number = a;
        (*t)->depth = m;
    } else if (a < (*t)->number) {
        Insert(a, &((*t)->left), m + 1);
    } else {
        Insert(a, &((*t)->right), m + 1);
    }
    return; // @@ [The function is declared as void but attempts to return 't', which is invalid and causes a compilation error]
}

void Inorder(Treeptr t) {
    if (t != NULL) {
        Inorder(t->left); // @@ [The inorder traversal is incorrect for left-to-right leaf output: it checks for leaf before recursing left, and also recurses right after, but the check should happen between left and right recursion to maintain in-order (left-root-right) sequence]
        if ((t->left == NULL) && (t->right == NULL)) {
            printf("%d %d\n", t->number, t->depth);
        }
        Inorder(t->right);
    }
}