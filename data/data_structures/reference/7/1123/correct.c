#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct BST
{
    int data;
    struct BST* left;
    struct BST* right;
};
struct BST* get(int data)
{
    struct BST* newNODE = (struct BST*)malloc(sizeof(struct BST));
    newNODE->data=data;
    newNODE->left=NULL;
    newNODE->right=NULL;
    return newNODE;
}

struct BST* insert(struct BST* root,int data)
{
    if(root==NULL)  root=get(data);
    else if(data< root->data) root->left=insert(root->left,data);
    else root->right=insert(root->right,data);
    return root;
}
int i=1;
void level(struct BST *root)
{


    if(root == NULL)
    {
        return;
    }
    else
    {
        if(root->left == NULL&&root->right == NULL)

        printf("%d %d\n", root->data,i);
        i++;
        level(root->left);
        level(root->right);
        i--;









    }
}
int main()
{
    struct BST* root=NULL;  //根节点指针，为bst类型
    int n,num;
    struct BST que[200];
    scanf("%d",&n);

    while(n--)
    {
        scanf("%d",&num);
        root=insert(root,num);

        //int r=(int*)root;
        //printf("%d\n",root);
    }
    level(root);
    return 0;
}

























