#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int elem;
    int deep;
    struct node *left;
    struct node *right;
};
typedef struct node Node;
typedef struct node *NodePtr;
NodePtr CreateTree(int a, int b);
NodePtr Addtree(NodePtr a, int b);
void put(NodePtr a);
int is_leaf(NodePtr a);
Node tree;
NodePtr treeptr;
int depth;
int main()
{
    int n;
    int i;
    scanf("%d", &n);
    int num;
    scanf("%d",&num);
    treeptr=CreateTree(num,1);
    for (i = 1; i < n; i++)
    {
        scanf("%d",&num);
        depth=0;
        Addtree(treeptr,num);
    }
    put(treeptr);
    return 0;
}
NodePtr CreateTree(int a, int b)
{
    NodePtr temp = (NodePtr)malloc(sizeof(Node));
    temp->elem = a;
    temp->deep = b;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
NodePtr Addtree(NodePtr a, int b)
{
    depth++;
    if (a == NULL)
        a = CreateTree(b, depth);
    else if (b < a->elem)
        a->left = Addtree(a->left, b);
    else if (b >= a->elem)
        a->right = Addtree(a->right, b);
    return a;
}
int is_leaf(NodePtr a)
{
    if (a->left == NULL && a->right == NULL)
        return 1;
    else
        return 0;
}
void put(NodePtr a)
{
    if(a->left!=NULL)
    {
        put(a->left);
    }
    if(is_leaf(a))
    {
        printf("%d %d\n",a->elem,a->deep);
    }
    if(a->right!=NULL)
    {
        put(a->right);
    }
}
