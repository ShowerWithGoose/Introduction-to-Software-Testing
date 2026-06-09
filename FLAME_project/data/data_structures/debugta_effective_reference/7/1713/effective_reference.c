#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

struct node
{
    int item;
    int height;
    struct node* left;
    struct node* right;
};

typedef struct node* BTNodeptr;
typedef struct node BTNode;

BTNodeptr root = NULL;

void insertBST(int item)
{
    BTNodeptr p,q;
    p = (BTNodeptr) malloc (sizeof(BTNode));
    p->item = item;
    p->height = 1;
    p->left = NULL;
    p->right = NULL;
    if ( root == NULL ) root = p;
    else
    {
        q=root;
        while(1)
        {
            if(item < q->item)
            {
                if(q->left == NULL)
                {
                    p->height++;
                    q->left=p;
                    break;
                }
                else {p->height++; q=q->left;}
            }
            else if(item >= q->item)
            {
                if(q->right == NULL)
                {
                    p->height++;
                    q->right=p;
                    break;
                }
                else {p->height++; q=q->right;}
            }
        }
    }
}

void preorder(BTNodeptr t)
{
    if(t!=NULL)
    {
		if(t->left==NULL&&t->right==NULL)
        {
            printf("%d %d\n",t->item,t->height);
        } 
		preorder(t->left);
        preorder(t->right);
    }
}

void destoryTree(BTNodeptr p)
{
    if(p!=NULL)
    {
        destoryTree(p->left);
        destoryTree(p->right);
        free(p);
        p=NULL;
    }
}

int main()
{
    int n,i;
    int item;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&item);
        insertBST(item);
    }
    preorder(root);
    destoryTree(root); 
}
