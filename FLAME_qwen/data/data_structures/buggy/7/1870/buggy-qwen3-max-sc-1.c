#include <stdio.h>
#include <stdlib.h>
struct  node 
{
    int   data;
    struct  node   *left,  *right;
};
typedef struct node  BTNode;
typedef struct node  *BTNodeptr;
int depth; // @@ [Global variable 'depth' is not properly tracking the actual depth of each node during insertion or traversal. It is modified during preorder traversal but not initialized to 1 at the start, and it doesn't reflect per-node depth.]

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
            printf("%d %d\n",T->data,depth); // @@ [Printing global 'depth' which does not represent the actual depth of the current leaf node. The depth should be stored in the node during insertion or passed correctly during traversal.]
        }
        
        depth++; // @@ [Incrementing global 'depth' before traversing children, but this approach fails because recursive calls interfere with shared global state, leading to incorrect depth values for different branches.]
        preorder(T->left);
        preorder(T->right);
        depth--; // @@ [Decrementing global 'depth' after traversal, but due to shared state across recursive calls, this does not correctly track depth per path from root to leaf.]
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
    depth = 1; // @@ [Missing initialization of 'depth' to 1 before calling preorder. Without this, 'depth' starts at 0 (or undefined if not zero-initialized), causing wrong height output. However, even with initialization, using a global variable for depth in recursive traversal is fundamentally flawed.]
    preorder(root);
    return 0;
}