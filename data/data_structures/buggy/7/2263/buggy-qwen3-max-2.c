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
                node->deepth++; // @@ [The depth is being incremented incorrectly during traversal. The depth should be determined by the path length from root, not by incrementing as we traverse. This leads to wrong height values.]
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
                node->deepth++; // @@ [Same issue: depth is incremented multiple times possibly (once per level traversed), but it's initialized to 1 and then incremented for each step, which actually gives correct depth if done once per level. However, note that both 'if' blocks can't execute, so this may be okay logically, but the bigger issue is in inorder()]
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
        if (node->left == NULL && node->left == NULL) // @@ [Typo: should be 'node->right == NULL'. As written, it checks left twice, so non-leaf nodes with no left child but a right child would be incorrectly treated as leaves.]
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
    system("pause"); // @@ [This line may cause issues on systems without 'pause' command (like Unix-like systems), leading to runtime errors or unexpected behavior. However, the reported error is compilation error due to missing gcc, which is environment-related. But within code logic, this is non-portable and unnecessary. However, the primary logical bugs are above.]
    return 0;
}
/*
13
50 38 30 64 58 40 10 73 70 50 60 100 35
*/