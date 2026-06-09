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
    int data; // @@ missing depth field
    struct _DT *left, *right;
} DT, *PDT;

PDT insert(PDT root, int data) // @@ missing depth parameter; should pass and store height
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

void printLeaf(PDT t)
{
    if (t != NULL)
    {
        if (t->left == NULL && t->right == NULL)
        {
            printf("%d ", t->data); // @@ should print data and depth with newline; e.g., "%d %d\n"
        }
        printLeaf(t->left); // @@ traversal order is preorder; should be inorder (left, print, right)
        printLeaf(t->right); // @@ same reason; order incorrect
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
    printLeaf(T);
    return 0;
}