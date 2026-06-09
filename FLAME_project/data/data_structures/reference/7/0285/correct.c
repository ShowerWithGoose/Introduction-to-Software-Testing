#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int val;
    struct Node *left, *right;
}Node;

Node* root;


Node* create_BST(Node* node, int num)
{
    if(node == NULL)
    {
        Node* tmp = (Node*)malloc(sizeof(Node));
        tmp->val = num;
        tmp->left = tmp->right = NULL;
        return tmp;
    }

    if(node->val <= num)   //右子树的方向
    {
        node->right = create_BST(node->right, num);
    }
    else   //左子树的方向
    {
        node->left = create_BST(node->left, num);
    }

    return node;
}


void dfs(Node* node, int height)
{
    if(node->left == NULL && node->right == NULL)
    {
        printf("%d %d\n", node->val, height);
        return;
    }

    if(node->left != NULL)
    {
        dfs(node->left, height + 1);
    }
    if(node->right != NULL)
    {
        dfs(node->right, height + 1);
    }
}


int main()
{
    root = NULL;
    int front = 0, rear = 0;
    Node* queue[500];

    int n, num[500];
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }

    for(int i = 0; i < n; i++)
    {
        root = create_BST(root, num[i]);  //递归创建BST，不要担心时间复杂度
    }
    
    //深度优先搜索，从左到右找到叶子结点
    dfs(root, 1);

    return 0;
}
