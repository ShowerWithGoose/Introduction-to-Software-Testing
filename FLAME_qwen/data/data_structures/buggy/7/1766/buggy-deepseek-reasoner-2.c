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

int height=1; // @@ global height variable; using a global leads to incorrect tracking when children are missing

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

void  preorder(BTNodeptr t) //前序遍历  // @@ traversal order should be inorder (left-root-right) to ensure left-to-right leaf output
{
    if(t!=NULL)
    {
        if(t->left==NULL && t->right==NULL)
        {
            printf("%d %d\n",t->data,height); // @@ printed height may be incorrect due to flawed height management
            return;
        }
        if(t->left!=NULL)    
        {
            height++;
            preorder(t->left);
        }
        height--; // @@ unconditional decrement; when left child is missing, this incorrectly reduces height
        if(t->right!=NULL)    
        {
            height++;
            preorder(t->right);
        }
        height--; // @@ unconditional decrement; when right child is missing, this incorrectly reduces height
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