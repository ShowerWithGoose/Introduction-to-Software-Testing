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
    tree->root=node;
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
    
} // @@ [The 'height' field of the root node is never initialized in the 'init' function. When inserting subsequent nodes, the height calculation assumes the root has height 1, but the root's 'height' member remains uninitialized, which may cause undefined behavior if accessed. However, the immediate error causing failure is that when n=0 or n=1, the program may not handle edge cases properly. But more critically, if n=0, the code still tries to access a[0], leading to undefined behavior. Also, for n=1, the root's height is never set, so during inorder traversal, printing node->height reads uninitialized memory.]

void inorder(Node* node)//树的中序遍历
{
    if (node != NULL)
    {
        inorder(node->left);
        if(node->left==NULL&&node->right==NULL)
        {
            printf("%d %d\n",node->data,node->height); // @@ [If the tree has only one node (the root), its 'height' was never assigned in 'init', so this prints an uninitialized value. The reference program sets node->h during insertion even for the root.]
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
    init(&tree,a[0]); // @@ [If n is 0, this accesses a[0] which is out of bounds (since no integers were read). Also, the root node's 'height' is never initialized to 1 here, unlike in the reference program.]
    for(i=1;i<n;i++)
    {
        insert(&tree,a[i]);
    }
    inorder(tree.root);
    return 0;
}