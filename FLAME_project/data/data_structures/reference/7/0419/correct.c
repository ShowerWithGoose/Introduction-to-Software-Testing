
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

#define MAX_SIZE 10
/*数据：
13
50 38 30 64 58 40 10 73 70 50 60 100 35*/
typedef int TreeDatatype;   //每个文件的数据类型最好定义不一样，这样以后可以分别同时使用

//普通二叉树一般不储存数据，因此不做增删查改（没有意义km），一般用来搜索用的
struct BinaryTreeNode  //定义一个二叉树，只有左右两个孩子（二叉链）
{
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
    TreeDatatype data;
    int depth;
};

int arr[200];
int Init(int* arr);
struct BinaryTreeNode* CreatTree(struct BinaryTreeNode*root,int item,int* depth);
void PrevOrder(struct BinaryTreeNode* root);  //前序：根->左子树->右子树
int main()
{
    int len=Init(arr);
    //for(int i=0;i<len;i++)printf("%d ",arr[i]);printf("\n");
    struct BinaryTreeNode* root =NULL;
    int depth=1;
    for(int i=0;i<len;i++)
    {
        depth=1;
        root=CreatTree(root,arr[i],&depth);
    }
    PrevOrder(root);
    return 0;
}
int Init(int* arr)
{
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    return n;
}
struct BinaryTreeNode* CreatTree(struct BinaryTreeNode*root,int item,int* depth)
{

        if(root==NULL)
        {

            root=(struct BinaryTreeNode*)malloc(sizeof(struct BinaryTreeNode));
            root->data=item;
            root->left=NULL;
            root->right=NULL;
            root->depth=*depth;

        }
        else if(item<root->data)
        {
            (*depth)++;
            root->left=CreatTree(root->left,item,depth);
        }
        else if(item>=root->data)
        {
            (*depth)++;
            root->right=CreatTree(root->right,item,depth);
        }
        return root;

};
void PrevOrder(struct BinaryTreeNode* root)  //前序：根->左子树->右子树
{
    if(root==NULL)
        return;
    if(root->left==NULL&&root->right==NULL)
    {
        printf("%d %d\n",root->data,root->depth);
    }
    PrevOrder(root->left);  //递归实现
    PrevOrder(root->right);

}

