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
        *T = (tree)malloc(sizeof(tree)); // @@ [Error: sizeof(tree) allocates pointer size, should be sizeof(struct node) to allocate the node structure]
        (*T)->left = NULL;
        (*T)->right = NULL;
        (*T)->data = dat;
        (*T)->depth = dep; 
    }
    else if((*T)->data < dat) // @@ [Error: condition should be <= to place equal values in the right subtree as per problem specification (right child >= root)]
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