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
    scanf("%d",&a); // @@ The first integer 'a' is read as the count 'n', but it is not used to control the loop. The subsequent loop reads all remaining integers including potentially treating the count itself or missing the count logic depending on input format. More critically, the variable 'a' is reused for both count and values.
    while(scanf("%d",&a)!=EOF)  // @@ This loop reads until EOF. It should read exactly 'n' integers as specified by the first input. Also, the first scanf read the count, so this loop starts reading the actual numbers. However, if the input is "1\n5678", the first scanf reads 1. The while loop then reads 5678. This part is logically okay for reading values IF the first number was just discarded. But wait, the problem says "First, read an integer n... Then read n integers". The code reads 'a' (n), then enters a loop reading 'a' (values). This overwrites n. The loop condition `!=EOF` is dangerous if there's extra whitespace or newlines, but typically works for competitive programming inputs. The main issue is likely in the output or tree construction.
    Insert(&Root,a);
    preorder(Root,1);
    Destory_(Root);
    return 1;
}