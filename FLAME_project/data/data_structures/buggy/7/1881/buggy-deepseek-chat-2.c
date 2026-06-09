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
            printf("%d %d\n ", node->data, num); // @@ The height of the root should be 1, but here the initial call passes count=1, and then increments by 1 for each level. However, the logic is flawed: the height should be passed correctly from parent to child. Additionally, the printf has a space after \n which may cause formatting issues. The main issue is that the height calculation is incorrect because the function does not properly track the height from the root; it increments num for both left and right children but the initial value should be 1 for the root, and the recursion should pass the current height + 1 to children. The current code passes num+1 to both children, which is correct in concept, but the initial call with count=1 is correct. However, the error is that the program fails to read the first integer when n=1 because the loop starts from i=1 instead of i=0, so it never reads the single input value, resulting in no output.
    }
}
int main()
{
    Tree tree;
    tree.root =NULL;
    int n,num;
    scanf("%d", &n);
    
    for (int i = 1; i < n; i++) // @@ The loop should start from i=0 to read all n integers. Starting from i=1 skips the first integer, so when n=1, the loop runs 0 times and no value is inserted, causing the tree to be empty and no output.
    {
        scanf("%d", &num);
        insert(&tree, num);
    }
    int count = 1;
    inorder(tree.root, count);
}