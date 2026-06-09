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
            printf("%d %d\n ", node->data, num); // @@ [The space after \n is incorrect and the order of traversal is wrong; should be left-to-right leaf order which requires in-order traversal to print before recursing right, but here it prints after both recursions, making it post-order. Also, height starts at 1 for root, but passed as 1 from main, yet incremented before checking children, leading to off-by-one if not handled correctly. However, primary issue is traversal order: printing after both recursive calls makes it post-order, not in-order. For left-to-right leaves, in-order is correct, but print must happen between left and right recursion.]
    }
}
int main()
{
    Tree tree;
    tree.root =NULL;
    int n,num;
    scanf("%d", &n);
    
    for (int i = 1; i < n; i++) // @@ [Loop starts at i=1, so only reads n-1 numbers instead of n. Should be i = 0; i < n; i++.]
    {
        scanf("%d", &num);
        insert(&tree, num);
    }
    int count = 1;
    inorder(tree.root, count); // @@ [Passes initial height as 1, which is correct per problem (root height = 1), but due to incorrect traversal order and extra space in output, results are wrong.]
}