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
            printf("%d %d\n ", node->data, num); // @@ printf格式中\n后面多了一个空格，应为"%d %d\n"
    }
}
int main()
{
    Tree tree;
    tree.root =NULL;
    int n,num;
    scanf("%d", &n);
    
    for (int i = 1; i < n; i++) // @@ 循环应该从i=0开始，以读取所有n个整数
    {
        scanf("%d", &num);
        insert(&tree, num);
    }
    int count = 1;
    inorder(tree.root, count);
}