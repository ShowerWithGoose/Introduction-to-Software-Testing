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
        *T = (tree)malloc(sizeof(struct node)); // @@ [Error: malloc(sizeof(tree)) allocates memory for a pointer (4 or 8 bytes), not the struct node. It should be sizeof(struct node) or sizeof(**T). This causes memory corruption and undefined behavior.]
        (*T)->left = NULL;
        (*T)->right = NULL;
        (*T)->data = dat;
        (*T)->depth = dep; 
    }
    else if((*T)->data < dat) // @@ [Error: The problem states left child < root, right child >= root. This condition sends values equal to root to the left (else branch), but they should go to the right. It should be (*T)->data <= dat for right, or strictly (*T)->data > dat for left. Correct logic: if dat >= (*T)->data go right, else go left. Here, if dat == (*T)->data, it goes to else (left), which is wrong.]
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