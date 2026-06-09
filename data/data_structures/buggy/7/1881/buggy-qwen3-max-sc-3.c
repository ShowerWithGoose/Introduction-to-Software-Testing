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
            printf("%d %d\n ", node->data, num); // @@ [The output format has an extra space before the newline; also, the traversal order is incorrect for left-to-right leaf output—it should be pre-order or modified in-order to ensure left-to-right leaf order, but more critically, the height is passed incorrectly due to post-order style processing. However, the main logic error is that the height is incremented on the way down but printed after recursive calls, so 'num' represents depth from root correctly, but the bigger issue is the loop in main.]
    }
}
int main()
{
    Tree tree;
    tree.root =NULL;
    int n,num;
    scanf("%d", &n);
    
    for (int i = 1; i < n; i++) // @@ [Loop starts at i=1 and runs while i < n, so it reads only n-1 numbers instead of n. It should be i = 0; i < n or i = 1; i <= n. This causes one input value to be skipped, leading to incomplete tree construction.]
    {
        scanf("%d", &num);
        insert(&tree, num);
    }
    int count = 1;
    inorder(tree.root, count); // @@ [The traversal function 'inorder' processes children before printing the current node (due to recursive calls before the print condition), which means it's effectively a post-order traversal regarding the print statement. However, for left-to-right leaf output, a standard in-order traversal would work if the print were in the middle. But here, because the print happens after both recursions, it prints leaves from left to right? Actually, no: the left subtree is fully traversed (including printing its leaves), then the right, so leaf order is correct. However, the height 'num' is passed as depth+1 on each call, but since the print occurs after recursion, the 'num' value at print time is actually the depth of the leaf (since it was incremented on the way down). BUT: the initial call uses count=1, and each recursive call uses num+1, so depth is correctly tracked. However, the real critical bug is the loop reading n-1 values. Also, the output has a trailing space: " %d\n " should be " %d\n" without trailing space. But the problem says output format is "value height" separated by space and then newline—trailing space may cause presentation error. However, the primary functional error is the loop.]
}