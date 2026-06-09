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
            printf("%d ", t->data); // @@ [This prints only the value, but the problem requires printing both value and height. Also, height tracking is missing.]
        }
        printLeaf(t->left); // @@ [Recursive calls do not pass or track node height, so height cannot be determined for leaf nodes.]
        printLeaf(t->right); // @@ [Same issue: no height information is maintained during traversal.]
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
    printLeaf(T); // @@ [Function does not output heights and does not format output as "value height\n" per leaf in left-to-right order.]
    return 0;
}