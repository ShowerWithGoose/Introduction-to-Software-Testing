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
    cur = (tree*)malloc(sizeof(tree)); // @@ The root node is allocated but its 'item' field is uninitialized. When the first number is inserted, it is compared against this garbage value instead of becoming the root or being compared correctly.
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
    if (x < cur->item) {
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
        printf("%d %d\n", cur->item, depth-1); // @@ The height calculation is incorrect. It subtracts 1 from the current depth. Since the root is passed with depth 1, leaf depths are calculated relative to that, but subtracting 1 results in heights that are too small (e.g., root leaf would be 0 instead of 1). It should just print 'depth'.
    }
    if (cur->left != NULL) {
        printftree(cur->left, depth + 1);
    }
    if (cur->right != NULL) {
        printftree(cur->right, depth + 1);
    }
    return;
}