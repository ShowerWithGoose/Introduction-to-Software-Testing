#include <stdio.h>
#include <stdlib.h>
struct  node 
{
    int   data;
    struct  node   *left,  *right;
};
typedef struct node  BTNode;
typedef struct node  *BTNodeptr;
int depth; // @@ [Global variable 'depth' is not correctly tracking node depth during tree construction or traversal; it's modified during traversal but not initialized per node, leading to incorrect height values for leaf nodes.]

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
            printf("%d %d\n",T->data,depth); // @@ [Using global 'depth' which does not represent the actual depth of the current node; depth should be passed as a parameter or stored in the node during insertion.]
        }
        
        depth++; // @@ [Modifying global 'depth' during traversal leads to incorrect depth values because recursive calls interfere with each other's depth tracking.]
        preorder(T->left);
        preorder(T->right);
        depth--; // @@ [This backtracking of global 'depth' is error-prone and fails to correctly reflect node depth in all cases, especially in complex trees.]
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