#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define nodeptr struct Node*
#define node struct Node

struct Node
{
    struct Node *lchild;
    struct Node *rchild;
    int data;
}root;

nodeptr new();
nodeptr insert(int, nodeptr);
nodeptr SearchForLeaf(nodeptr, int);
int main()
{
    int n = 0;
    nodeptr rootptr = &root;
    #ifdef ACU
    freopen("in.txt","r", stdin);
    #endif
    scanf("%d", &n);//nonsense
    scanf("%d", &n),root.data = n;
    while (scanf("%d", &n) != EOF)
    {
        rootptr = insert(n, rootptr);
    }
    
    SearchForLeaf(rootptr, 1);
    return 0;
}

nodeptr new()
{
    nodeptr temp = (nodeptr)malloc(sizeof(node));
    memset(temp, 0, sizeof(node));
    return temp;
}

nodeptr insert(int n, nodeptr ptr)
{
    if (ptr == NULL)
    {
        ptr = new();
        ptr->data = n;
    }
    else if (ptr->data > n)
    {
        ptr->lchild = insert(n, ptr->lchild);
    }
    else if (ptr->data <= n)
    {
        ptr->rchild = insert(n, ptr->rchild);
    }
    return ptr;
}

nodeptr SearchForLeaf(nodeptr ptr, int n)
{
    if (ptr->lchild == NULL && ptr->rchild == NULL)
    {
        printf("%d %d \n", ptr->data, n);
    }
    else
    {
        if (ptr->lchild != NULL)
        {
            SearchForLeaf(ptr->lchild, n+1);
        }
        if (ptr->rchild != NULL)
        {
            SearchForLeaf(ptr->rchild, n+1);
        }
    }
}
