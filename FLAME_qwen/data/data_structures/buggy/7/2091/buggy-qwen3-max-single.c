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
    Search(N->left, Visit, height + 1);
  if (N->right)
    Search(N->right, Visit, height + 1);
  if (!N->left || !N->right)
    Visit(N, height);
    return OK;
} // @@ [The logic for identifying leaf nodes is wrong: it prints nodes that have at least one child missing (`!N->left || !N->right`), but leaf nodes must have both children NULL (`!N->left && !N->right`). Also, the traversal order is post-order, but the problem requires left-to-right (in-order) enumeration of leaves.]

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
    N--; // @@ [If N is 0, this underflows and leads to reading negative number of inputs. Also, if N==0, the program should exit without doing anything, but here it proceeds incorrectly.]
    scanf("%d", &data);
    InitTree(T, data);
    while (N--) {
    scanf("%d", &data);
    AddNode(T, data);
    }
    Search(T, NodePrint, 1);
    return 0;
}