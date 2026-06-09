#include <stdlib.h>
#include <stdio.h>
typedef struct node{//树的结点
    int data;
    struct node* left;
    struct node* right;
    int h;
} Node,*Link;
 
typedef struct { //树根
    Node* root;
} Tree;
void insert(Tree* tree, int value)//创建树
{
    Link node=(Link)malloc(sizeof(Node));//创建一个节点
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    int dep=1;
    if (tree->root == NULL)//判断树是不是空树
    {
        tree->root = node;
        node->h=dep;
    }
    else {//不是空树
        Link temp = tree->root;//从树根开始
        while (temp != NULL)
        {
            if (value < temp->data)//小于就进左儿子
            {
                if (temp->left == NULL)
                {
                    temp->left = node;
                    node->h=dep+1;
                    return;
                }
                else {//继续判断
                    temp = temp->left;
                    dep++;
                }
            }
            else {//否则进右儿子
                if (temp->right == NULL)
                {
                    temp->right = node;
                    node->h=dep+1;
                    return;
                }
                else {//继续判断
                    temp= temp->right;
                    dep++;
                }
            }
        }
    }
    return;
}
void inorder(Node* node)//树的中序遍历
{
    if (node != NULL)
    {
        inorder(node->left);
        if(node->left==NULL&&node->right==NULL) printf("%d %d\n",node->data,node->h);
        inorder(node->right);
    }
}
int main()
{
    Tree tree;
    tree.root = NULL;//创建一个空树
    int n,num;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)//输入n个数并创建这个树
    {
        scanf("%d",&num);
        insert(&tree,num);
    }
    inorder(tree.root);//中序遍历
    return 0;
}

