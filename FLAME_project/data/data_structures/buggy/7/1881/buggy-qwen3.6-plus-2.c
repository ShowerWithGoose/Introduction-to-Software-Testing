#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct node { //树的结点
    int data;
    struct node* left;
    struct node* right;
} Node;
typedef struct { //树根
    Node* root;
} Tree;
void insert(Tree* tree, int value)//创建树
{
    Node* node = (Node*)malloc(sizeof(Node));//创建一个节点
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    if (tree->root == NULL)//判断树是不是空树
    {
        tree->root = node;
    }
    else {//不是空树
        Node* temp = tree->root;//从树根开始
        while (temp != NULL)
        {
            if (value < temp->data)//小于就进左儿子
            {
                if (temp->left == NULL)
                {
                    temp->left = node;
                    return;
                }
                else {//继续判断
                    temp = temp->left;
                }
            }
            else {//否则进右儿子

                if (temp->right == NULL)
                {
                    temp->right = node;
                    return;
                }
                else {//继续判断
                    temp = temp->right;
                }
            }
        }
    }
    return;
}
void inorder(Node* node,int num)//树的中序遍历
{
    if (node != NULL)
    {
        inorder(node->left,num+1);
        
        inorder(node->right,num+1);
        if (node->left == NULL && node->right == NULL)
            printf("%d %d\n ", node->data, num); // @@ [Output format error: there is an extra space after \n, which may cause presentation error or wrong answer depending on strictness. Also, the traversal order is Pre-order (process, left, right) effectively because the print is after left recursion but before right? No, wait. The code structure is: recurse left, recurse right, THEN print. This is Post-order. But the problem asks for Left-to-Right output of leaves. In-order traversal visits nodes in sorted order for BST. However, simply visiting leaves in In-order (Left, Process, Right) ensures left-to-right spatial order. The current code does Left, Right, Process. This is Post-order. While post-order might visit leaves in a similar order for some trees, In-order is the standard for "left to right" in BST context. More critically, the loop in main is wrong.]
    }
}
int main()
{
    Tree tree;
    tree.root =NULL;
    int n,num;
    scanf("%d", &n);
    
    for (int i = 1; i < n; i++) // @@ [Loop starts from 1 and goes to n-1, so it only reads n-1 integers. It should start from 0 and go to n-1 (i < n) or 1 to n (i <= n) to read all n integers.]
    {
        scanf("%d", &num);
        insert(&tree, num);
    }
    int count = 1;
    inorder(tree.root, count);
}