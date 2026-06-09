#include <stdio.h>
#include <stdlib.h>
#define elemtype int
#define maxn 1000
int a[maxn];

typedef struct node
{
    elemtype data;
    elemtype height;
    struct node *left,*right;
 }Node,*Nodeptr;
 
typedef struct { //树根
    Node* root;
} Tree;

void init(Tree* tree, int value)//创建树
{
    Node* node=(Node*)malloc(sizeof(Node));//创建一个节点
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    tree->root=node; // @@ Missing initialization of node->height = 1; The root's height should be 1 according to the problem (root height is 1). Without it, the root node's height field contains garbage, leading to incorrect output when the root is a leaf (e.g., n=1).
}

void insert(Tree* tree, int value)
{
    int h = 1;
    Node* node=(Node*)malloc(sizeof(Node));//创建一个节点
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    
    Node* temp=tree->root;
    while(1)
    {
        if(value < temp->data)
    {
        if(temp->left==NULL)
        {
            node->height = h+1;
            temp->left=node;
            return;
        }
        else
        {
            h++;
            temp=temp->left;
        }
        
    }
        else
        {
            if(temp->right==NULL)
        {
            node->height = h+1;
            temp->right=node;
            return;
        }
        else
        {
            h++;
            temp=temp->right;
        }
        }
    }
    
}

void inorder(Node* node)//树的中序遍历
{
    if (node != NULL)
    {
        inorder(node->left);
        if(node->left==NULL&&node->right==NULL)
        {
            printf("%d %d\n",node->data,node->height);
        }
        inorder(node->right);
    }
}
int main()
{
    Tree tree;
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    init(&tree,a[0]);
    for(i=1;i<n;i++)
    {
        insert(&tree,a[i]);
    }
    inorder(tree.root);
    return 0;
}