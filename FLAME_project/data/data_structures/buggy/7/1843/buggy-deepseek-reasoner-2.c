#include <stdio.h>
#include <stdlib.h>
typedef struct binode
{
    int data;
    int depth;
    struct binode *left;
    struct binode *right;
} binode;

binode *create_binode(int data, int depth)
{
    binode *p = (binode *)malloc(sizeof(binode));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    p->depth = depth;
    return p;
}
void insert(binode **root, int data, int depth)
{
    if (*root == NULL)
    {
        *root = create_binode(data, depth);
    }
    else if (data < (*root)->data)
    {
        depth++;
        insert(&((*root)->left), data, depth);
    }
    else if (data > (*root)->data) // @@ Missing handling for equal values; should go to right subtree (>= root)
    {
        depth++;
        insert(&((*root)->right), data, depth);
    }
}
void order(binode *root)
{
    if (root != NULL)
    {
        order(root->left);
        if (root->left == NULL && root->right == NULL)
        {
            printf("%d %d\n", root->data, root->depth);
        }
        order(root->right);
    }
}

int main()
{
    int num;
    scanf("%d", &num);
    binode *root = NULL;
    int depth = 1;
    for (int i = 0; i < num; i++)
    {
        int temp;
        scanf("%d", &temp);
        insert(&root, temp, depth);
    }
    order(root);
    return 0;
}