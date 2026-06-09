#include <stdio.h>
#include <stdlib.h>
struct  node 
{
    int   data;
    struct  node   *left,  *right;
};
typedef struct node  BTNode;
typedef struct node  *BTNodeptr;
int depth; // @@ [The 'depth' variable is global and shared across recursive calls, but it's modified during traversal without being correctly set per node. Leaf nodes print the current global 'depth', which does not represent their actual height in the tree.]

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
            printf("%d %d\n",T->data,depth); // @@ [Printing global 'depth' here is incorrect because 'depth' tracks traversal state, not the actual height of the current node. Height should be computed during insertion or passed as a parameter during traversal.]
        }
        
        depth++; // @@ [Incrementing global 'depth' before recursing left affects the depth value used for all subsequent nodes, leading to incorrect height values for leaf nodes.]
        preorder(T->left);
        preorder(T->right);
        depth--; // @@ [Decrementing after recursion assumes symmetric traversal, but due to early returns and shared global state, this does not correctly track per-node depth.]
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