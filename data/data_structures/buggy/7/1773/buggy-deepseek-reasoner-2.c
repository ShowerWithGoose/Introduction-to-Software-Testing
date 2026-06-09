#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct node{
    int data;
    int depth;
    struct node *left,*right;
}*tree;
int dat,dep = 1;
tree root = NULL;
int n;
void inorder(tree T)
{
    if(T != NULL)
    {
        inorder(T->left);
        if(T->left == NULL && T->right == NULL)
            printf("%d %d\n",T->data,T->depth);
        inorder(T->right);
    }
}
void create(tree *T,int dep,int dat)
{
    if(*T == NULL)
    {
        *T = (tree)malloc(sizeof(tree)); // @@ error: malloc allocates size of pointer, not size of struct node; should be sizeof(struct node)
        (*T)->left = NULL;
        (*T)->right = NULL;
        (*T)->data = dat;
        (*T)->depth = dep; 
    }
    else if((*T)->data < dat) // @@ error: condition should be dat < (*T)->data to ensure left subtree contains values less than root and right subtree contains values greater than or equal to root
    {
        dep++;
        create(&((*T)->right), dep , dat);
    }
    else
    {
        dep++;
        create(&((*T)->left), dep , dat);
    }
}
int main()
{
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &dat);
        create(&root,1,dat);
    }
    inorder(root);
    return 0;
}