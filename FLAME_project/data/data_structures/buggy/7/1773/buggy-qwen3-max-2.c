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
        *T = (tree)malloc(sizeof(tree)); // @@ [Incorrect memory allocation: sizeof(tree) is the size of a pointer, not the struct. Should be sizeof(struct node).]
        (*T)->left = NULL;
        (*T)->right = NULL;
        (*T)->data = dat;
        (*T)->depth = dep; 
    }
    else if((*T)->data < dat)
    {
        dep++;
        create(&((*T)->right), dep , dat);
    }
    else
    {
        dep++;
        create(&((*T)->left), dep , dat); // @@ [The BST insertion logic is reversed: values less than the current node should go to the left, but the condition above uses < for right, so equal values go left incorrectly. According to problem, right child should be >= root, so left should be <, which is correct, BUT the recursive call passes incremented dep before recursion, causing depth to be over-incremented across siblings.]
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