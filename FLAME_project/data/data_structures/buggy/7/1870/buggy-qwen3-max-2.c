#include <stdio.h>
#include <stdlib.h>
struct  node 
{
    int   data;
    struct  node   *left,  *right;
};
typedef struct node  BTNode;
typedef struct node  *BTNodeptr;
int depth; // @@ [Global variable 'depth' is uninitialized and incorrectly used to track node height during traversal; it should be stored per node during tree construction.]

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
            printf("%d %d\n",T->data,depth); // @@ [Using global 'depth' which does not represent the actual height of the current node; height should be stored in each node during insertion.]
        }
        
        depth++; // @@ [Modifying global 'depth' during traversal leads to incorrect height tracking because recursive calls interfere with each other's depth values.]
        preorder(T->left);
        preorder(T->right);
        depth--; // @@ [This decrement assumes a strict DFS stack behavior, but due to shared global state, it fails when multiple branches exist or in single-node cases.]
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
    depth = 1; // @@ [Missing initialization of 'depth' before traversal; even if added here, the approach is flawed because height must be per-node, not global.]
    preorder(root);
    return 0;
}