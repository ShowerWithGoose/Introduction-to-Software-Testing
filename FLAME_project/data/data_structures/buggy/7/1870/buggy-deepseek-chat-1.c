#include <stdio.h>
#include <stdlib.h>
struct  node 
{
    int   data;
    struct  node   *left,  *right;
};
typedef struct node  BTNode;
typedef struct node  *BTNodeptr;
int depth;

BTNodeptr createTree(BTNodeptr T,int a)
{
    BTNodeptr p;
    if(T==NULL)
    {
        T=(BTNodeptr)malloc(sizeof(BTNode));
        T->data=a;
        T->left=T->right=NULL;
    }
    else if(a<T->data)
    {
        T->left=createTree(T->left,a);
    }
    else if(a>=T->data)
    {
        T->right=createTree(T->right,a);
    }
    
    return T;
}

void preorder(BTNodeptr T)
{
    if(T==NULL)
    return;
    else
    {
        if(T->left==NULL&&T->right==NULL)
        {
            printf("%d %d\n",T->data,depth); // @@ The depth variable is not initialized for the root node; it should start at 1, but here it is used without being set, leading to incorrect output (e.g., 0 instead of 1).
        }
        
        depth++; // @@ The depth is incremented before traversing children, but the root's depth is never set to 1 initially, causing all depths to be off by one.
        preorder(T->left);
        preorder(T->right);
        depth--;
    }
}

int main()
{
    int n,a;
    scanf("%d",&n);
    BTNodeptr root=NULL;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a);
        root=createTree(root,a);
    }
    preorder(root);
    return 0;
}