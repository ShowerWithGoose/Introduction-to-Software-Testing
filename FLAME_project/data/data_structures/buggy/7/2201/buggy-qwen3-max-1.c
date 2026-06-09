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

void printLeaf(PDT t)
{
    if (t != NULL)
    {
        if (t->left == NULL && t->right == NULL)
        {
            printf("%d ", t->data); // @@ [The output format is incorrect: it prints only the value without the height, and uses a space instead of newline. Also, height information is not stored or computed in the node structure.]
        }
        printLeaf(t->left);
        printLeaf(t->right);
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
    printLeaf(T); // @@ [The traversal order is preorder (root, left, right), but the problem requires left-to-right leaf order which corresponds to inorder traversal. Additionally, height is never tracked during insertion or traversal.]
    return 0;
}