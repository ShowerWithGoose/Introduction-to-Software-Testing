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

int height=1; // @@ [使用全局变量追踪高度，递归过程中手动增减容易出错，应改为递归参数传递]

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
            printf("%d %d\n",t->data,height); // @@ [打印的是全局height，但该值因错误的增减逻辑而不等于当前节点实际高度]
            return;
        }
        if(t->left!=NULL)    
        {
            height++; // @@ [无左子树时不应进行此增减，全局变量方式导致高度偏差]
            preorder(t->left);
        }
        height--; // @@ [无论左子树是否存在都执行减一，破坏高度计数]
        if(t->right!=NULL)    
        {
            height++; // @@ [同上，错误的增减逻辑]
            preorder(t->right);
        }
        height--; // @@ [同上，导致最终高度错误]
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