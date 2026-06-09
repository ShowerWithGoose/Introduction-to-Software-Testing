#include<stdio.h>
#include<stdlib.h> 
typedef struct node{
    int data;
    struct node* lchild;
    struct node* rchild;
}Node,*PNode;
void Insert(struct node** root,int item)
{
    if(*root==NULL)
    {
        *root=(PNode)malloc(sizeof(Node));
        (*root)->data=item;
        (*root)->lchild=(*root)->rchild=NULL;
        return ;
    }
    else
    {
        if(item>=(*root)->data)
        Insert(&((*root)->rchild),item);
        else
        Insert(&((*root)->lchild),item);
    }
}
//int Search(struct node* root,int item,int Level)
//{
//     if(root===NULL)
//     return -1;
//     
//}
void preorder(struct node* root,int level)//从root进入前序遍历，当前root在level层（level从1开始
{
    if(root!=NULL)
    if(root->lchild!=NULL||root->rchild!=NULL)
    {
        preorder(root->lchild,1+level);
        preorder(root->rchild,1+level);
    }
    else
    printf("%d %d\n",root->data,level);
    else
    return ;
} 
void Destory_(struct node* root)
{
    if(root!=NULL)
    {
        Destory_(root->lchild);
        Destory_(root->rchild);
        free(root);
        root=NULL;
    }
}
int main()
{
    int a;
    PNode Root=NULL;
    scanf("%d",&a); // @@ Error: This reads the first integer (n=1) into variable 'a', but then the while loop reads the remaining integers. For a single integer input, the first scanf consumes the '1', and the while loop reads '5678', but the tree is built from '5678' only, missing the fact that '1' was the count, not a tree value. The correct behavior is to read n first, then read n integers into the BST.
    while(scanf("%d",&a)!=EOF) // @@ Error: This loop reads all remaining integers, but for the test case "1\n5678", after reading n=1, it reads 5678 correctly. However, the problem expects to read n first, then read exactly n integers. The program should read n, then loop n times to insert values.
    Insert(&Root,a);
    preorder(Root,1);
    Destory_(Root);
    return 1;
}