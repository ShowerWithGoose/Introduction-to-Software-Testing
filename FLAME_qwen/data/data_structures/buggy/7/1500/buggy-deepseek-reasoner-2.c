#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct tree tree;
struct tree
{
    int item;
    tree* left;
    tree* right;
};
void creat(tree* cur, int x);
void printftree(tree* cur, int depth);
int main() {
    int n = 0, x = 0,i=0;
    tree * cur = NULL;
    cur = (tree*)malloc(sizeof(tree)); // @@ [Root node allocated but item never initialized; causes undefined behavior when comparing in creat.]
    cur->left = NULL;
    cur->right = NULL;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        creat(cur, x);
    }
    printftree(cur, 1);
    return 0;
}
void creat(tree* cur, int x) {
    if (x < cur->item) { // @@ [cur->item may be garbage for the first call because the root's item was never set.]
        if (cur->left == NULL) {
            cur->left = (tree*)malloc(sizeof(tree));
            cur->left->item = x;
            cur->left->left = NULL;
            cur->left->right = NULL;
            return;
        }
        else if (cur->left != NULL) {
            creat(cur->left, x);
        }
    }
    else if (x  >= cur->item) {
        if (cur->right == NULL) {
            cur->right= (tree*)malloc(sizeof(tree));
            cur->right->item = x;
            cur->right->left = NULL;
            cur->right->right = NULL;
            return;
        }
        else if (cur->right != NULL) {
            creat(cur->right, x);
        }
    }
}
void printftree(tree* cur, int depth) {
    if (cur->left == NULL && cur->right == NULL) {
        printf("%d %d\n", cur->item, depth-1); // @@ [Depth should be depth, not depth-1. Root height is 1, and initial call uses depth=1.]
    }
    if (cur->left != NULL) {
        printftree(cur->left, depth + 1);
    }
    if (cur->right != NULL) {
        printftree(cur->right, depth + 1);
    }
    return;
}