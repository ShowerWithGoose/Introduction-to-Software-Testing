#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left,*right;
};
typedef struct node BTNode;
typedef struct node *BTNodeptr;

struct Tree
{
    struct Tree *root;
};
typedef struct Tree Tnode;
typedef struct Tree *Tnodeptr;
void insert(Tnode *tree,int value)
{
    BTNodeptr p;
    p = (BTNodeptr)malloc(sizeof(BTNode));
    p->data = value;
    p->left = NULL;
    p->right = NULL;
    if(tree->root == NULL)
        tree->root = p;
    else
    {
        BTNodeptr temp;
        temp = tree->root;
        while(temp!=NULL)
        {
            if(value<temp->data)
            {
                if(temp->left == NULL)
                {
                    temp->left = p;
                    return;
                }
                else
                    temp = temp->left;
            }
            else
            {
                if(temp->right == NULL)
                {
                    temp->right = p;
                    return;
                }
                else
                    temp = temp->right;
            }
        }
    }
}

void tprintf(BTNodeptr q,int depth)
{
    if(q != NULL)
    {
        tprintf(q->left,depth+1);
        tprintf(q->right,depth+1);
        if(q->left == NULL && q->right == NULL)
            printf("%d %d\n",q->data,depth);
    }
}

int num,n,i,j,k;
int main()
{
    Tnode tree;
    tree.root = NULL;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&num);
        insert(&tree,num);
    }
    tprintf(tree.root,1);
    return 0;
}

