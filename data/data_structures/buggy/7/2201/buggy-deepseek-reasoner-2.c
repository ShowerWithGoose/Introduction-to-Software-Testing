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

void printLeaf(PDT t) // @@ [missing height parameter; need to pass current height to print leaf values with heights]
{
    if (t != NULL)
    {
        if (t->left == NULL && t->right == NULL)
        {
            printf("%d ", t->data); // @@ [should print height and newline: printf("%d %d\n", t->data, height)]
        }
        printLeaf(t->left); // @@ [recursive call missing height argument; should pass height+1]
        printLeaf(t->right); // @@ [recursive call missing height argument; should pass height+1]
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
    printLeaf(T); // @@ [missing height argument; should pass 1 as initial height]
    return 0;
}