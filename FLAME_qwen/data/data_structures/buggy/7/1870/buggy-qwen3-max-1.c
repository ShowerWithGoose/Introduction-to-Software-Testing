#include <stdio.h>
#include <stdlib.h>
struct  node 
{
    int   data;
    struct  node   *left,  *right;
};
typedef struct node  BTNode;
typedef struct node  *BTNodeptr;
int depth; // @@ [The global variable 'depth' is not properly initialized or updated during tree construction; it is modified during traversal but does not reflect the actual depth of each node in the tree.]

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
            printf("%d %d\n",T->data,depth); // @@ [The 'depth' printed here is a global variable that tracks traversal depth via increment/decrement, but it starts at 0 (uninitialized), and more critically, the root's depth should be 1. Since 'depth' is never set to 1 before traversal, all leaf depths will be off by one (too low).]
        }
        
        depth++; // @@ [Incrementing 'depth' after checking for leaf causes children to have correct depth during their visit, but the root is processed at depth=0 (initial value), so its children are at depth=1, etc. This makes leaf heights one less than required (root height should be 1).]
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
    preorder(root); // @@ [The global 'depth' variable is used uninitialized (default 0), and the traversal logic does not assign correct node depths during tree construction. The problem requires each node to know its own height (with root = 1), but this code tries to track depth globally during traversal, leading to incorrect height values for leaves.]
    return 0;
}