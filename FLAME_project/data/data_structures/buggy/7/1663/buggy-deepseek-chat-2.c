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
    scanf("%d",&a); // @@ [Error: This reads the first integer n (1) as a tree node value, but it should be ignored as the count of integers. The subsequent loop then reads the actual data (5678) but misses the first value because it was already consumed.]
    while(scanf("%d",&a)!=EOF) 
    Insert(&Root,a);
    preorder(Root,1);
    Destory_(Root);
    return 1;
}