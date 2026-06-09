#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node {
    int data,high;
    struct node* left, * right;
}BTNode, * BTREE;
BTREE  insertBST(BTREE p, int item)// 将一个数据元素item  插入到根指针为root  的二叉排序树中。 递归算法
{
    if (p == NULL) {
        p = (BTREE)malloc(sizeof(BTNode));
        p->data = item;
        p->high = 1;
        p->left = NULL;
        p->right = NULL;
    }
    else {
        if (item < p->data) {
            p->left = insertBST(p->left, item);
            p->left->high=p->high+1;
        }
        else{
            p->right = insertBST(p->right, item);
            p->right->high = p->high + 1;
        }
    }
    return p;
}

void inorder(BTREE t) {//（递归）
    //t为二叉树根结点所在链结点的地址
    if (t != NULL) {
        inorder(t->left);
        //visit(t);//访问t指向结点
        if (t->left == NULL && t->right == NULL) {
            printf("%d %d\n", t->data, t->high);
        }
        inorder(t->right);
    }
}

int main() {
    BTREE root = NULL;
    int k[1000] = { 0 },i=0,n;
    scanf("%d", &n);
    while (n--) {
        scanf("%d", &k[i]);
        root = insertBST(root, k[i]);
        i++;
    }
    inorder(root);
    return 86;
}
//13
//50 38 30 64 58 40 10 73 70 50 60 100 35
