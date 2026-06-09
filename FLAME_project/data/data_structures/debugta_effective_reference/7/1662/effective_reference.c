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

bst *root,*p,*now;

void insert(int item)
{
    bst* q;
    p=(bst*)malloc(sizeof(bst));
    p->n=item;
    p->left=NULL;
    p->right=NULL;
    p->height=1;
    if(root==NULL)
    {
        root=p;
        return;
    }
    else
    {
        q=root;
        while(1)
        {
            p->height++;
            if(item<q->n)
            {
                
                if(q->left!=NULL) 
                {
                    q=q->left;
                }
                else
                {
                    q->left=p;
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
                    q->right=p;
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
        int temp;
        scanf("%d",&temp);
        insert(temp);
    }
    visit(root);
    return 0;
}
