#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include <memory.h>
#include <stdbool.h>
#define mian main
typedef long long ll;
typedef unsigned long long ull;
typedef struct bst treeNode, *pNode;
struct bst
{
    pNode l, r;
    int data, degree;
};
void Insert(pNode* p, int num);
void print(pNode p);
int main(int argc, const char *argv[])
{
    pNode root = NULL;
    int n, tmp;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &tmp);
        Insert(&root, tmp);
    }
    print(root);
    return 0;
}
void Insert(pNode *root, int num)
{
    int flag = 1;
    if (*root == NULL)
    {
        *root = (pNode)malloc(sizeof(treeNode));
        (*root)->l = NULL;
        (*root)->r = NULL;
        (*root)->data = num;
        (*root)->degree = 1;
        return;
    }
    else
    {
        pNode now = *root, parent = NULL;
        while (now != NULL)
        {
            parent = now;
            if (num < now->data)
            {
                now = now->l;
                flag = 1;
            }
            else
            {
                now = now->r;
                flag = 0;
            }
        }
        pNode newNode = (pNode)malloc(sizeof(treeNode));
        newNode->data = num;
        newNode->l = NULL;
        newNode->r = NULL;
        newNode->degree = parent->degree + 1;
        if (flag)
            parent->l = newNode;
        else
            parent->r = newNode;
    }
}
void print(pNode p)
{
    if (p == NULL)
        return;
    print(p->l);
    if (p->l == NULL && p->r == NULL)
    {
        printf("%d %d\n", p->data, p->degree);
    }
    print(p->r);
}


