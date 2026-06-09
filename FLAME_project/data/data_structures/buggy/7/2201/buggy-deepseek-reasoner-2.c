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
    int data; // @@ Missing depth field in node structure.
    struct _DT *left, *right;
} DT, *PDT;

PDT insert(PDT root, int data) // @@ Missing depth parameter; need to track depth.
{
    if (root == NULL)
    {
        PDT temp = (PDT)malloc(sizeof(DT));
        temp->data = data; // @@ Missing initialization of node depth.
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data); // @@ Forgot to pass depth+1.
    }
    else
    {
        root->right = insert(root->right, data); // @@ Forgot to pass depth+1.
    }
    return root;
}

void printLeaf(PDT t)
{
    if (t != NULL)
    {
        if (t->left == NULL && t->right == NULL)
        {
            printf("%d ", t->data); // @@ Should print "%d %d\n" with value and depth; missing height and newline.
        }
        printLeaf(t->left); // @@ Should be called before checking leaf for inorder traversal.
        printLeaf(t->right); // @@ Should be called after checking leaf for inorder traversal.
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