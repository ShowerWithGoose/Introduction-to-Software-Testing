#include <stdio.h>
#include <malloc.h>
struct Tree
{
    int num;
    struct Tree *left;
    struct Tree *right;
}first;

void insert(int n, struct Tree *t)
{
    if(n < t->num)
    {
        if(t->left==NULL)
        {
            t->left = (struct Tree*)malloc(sizeof(struct Tree));
            t->left->num = n;
            t->left->left = NULL;
            t->left->right = NULL;
        }
        else
            insert(n,t->left);
    }
    else
    {
        if(t->right==NULL)
        {
            t->right = (struct Tree*)malloc(sizeof(struct Tree));
            t->right->num = n;
            t->right->left = NULL;
            t->right->right = NULL;
        }
        else
            insert(n,t->right);
    }
}

void printTree(int n, struct Tree *t)
{
    if(t->left == NULL && t->right == NULL)
    {
        printf("%d %d\n",t->num,n);
    }
    else
    {
        if(t->left!=NULL)
            printTree(n+1, t->left);
        if(t->right!=NULL)
            printTree(n+1, t->right);
    }
}

void freetree(struct Tree *t)
{
    if(t->left == NULL && t->right == NULL && t != &first)
    {
        free(t);
    }
    else
    {
        if(t->left!=NULL)
            freetree(t->left);
        if(t->right!=NULL)
            freetree(t->right);
    }
}

int main()
{
    int all,n;
    first.num = 0;
    first.left = NULL;
    first.right = NULL;
    scanf("%d",&all);
    scanf("%d",&first.num);
    for(int i = 0; i < all - 1; i++)
    {
        scanf("%d",&n);
        insert(n, &first);
    }
    printTree(1,&first);
    //freetree(&first);
    return 0;
}



