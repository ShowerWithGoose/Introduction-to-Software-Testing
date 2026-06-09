#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *PtrTreeNode;
typedef PtrTreeNode Tree;

struct TreeNode
{
    int num;
    Tree left;
    Tree right;
};
Tree temp, root, q, p;

void addNode(int n);
void traverse(Tree ptr, int depth);
int main(void)
{
    int n;
    int num;
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &num);
        addNode(num);
    }
    traverse(root, 1);
    return 0;
}

void addNode(int n)
{
    p = (Tree)malloc(sizeof(struct TreeNode));
    p->num = n;
    p->left = p->right = NULL;
    if (root == NULL)
    {
        root = p;
    }
    else
    {
        temp = root;
        while (temp != NULL)
        {
            if (n < temp->num)
            {
                if (temp->left == NULL)
                {
                    temp->left = p;
                    return;
                }
                temp = temp->left;
            }
            if (n >= temp->num)
            {
                if (temp->right == NULL)
                {
                    temp->right = p;
                    return;
                }
                temp = temp->right;
            }
        }
    }
}
void traverse(Tree ptr, int depth)
{
    if (ptr->left == NULL && ptr->right == NULL)
    {
        printf("%d %d\n", ptr->num, depth);
    }
    if (ptr->left)
    {
        traverse(ptr->left, depth + 1);
    }
    if (ptr->right)
    {
        traverse(ptr->right, depth + 1);
    }
}


