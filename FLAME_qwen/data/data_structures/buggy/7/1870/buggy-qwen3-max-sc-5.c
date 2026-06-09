#include <stdio.h>
#include <stdlib.h>
struct  node 
{
    int   data;
    struct  node   *left,  *right;
};
typedef struct node  BTNode;
typedef struct node  *BTNodeptr;
int depth; // @@ [The global variable 'depth' is not correctly tracking the height of each node during tree construction or traversal. Height should be stored per node or passed as a parameter during traversal, not managed via a global variable that gets modified in preorder traversal.]

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
            printf("%d %d\n",T->data,depth); // @@ [Using global 'depth' here is incorrect because 'depth' does not represent the actual height of the current node. The height of a node is the number of edges from the root to that node plus one, but 'depth' is being incremented/decremented during traversal and doesn't reflect per-node height.]
        }
        
        depth++; // @@ [Incrementing 'depth' after checking for leaf nodes leads to incorrect depth values for children. Also, this approach fails to assign correct heights during tree building.]
        preorder(T->left);
        preorder(T->right);
        depth--; // @@ [This decrement assumes symmetric traversal behavior, but it doesn't correctly maintain node-specific height information.]
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
    depth = 1; // @@ [Missing initialization of 'depth' to 1 before traversal. Without this, 'depth' starts at 0 (global default), leading to off-by-one errors in height reporting. However, even with initialization, the global depth approach is fundamentally flawed.]
    preorder(root);
    return 0;
}