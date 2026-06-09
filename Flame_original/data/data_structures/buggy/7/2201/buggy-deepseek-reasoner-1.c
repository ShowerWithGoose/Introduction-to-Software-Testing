#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

#define eps 1e-10
#define LL long long

typedef struct _DT
{
    int data;
    struct _DT *left, *right;
} DT, *PDT;

PDT insert(PDT root, int data)
{
    if (root == NULL)
    {
        PDT temp = (PDT)malloc(sizeof(DT));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }
    return root;
}

void printLeaf(PDT t) @@ // [Missing height parameter; should be void printLeaf(PDT t, int height)]
{
    if (t != NULL)
    {
        if (t->left == NULL && t->right == NULL)
        {
            printf("%d ", t->data); @@ // [Should print height and use newline: printf("%d %d\n", t->data, height);]
        }
        printLeaf(t->left); @@ // [Should pass height+1: printLeaf(t->left, height+1);]
        printLeaf(t->right); @@ // [Should pass height+1: printLeaf(t->right, height+1);]
    }
    return;
}

int main()
{

    int n, num;
    scanf("%d", &n);
    PDT T = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        T = insert(T, num);
    }
    printLeaf(T); @@ // [Should pass initial height 1: printLeaf(T, 1);]
    return 0;
}