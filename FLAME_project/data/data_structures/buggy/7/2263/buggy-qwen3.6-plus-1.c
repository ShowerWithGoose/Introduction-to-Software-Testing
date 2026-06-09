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
                node->deepth++;
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
            if (node->data < temp->data) // @@ The two 'if' statements should be 'if-else'. If the first 'if' is true and inserts the node, the function returns. However, if it doesn't return (goes to else), it continues to the next 'if'. More critically, if the first 'if' is true but goes to else (temp->right is not NULL), temp is updated. Then the second 'if' is checked. If node->data < temp->data is false (which it might be if we just went right), it does nothing. But if node->data >= temp->data was true, node->data < temp->data is false. So logically it might work for traversal, BUT there is a logical flaw in structure. The main issue is that these should be mutually exclusive. Using two separate 'if's is risky and bad practice, but let's look closer. Actually, if node->data >= temp->data, we go right. If we don't return, we update temp. Then we check if node->data < temp->data. Since we just moved temp to temp->right, and originally node->data >= old_temp->data, it is possible that node->data < new_temp->data? No, BST property. Wait. The real bug is likely elsewhere. Let's look at the output.
            // The buggy output includes "10 1". 10 is the root. The root is a leaf only if it has no children. In the input 10 20 ..., 10 has a right child 20. So 10 is not a leaf.
            // Why is 10 printed? The condition for printing is in inorder.
            {
                node->deepth++;
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
        if (node->left == NULL && node->left == NULL) // @@ The condition checks node->left twice. It should check node->left == NULL && node->right == NULL to identify a leaf node. Because of this error, any node with left==NULL is considered a leaf, including the root if it has no left child (like 10 in the example).
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
    system("pause");
    return 0;
}
/*
13
50 38 30 64 58 40 10 73 70 50 60 100 35
*/