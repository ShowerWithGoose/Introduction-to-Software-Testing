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

void printLeaf(PDT t) // @@ [This function only prints leaf values but not their heights, and does not traverse in left-to-right order with height tracking. Also, it doesn't free memory like the reference, but more critically misses height parameter entirely.]
{
    if (t != NULL)
    {
        if (t->left == NULL && t->right == NULL)
        {
            printf("%d ", t->data); // @@ [Missing height output; problem requires "value and height separated by space", and each leaf on separate line.]
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
    printLeaf(T); // @@ [Calling printLeaf without height tracking; should pass initial height=1 and collect leaves in-order with height. Also output format is wrong: no newline per leaf, no height printed.]
    return 0;
}