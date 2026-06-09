#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "math.h"
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 1000

typedef int Status;

typedef struct Node 
{
    int data;
    struct Node *left;
    struct Node *right;
} Node, *Tree;

Status InitTree(Tree T, int data) 
{
    T->data = data;
    T->left = NULL;
    T->right = NULL;
  return OK;
}

Status AddNode(Node *N, int data) 
{
    if (N->data > data) 
    {
        if (N->left) 
        {
            AddNode(N->left, data);
        } 
        else 
        {
            N->left = (Node *)malloc(sizeof(Node));
            N->left->data = data;
            N->left->left = N->left->right = NULL;
            return OK;
        }
    } 
    else
    {
        if (N->right) 
        {
            AddNode(N->right, data);
        }
        else 
        {
            N->right = (Node *)malloc(sizeof(Node));
            N->right->data = data;
            N->right->left = N->right->right = NULL;
            return OK;
        }
    }
    return ERROR; // @@ [This function does not return a value in all recursive paths. When recursing into AddNode(N->left, data) or AddNode(N->right, data), the return value is ignored and the function falls through to return ERROR, which is incorrect.]
}

Status Search(Node *N, Status *Visit(Node *, int), int height) {
  if (N->left)
    Search(N->left, Visit, height + 1); // @@ [Recursive calls do not use return values, but more critically, the logic for identifying leaf nodes is wrong: it prints nodes that have at least one missing child, not only those with both children missing.]
  if (N->right)
    Search(N->right, Visit, height + 1);
  if (!N->left || !N->right) // @@ [This condition is incorrect for detecting leaf nodes. A leaf node must have BOTH left and right as NULL. This condition triggers for any node missing at least one child, including internal nodes with only one child.]
    Visit(N, height);
    return OK;
}

Status *NodePrint(Node *N, int height)
{
    printf("%d %d\n", N->data, height);
    return NULL;
}

int main()
{
    int N;
    scanf("%d", &N);
    int data;
    int height = 1;
    Node tree;
    Tree T = &tree;
    N--; // @@ [If N is 0, this leads to negative loop count; also, if N==0, the program still tries to read one integer below, causing undefined behavior. The handling of N<=0 is missing.]
    scanf("%d", &data); // @@ [If initial N is 0, this reads anyway, which is invalid. Also, the tree is allocated on the stack as a single Node, but if N==0, nothing should be done.]
    InitTree(T, data);
    while (N--) {
    scanf("%d", &data);
    AddNode(T, data);
    }
    Search(T, NodePrint, 1);
    return 0;
}