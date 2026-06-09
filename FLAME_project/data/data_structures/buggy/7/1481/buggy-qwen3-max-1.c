#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define max(a,b) (a>b?a:b)
typedef struct tree
{
    int data;
    struct tree *left,*right;
}tree;
tree* insert(tree *p,int item);
void perorder(tree *t);
int length=1;
int main()
{
    int n;
    scanf("%d",&n);
    tree *root=NULL;
    for(int i=0;i<n;i++)
    {
        int item;
        scanf("%d",&item);
        root=insert(root,item);
    }
    perorder(root);
    return 0;
}
tree* insert(tree *p,int item)
{
    if(p==NULL)
    {
        p=(tree*)malloc(sizeof(tree));
        p->data=item;
        p->left=NULL;
        p->right=NULL;
    }
    else if(item<p->data)
    {
        p->left=insert(p->left,item);
    }
    else if(item>=p->data)
    {
        p->right=insert(p->right,item);
    }
} // @@ [The function does not return p in all control paths; missing 'return p;' at the end, causing undefined behavior]
void perorder(tree *t)
{
    if(t!=NULL)
    {
        if(t->left==NULL&&t->right==NULL)
        {
            printf("%d %d\n",t->data,length);
        }
        length++;
        perorder(t->left);
        perorder(t->right);
        length--;
    }
} // @@ [The global variable 'length' is used to track depth, but it's modified during traversal in a way that doesn't correctly represent the current node's height; preorder traversal increments before visiting children, so leaf nodes print an incorrect height]