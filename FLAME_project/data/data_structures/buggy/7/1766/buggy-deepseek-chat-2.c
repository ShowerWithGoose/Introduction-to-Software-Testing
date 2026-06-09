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

int height=1; // @@ [Error: Using a global variable for height causes incorrect height tracking during recursion. When traversing left and right subtrees, the height modifications (increment/decrement) do not correctly reflect the depth of each node, leading to leaf heights being reported as 1 less than expected. The height should be passed as a parameter to the recursive function, as in the reference program.]

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
            printf("%d %d\n",t->data,height);
            return;
        }
        if(t->left!=NULL)    
        {
            height++; // @@ [Error: Incrementing global height here is incorrect because it does not properly track the depth for each recursive call. The height should be passed as a parameter to maintain correct depth values for leaf nodes.]
            preorder(t->left);
        }
        height--; // @@ [Error: Decrementing global height here is incorrect and disrupts the height tracking. This approach fails to correctly compute the height of leaf nodes, resulting in all leaf heights being off by 1.]
        if(t->right!=NULL)    
        {
            height++; // @@ [Error: Same issue as above; incrementing global height does not correctly represent the depth when traversing the right subtree.]
            preorder(t->right);
        }
        height--; // @@ [Error: Decrementing global height here further corrupts the height calculation, leading to incorrect output.]
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