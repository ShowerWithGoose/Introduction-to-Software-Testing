#include <stdio.h>
#include <stdlib.h>
struct  node 
{
    int   data;
    struct  node   *left,  *right;
};
typedef struct node  BTNode;
typedef struct node  *BTNodeptr;
int depth; // @@ [The 'depth' variable is global and shared across recursive calls, leading to incorrect height calculation for leaf nodes. Height should be tracked per node during insertion or traversal, not via a single global counter.]

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
            printf("%d %d\n",T->data,depth); // @@ [Using the global 'depth' here gives incorrect height because it reflects the current traversal depth, not the actual height of the node in the tree. The height of a node should be stored when the node is created or computed based on its position from the root.]
        }
        
        depth++; // @@ [Modifying a global 'depth' during traversal corrupts the depth value for sibling and parent nodes due to shared state across recursive calls.]
        preorder(T->left);
        preorder(T->right);
        depth--; // @@ [This decrement assumes perfect backtracking, but any early return or unbalanced structure may leave 'depth' inconsistent. More fundamentally, height should not rely on a global variable.]
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