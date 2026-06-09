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
    int depth; // @@ The struct is missing the 'depth' field required to store and output the height of nodes.
    struct _DT *left, *right;
} DT, *PDT;

PDT insert(PDT root, int data, int depth) // @@ The function signature is missing the 'depth' parameter needed to track node height during insertion.
{
    if (root == NULL)
    {
        PDT temp = (PDT)malloc(sizeof(DT));
        temp->data = data;
        temp->depth = depth; // @@ Need to assign the calculated depth to the new node.
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data, depth + 1); // @@ Need to pass incremented depth when recursing left.
    }
    else
    {
        root->right = insert(root->right, data, depth + 1); // @@ Need to pass incremented depth when recursing right.
    }
    return root;
}

void printLeaf(PDT t)
{
    if (t != NULL)
    {
        printLeaf(t->left); // @@ Must traverse left subtree first to ensure left-to-right output order (in-order traversal).
        if (t->left == NULL && t->right == NULL)
        {
            printf("%d %d\n", t->data, t->depth); // @@ Output format must include both value and depth, separated by space, followed by newline. The original code only printed data and missed the depth.
        }
        printLeaf(t->right); // @@ Must traverse right subtree after processing current node/left subtree.
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
        T = insert(T, num, 1); // @@ Need to pass initial depth 1 when calling insert.
    }
    printLeaf(T);
    return 0;
}