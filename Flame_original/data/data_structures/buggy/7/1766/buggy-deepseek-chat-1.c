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

int height=1; // @@ [Error: Using a global variable for height is incorrect because it does not properly track the height of each node during recursion. The height should be passed as a parameter or computed recursively, as in the reference program. This leads to incorrect height values for leaf nodes.]

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
            printf("%d %d\n",t->data,height); // @@ [Error: Using global variable 'height' here is incorrect because it does not reflect the actual height of the current node. The height should be tracked per node, not globally.]
            return;
        }
        if(t->left!=NULL)    
        {
            height++; // @@ [Error: Modifying global variable 'height' is error-prone and does not correctly compute the height for each node. The height should be passed as a parameter to the recursive function.]
            preorder(t->left);
        }
        height--; // @@ [Error: Decrementing global variable 'height' is incorrect and can cause mismatched height values.]
        if(t->right!=NULL)    
        {
            height++; // @@ [Error: Same issue as above; global variable manipulation leads to incorrect height tracking.]
            preorder(t->right);
        }
        height--; // @@ [Error: Same issue as above.]
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