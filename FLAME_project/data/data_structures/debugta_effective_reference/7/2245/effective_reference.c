#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct node {
    int num,h;
    struct node* left, * right;
}BTNode, * BTREE;
BTREE  insertBST(BTREE p, int item)// 将一个数据元素item  插入到根指针为root  的二叉排序树中。 递归算法
{
    if (p == NULL) {
        p = (BTREE)malloc(sizeof(BTNode));
        p->num = item;
        p->h = 1;
        p->left = NULL;
        p->right = NULL;
    }
    else {
        if (item < p->num) {
            p->left = insertBST(p->left, item);
            p->left->h=p->h+1;
        }
        else{
            p->right = insertBST(p->right, item);
            p->right->h = p->h + 1;
        }
    }
    return p;
}

void printLeaf(BTREE p) {//（递归）
    //t为二叉树根结点所在链结点的地址
    if (p != NULL) {
        printLeaf(p->left);
        //visit(t);//访问t指向结点
        if (p->left == NULL && p->right == NULL) {
            printf("%d %d\n", p->num, p->h);
        }
        printLeaf(p->right);
    }
}

int main() {
    BTREE root = NULL;
    int item[1000] = { 0 },i=0,t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &item[i]);
        root = insertBST(root, item[i]);
        i++;
    }
    printLeaf(root);
    return 86;
}
//13
//50 38 30 64 58 40 10 73 70 50 60 100 35
