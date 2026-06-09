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
    return ERROR; // @@ [This return ERROR is unreachable in some paths and causes incorrect return value handling; also, recursive calls do not return their result, leading to undefined behavior]
}

Status Search(Node *N, Status *Visit(Node *, int), int height) {
  if (N->left)
    Search(N->left, Visit, height + 1);
  if (N->right)
    Search(N->right, Visit, height + 1);
  if (!N->left || !N->right)
    Visit(N, height); // @@ [Logic error: condition `!N->left || !N->right` identifies nodes with at least one missing child, not leaf nodes. Leaf nodes must have both children NULL. Also, the function signature uses `Status *Visit(...)` which is invalid syntax for a function pointer parameter.]
    return OK;
}

Status *NodePrint(Node *N, int height) // @@ [Return type should be `Status`, not `Status *`; mismatch with function pointer expected by Search()]
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
    N--; // @@ [If input N is 0, this leads to negative loop count; also, using stack-allocated root node may cause issues if tree is large, but more critically, if N==0, the program still tries to read data]
    scanf("%d", &data);
    InitTree(T, data);
    while (N--) {
    scanf("%d", &data);
    AddNode(T, data);
    }
    Search(T, NodePrint, 1); // @@ [Function pointer syntax is incorrect; also, logic in Search does not correctly identify leaf nodes]
    return 0;
}