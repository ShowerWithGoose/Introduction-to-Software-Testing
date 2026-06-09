#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int n;
    int height;
    struct node *left;
    struct node *right;
}bst;

bst *root,*root,*i;

void insert(int item)
{
    bst* q;
    root=(bst*)malloc(sizeof(bst));
    root->n=item;
    root->left=NULL;
    root->right=NULL;
    root->height=1;
    if(root==NULL)
    {
        root=root;
        return;
    }
    else
    {
        q=root;
        while(1)
        {
            root->height++;
            if(item<q->n)
            {
                
                if(q->left!=NULL) 
                {
                    q=q->left;
                }
                else
                {
                    q->left=root;
                    return;
                }
            }
            else if(item>=q->n)
            {
                if(q->right!=NULL) 
                {
                    q=q->right;
                }
                else
                {
                    q->right=root;
                    return;
                }
            }
        }
    }
    
}

void visit(bst* r)
{
    bst* q;
    q=r;
    if(q==NULL) return;
    visit(q->left);
    if(q->left==NULL&&q->right==NULL)
    {
        printf("%d %d\n",q->n,q->height);
    }
    visit(q->right);
}


int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int num;
        scanf("%d",&num);
        insert(num);
    }
    visit(root);
    return 0;
}
