#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

struct node{
    int data;
    struct node *left,*right;
};
typedef struct node BTNode;
typedef struct node *BTNodeptr;

int height=1; // @@ [Using a global variable 'height' to track node height is incorrect because it doesn't represent the actual height of each node in the tree; height should be computed per node during traversal or stored in the node structure.]

BTNodeptr insert(BTNodeptr root,int insert_data) //数据插入
{
    if(root==NULL) 
    { 
        root=(BTNodeptr)malloc(sizeof(BTNode));
        root->data=insert_data;
        root->left=root->right=NULL;
        return root;
    } 
    else 
    {
        if(insert_data<root->data) 
            root->left=insert(root->left,insert_data);
        else
            root->right=insert(root->right,insert_data);
        return root;  
    }      
}

void  preorder(BTNodeptr t) //前序遍历 
{
    if(t!=NULL)
    {
        if(t->left==NULL && t->right==NULL)
        {
            printf("%d %d\n",t->data,height); // @@ [Printing the global 'height' instead of the actual height of the current leaf node. The global height variable is modified during traversal and does not reflect the true depth of the current node.]
            return; // @@ [Returning immediately after printing a leaf prevents traversal of the right subtree if the left child was NULL but right exists; however, in this specific condition (both children NULL), it's a leaf, so return is okay, but the main issue is the incorrect height.]
        }
        if(t->left!=NULL)    
        {
            height++;
            preorder(t->left);
        }
        height--; // @@ [Decrementing height after left traversal assumes that height was incremented exactly once, but if both left and right exist, the height may be incorrectly managed due to shared global state.]
        if(t->right!=NULL)    
        {
            height++;
            preorder(t->right);
        }
        height--; // @@ [Same issue: global height manipulation leads to incorrect height values for nodes, especially when backtracking from right subtrees.]
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    BTNodeptr root=NULL;
    int i,num;
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        root=insert(root,num);
    }
    preorder(root);
    return 0; 
}