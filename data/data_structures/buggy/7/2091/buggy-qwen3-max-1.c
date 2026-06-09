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
    return ERROR; // @@ [This function does not return a value in all paths when recursive calls are made; the recursive calls' return values are ignored, leading to undefined behavior and possibly returning ERROR incorrectly.]
}

Status Search(Node *N, Status *Visit(Node *, int), int height) { // @@ [The function signature is incorrect: 'Status *Visit(...)' should be 'Status (*Visit)(Node *, int)' to declare a function pointer. This causes a compilation error.]
  if (N->left)
    Search(N->left, Visit, height + 1);
  if (N->right)
    Search(N->right, Visit, height + 1);
  if (!N->left || !N->right)
    Visit(N, height); // @@ [This condition prints nodes that are not necessarily leaves. A leaf must have both left and right as NULL, but this condition triggers if either is NULL. Also, due to the earlier function pointer syntax error, this line won't compile.]
    return OK;
}

Status *NodePrint(Node *N, int height) // @@ [Return type should be 'Status', not 'Status *', to match the expected function pointer type in Search(). Returning NULL here is also inconsistent with Status being an int.]
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
    N--; // @@ [If N is 0, this leads to negative loop count; also, if N==0, the program still tries to read one integer below, which is wrong. The logic for handling N<=0 is missing.]
    scanf("%d", &data);
    InitTree(T, data);
    while (N--) {
    scanf("%d", &data);
    AddNode(T, data);
    }
    Search(T, NodePrint, 1);
    return 0;
}