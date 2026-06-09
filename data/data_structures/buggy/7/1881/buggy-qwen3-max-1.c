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
            printf("%d %d\n ", node->data, num); // @@ [The output format has an extra space before the newline; also, the traversal order is incorrect for left-to-right leaf output—it should be a modified in-order or level-order, but more critically, the height calculation is wrong because `num` is incremented on both recursive calls without tracking actual depth correctly. However, the primary logic error is that the height passed to leaves is not the correct depth from root. Additionally, the problem requires left-to-right leaf order, which in-order does give, but the height is computed incorrectly due to passing `num+1` to both children before checking leaf condition. The leaf check happens after recursing, so `num` is already too deep.]
    }
}
int main()
{
    Tree tree;
    tree.root =NULL;
    int n,num;
    scanf("%d", &n);
    
    for (int i = 1; i < n; i++) // @@ [Loop runs from 1 to n-1, so only n-1 numbers are read instead of n. It should be `i = 0; i < n; i++` or `i = 1; i <= n; i++`. This causes one input value to be skipped.]
    {
        scanf("%d", &num);
        insert(&tree, num);
    }
    int count = 1;
    inorder(tree.root, count); // @@ [The initial call passes height=1, but inside `inorder`, the height is incremented before processing children, and the leaf check happens after recursion, leading to incorrect height values. The height of a leaf should be the depth from root (root=1), but due to post-recursion check and pre-incremented depth, the printed height is too large. Also, the traversal prints leaves in in-order (which is left-to-right), so that part is okay, but height is wrong.]
}