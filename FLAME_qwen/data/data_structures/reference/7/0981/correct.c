#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
typedef struct node
{
    int data;
    int depth;
    struct node *lchild, *rchild;
} BiTree;
BiTree *first;
BiTree *Insert(BiTree *root,int temp,int len);
void PreOrderTraverse(BiTree *root);//µ›πÈ∞Êœ»–Ú±È¿˙
int main()
{
    BiTree *root=NULL;
    int n,temp;
    scanf("%d",&n);
    for (int i=0;i<n;i++) //¥¥Ω® ˜
    {
        scanf("%d",&temp);
        int len=0;
        root=Insert(root,temp,len);
    }
    PreOrderTraverse(root);
    return 0;
}
BiTree *Insert(BiTree *root,int temp,int len)
{
    len++;
    if (root==NULL)
    {
        root=(BiTree *)malloc(sizeof(BiTree));
        root->data=temp;
        root->lchild=root->rchild=NULL;
        first=root;
        root->depth=len;
    }
    else if(temp<root->data)
        root->lchild=Insert(root->lchild,temp,len);
    else if(temp>=root->data)
        root->rchild=Insert(root->rchild,temp,len);
    return root;
}
void PreOrderTraverse(BiTree *root)//µ›πÈ∞Êœ»–Ú±È¿˙ 
{
    if(root)
	{
        if(!root->lchild&&!root->rchild) 
			printf("%d %d\n",root->data,root->depth);
        PreOrderTraverse(root->lchild);
        PreOrderTraverse(root->rchild);
    }   
}

