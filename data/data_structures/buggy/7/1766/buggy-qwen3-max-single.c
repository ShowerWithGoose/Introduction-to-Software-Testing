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

int height=1; // @@ [Using a global variable 'height' to track node height during traversal is incorrect because it doesn't represent the actual height of each node in the tree; height should be stored per node or computed correctly during traversal.]

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
            printf("%d %d\n",t->data,height); // @@ [Printing the global 'height' instead of the actual height of the current leaf node. The global height is modified during traversal and does not reflect the true depth of the node.]
            return; // @@ [Returning immediately after printing a leaf prevents traversal of right subtrees that may also contain leaves, breaking the left-to-right order requirement.]
        }
        if(t->left!=NULL)    
        {
            height++;
            preorder(t->left);
        }
        height--;
        if(t->right!=NULL)    
        {
            height++;
            preorder(t->right);
        }
        height--;
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