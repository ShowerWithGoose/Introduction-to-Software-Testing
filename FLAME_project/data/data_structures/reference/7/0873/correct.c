#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<assert.h>
#define _CRT_SECURE_NO_WARNINGS 1
#define Maxlen 1//链式存储的串单个链接的字节
#define Maxsize 100
typedef struct tree {
    int data;
    struct tree* left, * right;
    int deep;
}Tree, * BTree;
int n;
int a[Maxsize];
BTree  insert_binary_sort_tree(BTree t, int item, int deep) {
    if (t == NULL) {
        t = (BTree)malloc(sizeof(Tree));
        t->data = item;
        t->left = NULL;
        t->right = NULL;
        t->deep = deep;
    }
    else if (item < t->data)
        t->left=insert_binary_sort_tree(t->left, item, deep + 1);
    else if (item>=t->data)
        t->right=insert_binary_sort_tree(t->right, item, deep + 1);
    return t;
}

void print(BTree t) {
    if (t != NULL) {
        print(t->left);
        if (t->left == NULL && t->right == NULL)
            printf("%d %d\n", t->data, t->deep);
        
        print(t->right);
    }
}
int main() {
    scanf("%d", &n);
    BTree root = NULL;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        root=insert_binary_sort_tree(root, a[i], 1);
    }
    print(root);
    return 0;
}


