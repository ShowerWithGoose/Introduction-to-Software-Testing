#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    int deepth;
    struct node *left;
    struct node *right;
} Node;

typedef struct tree
{
    Node *root;
} Tree;

void VISIT(Node *t)// 访问结点 
{
    printf("%d %d\n",t->data,t->deepth);
}

void create_tree(Tree *tree, int number, int dep)
{
    Node *node = (Node *)malloc(sizeof(Node)); // 定于一个节点，将数放到节点000000 0 00 中
    node->data = number;
    node->deepth = dep;
    node->left = NULL;
    node->right = NULL;
    if (tree->root == NULL)
    {
        tree->root = node; // 如果根为空，就将这个节点放到根节点
    }
    else
    {
        Node *temp = tree->root; // 定义指针指向根节点
        while (temp != NULL)
        {
            if (node->data >= temp->data)
            {
                node->deepth++; // @@ [The depth is being incremented inside the loop, but it should be based on the path length from root. This leads to incorrect depth calculation because it increments multiple times per insertion depending on traversal steps.]
                if (temp->right == NULL)
                {

                    temp->right = node;
                    return;
                }
                else
                {
                    temp = temp->right;
                }
            }
            if (node->data < temp->data)
            {
                node->deepth++; // @@ [Same issue: depth is incremented per comparison step rather than reflecting actual tree level. Should not modify node->deepth here.]
                if (temp->left == NULL)
                {
                    temp->left = node;
                    return;
                }
                else
                {
                    temp = temp->left;
                }
            }
        }
    }
}

void inorder(Node *node)
{
    if (node != NULL)
    {
        inorder(node->left);
        if (node->left == NULL && node->left == NULL) // @@ [Typo: should be 'node->right == NULL' instead of repeating 'node->left == NULL'. This causes non-leaf nodes with only a right child to be incorrectly treated as leaves.]
        VISIT(node);
            
        inorder(node->right);
    }
}

int main()
{
    int a[200] = {0};
    Tree tree;
    tree.root = NULL;
    int i = 0, n;
    int num;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {

        scanf("%d", &num);
        a[i] = num;
    }
    for (i = 0; i < n; i++)
    {
        create_tree(&tree, a[i], 1);
    }
    inorder(tree.root);
    system("pause"); // @@ [Non-standard function call that may cause compilation or runtime issues on some systems, though not directly related to logic errors in BST or output. However, the problem expects only leaf values and heights; this line is unnecessary and may interfere in restricted environments.]
    return 0;
}
/*
13
50 38 30 64 58 40 10 73 70 50 60 100 35
*/