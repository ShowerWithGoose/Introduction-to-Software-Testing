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
void insert(Tnode *root,int value)
{
    BTNodeptr p;
    p = (BTNodeptr)malloc(sizeof(BTNode));
    p->data = value;
    p->left = NULL;
    p->right = NULL;
    if(root->root == NULL)
        root->root = p;
    else
    {
        BTNodeptr temp;
        temp = root->root;
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

int temp,num,i,j,k;
int main()
{
    Tnode root;
    root.root = NULL;
    scanf("%d",&num);
    while(num--)
    {
        scanf("%d",&temp);
        insert(&root,temp);
    }
    tprintf(root.root,1);
    return 0;
}

